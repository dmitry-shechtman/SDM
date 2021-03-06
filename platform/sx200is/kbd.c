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
#define SWITCH_MASK1 (0x0000000f) 
#define SWITCH_MASK2 (0x00000000) 
static long menu_key_mask=0x00000800;
long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF }; 
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF }; 
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF }; 

static long last_kbd_key = 0;
static long alt_mode_key_mask = 0x00004000; // key_print
static int alt_mode_led=0;
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);


#define DELAY_TIMEOUT 100000   // increased by 10x


#define KEYS_MASK0 (0x00000300)
#define KEYS_MASK1 (0x0000FFF0) // block slow zoom as well
#define KEYS_MASK2 (0x00000000)

#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)
#define USB_MASK (0x200000)
#define USB_IDX 2


#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif

static KeyMap keymap[] = 
{	
      { 0, KEY_SHOOT_FULL     , 0x00000300 },
      { 0, KEY_SHOOT_FULL_ONLY, 0x00000200 },
      { 0, KEY_SHOOT_HALF     , 0x00000100 },
	{ 1, KEY_ZOOM_OUT_SLOW	, 0x00000010 },
	{ 1, KEY_ZOOM_OUT 	, 0x00000020 },
	{ 1, KEY_ZOOM_IN_SLOW	, 0x00000040 },
	{ 1, KEY_ZOOM_IN   	, 0x00000080 },
	{ 1, KEY_UP		      , 0x00000100 },
	{ 1, KEY_LEFT		, 0x00000200 },
	{ 1, KEY_SET		, 0x00000400 },
	{ 1, KEY_MENU		, 0x00000800 },
	{ 1, KEY_DOWN		, 0x00001000 },
	{ 1, KEY_RIGHT		, 0x00002000 },
	{ 1, KEY_PRINT		, 0x00004000 },
	{ 1, KEY_DISPLAY	      , 0x00008000 },
     	{ 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f() ;

#include "../generic/wurb2.c"
static void __attribute__((noinline)) mykbd_task_proceed()
{
  kbd_new_state[0] = physw_status[0]; 
  kbd_new_state[1] = physw_status[1]; 
  kbd_new_state[2] = physw_status[2]; 
	while (physw_run){
		_SleepTask(10);
		
		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
}

void __attribute__((naked,noinline)) mykbd_task()
{
    /* WARNING
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

	/* function can be modified to restore SP here...
	 */

	_ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{

	asm volatile(
		"STMFD   SP!, {R1-R5,LR}\n"
		"MOV     R4, #0\n"
		"BL      my_kbd_read_keys\n"
		"B       _kbd_p1_f_cont\n"
	);
	return 0; // shut up the compiler
}

volatile int jogdial_stopped=0;

void my_kbd_read_keys()
{
	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];
	
	_platformsub_kbd_fetch_data(kbd_new_state);

	      checkKeyPress();

      if (kbd_process() == 0)
      {
		// leave it alone...
          physw_status[0] = kbd_new_state[0];
          physw_status[1] = kbd_new_state[1];
          physw_status[2] = kbd_new_state[2];
          physw_status[1] |= alt_mode_key_mask;           // ignore Print key
          jogdial_stopped=0;

	} 
     else 
     {

		// override keys

platform_kbd_hook();
 	 physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) | // sets all keys pressed
			  (kbd_mod_state[0] & KEYS_MASK0);          // only pressed keys low in final state

	 physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) |
			  (kbd_mod_state[1] & KEYS_MASK1);

	 physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) |
			  (kbd_mod_state[2] & KEYS_MASK2);
       if(imgbuf)physw_status[1]  = physw_status[1] | menu_key_mask ;                                   // disable menu key

       if (switch_override == 1) 
       { 
        physw_status[1] = (physw_status[1] & (~SWITCH_MASK1)) | (switch_mod_state[1] & SWITCH_MASK1); // force movie mode
       }

	 if ((jogdial_stopped==0) && !state_kbd_script_run){ jogdial_stopped=1; get_jogdial_direction(); }
	 else if (jogdial_stopped && state_kbd_script_run) jogdial_stopped=0; 


     }
	
	_kbd_read_keys_r2(physw_status);

	remote_key = (physw_status[2] & USB_MASK)==USB_MASK;
		if (remote_key) remote_count += 1;
		else 
            if (remote_count) 
            {
		 usb_power = remote_count;
		 remote_count = 0;
		}
	    if (conf.remote_enable) 
            {
		 physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);
	      } 
           else 
            {
		 physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
	      }

}



/****************/

void kbd_set_alt_mode_key_mask(long key)
{
	int i;
	for (i=0; keymap[i].hackkey; ++i) 
            {
		if (keymap[i].hackkey == key) 
                {
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

static SwitchMap switchmap[] = 
 {
        { 1, MOVIE_MODE, 0x00000000, 0x0000000a, 0x00000000 },
	  { 0, 0, 0, 0, 0 }
 };

int get_usb_power(int edge)
{
	int x;
	if (edge) return remote_key;
	x = usb_power;
	usb_power = 0;
	return x;
}

long kbd_use_zoom_as_mf() {
 return 0;
}

static int new_jogdial=0, old_jogdial=0;

int Get_JogDial(void){
 return (*(int*)0xC0240104)>>16;
}

long get_jogdial_direction(void) { 
 old_jogdial=new_jogdial;
 new_jogdial=Get_JogDial();
 if (old_jogdial<new_jogdial) return JOGDIAL_LEFT; 
 else if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT;
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


