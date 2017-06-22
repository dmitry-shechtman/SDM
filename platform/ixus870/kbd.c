#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"

typedef struct {
	short grp;
	short hackkey;
	long canonkey;
} KeyMap;

typedef struct 
{
	short fun;      //1 = permanent, 2 = toggle
	short hackkey;
	long canonkey0; 
	long canonkey1;
	long canonkey2;
} SwitchMap;

static long switch_mod_state[3]; 
static SwitchMap switchmap[];    
static int switch_override = 0;  

// dial-mode mask for bits that change

#define SWITCH_MASK0 (0x00000000) 
#define SWITCH_MASK1 (0x30000000) 
#define SWITCH_MASK2 (0x00000000) 
static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];

static long last_kbd_key = 0;
static long alt_mode_key_mask = 0x00000800; // key_print
static int usb_power=0;
static int remote_key, remote_count;
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);
extern char *imgbuf;         // edge outline buffer
static long menu_key_mask=0x00000400;
#define DELAY_TIMEOUT 10000

//each mask should be the xor of all key values in the corresponding group
#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x00000FFF)

#define NEW_SS (0x2000)

// from sub_FF846198 (via aSdProtect (just above it))
// LDR  R1, =dword_FFAD6F20     R1 = 0xFFAD6F20 = a
// MOV  R3, #1                  R3 = 1
// LDRB R2, [R1,#0x114]         R2 = a[0x114] = 0x51
// LDRB R1, [R1,#0x114]         R1 = a[0x114] = 0x51
// MOV  R2, R2,LSR#5            R2 = 0x51 >> 5 = 2 = SD_READONLY_REG
// LDR  R0, [R0,R2,LSL#2]       R0 = R0[2] = b[2]
// AND  R1, R1, #0x1F           R1 = 0x51 & 0x1F = 0x11
// AND  R0, R0, R3,LSL R1       R0 = b[2] & (1 << 0x11)
// MOV  R0, R0,LSR R1           R0 = (b[2] & (1 << 0x11)) >> 0x11
// AND  R0, R0, #1              R0 = ((b[2] & (1 << 0x11)) >> 0x11) & 0x1
// BX   LR                      return
#define SD_READONLY_FLAG (0x20000)  // 1 << 0x11
#define SD_READONLY_REG 2 

#define USB_MASK (0x40000)
#define USB_IDX 2               // idx in physw_status


#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif


static KeyMap keymap[] = {
	/* tiny bug: key order matters. see kbd_get_pressed_key()
	 * for example
         * KEY_SHOOT_FULL and KEY_SHOOT_HALF overlap and the first has precedence
	 */

        // (note: key is in group i if it changes a bit in physw_status[i])
        // group, CHDK key      , mask
	{ 2, KEY_SHOOT_FULL	, 0x00000003 },
      { 2, KEY_SHOOT_FULL_ONLY, 0x00000002 }, 
	{ 2, KEY_SHOOT_HALF	, 0x00000001 },
	{ 2, KEY_UP		      , 0x00000080 },
	{ 2, KEY_DOWN		, 0x00000040 },
	{ 2, KEY_LEFT		, 0x00000010 },
	{ 2, KEY_RIGHT		, 0x00000020 },
	{ 2, KEY_SET		, 0x00000100 },
	{ 2, KEY_ZOOM_IN	      , 0x00000004 },
	{ 2, KEY_ZOOM_OUT	      , 0x00000008 },
	{ 2, KEY_MENU		, 0x00000400 },
	{ 2, KEY_DISPLAY	      , 0x00000200 },
	{ 2, KEY_PRINT	 	, 0x00000800 },
       	{ 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f() ;

#include "../generic/wurb2.c"

static void __attribute__((noinline)) mykbd_task_proceed()
 	{
 	  int i;
 	        while (physw_run)
               {
 	          _SleepTask(10);
 	               
	          if (wrap_kbd_p1_f() == 1)
                  { // autorepeat ?
 	             _kbd_p2_f();
 	            }
 	        }
 	}

void __attribute__((naked,noinline)) mykbd_task()
{
    /*WARNING
     * Stack pointer manipulation performed here!
     * This means (but not limited to):
     *	function arguments destroyed;
     *	function CAN NOT return properly;
     *	MUST NOT call or use stack variables before stack
     *	is setup properly;
     *
     */

	register int i;
	register long *newstack;

#ifndef MALLOCD_STACK
	newstack = (void*)kbd_stack;
#else
	newstack = malloc(NEW_SS);
#endif

	for (i=0;i<NEW_SS/4;i++)
		newstack[i]=0xdededede;

	asm volatile (
		"MOV	SP, %0"
		:: "r"(((char*)newstack)+NEW_SS)
		: "memory"
	);

	mykbd_task_proceed();

	/*function can be modified to restore SP here...
	 */

	_ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
        //first three lines from kbd_p1_f plus a jump to the fourth
	asm volatile(
		"STMFD   SP!, {R1-R5,LR}\n"
		"MOV     R4, #0\n"
		"BL      my_kbd_read_keys\n"
		"B       _kbd_p1_f_cont\n"
	);
	return 0; //shut up the compiler
}

volatile int jogdial_stopped=0;

void my_kbd_read_keys()
{
	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];
	
	_platformsub_kbd_fetch_data(kbd_new_state);

	      checkKeyPress();

      if (kbd_process() == 0){
		//leave it alone...
          physw_status[0] = kbd_new_state[0];
          physw_status[1] = kbd_new_state[1];
          physw_status[2] = kbd_new_state[2];
          physw_status[2] |= alt_mode_key_mask;
          if(imgbuf)physw_status[2]  = physw_status[2] | menu_key_mask ;
          jogdial_stopped=0;

	} else {
		// override keys

platform_kbd_hook();
 	physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) |
			  (kbd_mod_state[0] & KEYS_MASK0);

	physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) |
			  (kbd_mod_state[1] & KEYS_MASK1);

	physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) |
			  (kbd_mod_state[2] & KEYS_MASK2);

           if (switch_override == 1) 
           { 
            physw_status[1] = (physw_status[1] & (~SWITCH_MASK1)) | (switch_mod_state[1] & SWITCH_MASK1); // force movie mode
           }

	if ((jogdial_stopped==0) && !state_kbd_script_run){ jogdial_stopped=1; get_jogdial_direction(); }
	else if (jogdial_stopped && state_kbd_script_run) jogdial_stopped=0; 

	}
	
	_kbd_read_keys_r2(physw_status);

	remote_key = (physw_status[USB_IDX] & USB_MASK)==USB_MASK;
		if (remote_key) 
			remote_count += 1;
		else if (remote_count) {
			usb_power = remote_count;
			remote_count = 0;
		}
	if (conf.remote_enable) {
		physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);
	} else {
		physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
	}

}



void kbd_set_alt_mode_key_mask(long key)
{
	int i;
	for (i=0; keymap[i].hackkey; ++i) {
		if (keymap[i].hackkey == key) {
			alt_mode_key_mask = keymap[i].canonkey;
			return;
		}
	}
}


void kbd_key_press(long key)
{
	int i;
   if(key<30 || key>34)                                              // normal key
  {
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
			return;
		}
	}
  }
 else if ((key >29) && (key<35))                                        // dialmode-switch
  { 
        if (key == 34)                                      // playback mode
        {            
         switch_override = 2;
        } else 
        {
            switch_override = 1;
        }

    for (i=0; switchmap[i].hackkey; i++)
      {
       if (switchmap[i].hackkey == key)                     // find override key in table
          {
            switch_mod_state[0] |= switchmap[i].canonkey0;  // and get bit patterns to switch_mod_state[]
            switch_mod_state[1] |= switchmap[i].canonkey1;
            switch_mod_state[2] |= switchmap[i].canonkey2;
            return;
          }
       }
   }
}

void kbd_key_release(long key)
{
	int i;
 if (key < 30 || key>34) // normal key
  { 
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
			return;
		}
	}
}

  else if ((key >29) && (key<35))                                        // dialmode-switch
   { 
     switch_override = 0;
     for (i=0; switchmap[i].hackkey; i++)                    // find override key in table
        {
         if (switchmap[i].hackkey == key)
           {
             switch_mod_state[0] &= ~switchmap[i].canonkey0; // add inverse bit-pattern to switch_mod_state[]
             switch_mod_state[1] &= ~switchmap[i].canonkey1;
             switch_mod_state[2] &= ~switchmap[i].canonkey2;
             return;
           }
         }
    }

}

void kbd_key_release_all()
{
	kbd_mod_state[0] |= KEYS_MASK0;
	kbd_mod_state[1] |= KEYS_MASK1;
	kbd_mod_state[2] |= KEYS_MASK2;
      switch_override = 0;  // disable dialmode-override
}

long kbd_is_key_pressed(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			return ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
		}
	}
	return 0;
}

long kbd_is_key_clicked(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			return ((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
			       ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0);
		}
	}
	return 0;
}

long kbd_get_pressed_key()
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0){
			return keymap[i].hackkey;
		}
	}
	return 0;
}

long kbd_get_clicked_key()
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
		    ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)) {
			return keymap[i].hackkey;
		}
	}
	return 0;
}


void kbd_reset_autoclicked_key() {
	last_kbd_key = 0;
}

long kbd_get_autoclicked_key() {
	static long last_kbd_time = 0, press_count = 0;
	register long key, t;
	
	key=kbd_get_clicked_key();
	if (key) {
		last_kbd_key = key;
		press_count = 0;
		last_kbd_time = get_tick_count();
		return key;
	} else {
		if (last_kbd_key && kbd_is_key_pressed(last_kbd_key)) {
			t = get_tick_count();
			if (t-last_kbd_time>((press_count)?175:500)) {
				++press_count;
				last_kbd_time = t;
				return last_kbd_key;
			} else {
				return 0;
			}
		} else {
			last_kbd_key = 0;
			return 0;
		}
	}
}


int get_usb_power(int edge)
{
	int x;

	if (edge) return remote_key;
	x = usb_power;
	usb_power = 0;
	return x;
}

static SwitchMap switchmap[] = 
 {
        { 1, MOVIE_MODE, 0x00000000, 0x20000000, 0x00000000 },    
	  { 0, 0, 0, 0, 0 }
 };


long kbd_use_zoom_as_mf() {
 return 0;
}

static int new_jogdial=0, old_jogdial=0;

int Get_JogDial(void){
 //address from sub above aJogdail (sub_FF84B8D8)
 return (*(int*)0xC0240104)>>16;
}

long get_jogdial_direction(void) {
 //XXX this seems to have a overflow bug: old=MIN_INT, new = old-1 = MAX_INT  ->  old-1 < old < new = old - 1
 //not likely to happen though (very long runs with a bias for tuning one direction; bias is probably to the right due to menus)
 old_jogdial=new_jogdial;
 new_jogdial=Get_JogDial();
 if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT; 
 else if (old_jogdial>new_jogdial) return JOGDIAL_LEFT;
 else return 0;
}

long is_key_pressed_now(long key)
{
 int i;
 long kbd_tmp_state[3];
 _platformsub_kbd_fetch_data(kbd_tmp_state);
 for (i=0;keymap[i].hackkey;i++)
  {
   if (keymap[i].hackkey == key)
    {
     return ((kbd_tmp_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
    }
  }
 return 0;
}



