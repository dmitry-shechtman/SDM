#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
extern void _GetKbdState(long* buffer);
extern void _GetKbdState2(long* buffer);

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
/* info from Mike Bittner  */
#define SWITCH_MASK0 (0x000001e0) 
#define SWITCH_MASK1 (0x00000000) 
#define SWITCH_MASK2 (0x08000C00) 
static long menu_key_mask=0x00040000;
static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];
static KeyMap keymap[];
static long last_kbd_key = 0;
static long alt_mode_key_mask = 0x00000200;  
static long alt_mode_key_reg  = 1;     
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;

volatile int jogdial_stopped=0;

#define DELAY_TIMEOUT 10000

#define KEYS_MASK0 (0x00000003)
#define KEYS_MASK1 (0x000FFE18)
#define KEYS_MASK2 (0x00000000) 

static KeyMap keymap[] = {
    { 0, KEY_SHOOT_FULL      , 0x00000003 }, // Found @0xffb0f7c0, levent 0x01
    { 0, KEY_SHOOT_FULL_ONLY , 0x00000002 }, // http://chdk.setepontos.com/index.php?topic=1444.msg70223#msg70223
    { 0, KEY_SHOOT_HALF      , 0x00000001 }, // Found @0xffb0f7b4, levent 0x00
    { 1, KEY_ZOOM_OUT        , 0x00000008 }, // Found @0xffb0f82c, levent 0x03
    { 1, KEY_ZOOM_IN         , 0x00000010 }, // Found @0xffb0f838, levent 0x02
    { 1, KEY_PRINT           , 0x00000200 }, //
    { 1, KEY_LEFT            , 0x00000400 }, // Found @0xffb0f880, levent 0x06
    { 1, KEY_SET             , 0x00000800 }, // Found @0xffb0f88c, levent 0x08
    { 1, KEY_RIGHT           , 0x00001000 }, // Found @0xffb0f898, levent 0x07
    { 1, KEY_DOWN            , 0x00002000 }, // Found @0xffb0f8a4, levent 0x05
    { 1, KEY_UP              , 0x00004000 }, // Found @0xffb0f8b0, levent 0x04
    { 1, KEY_METERING        , 0x00008000 }, //
    { 1, KEY_ERASE           , 0x00010000 }, //
    { 1, KEY_DISPLAY         , 0x00020000 }, // Found @0xffb0f8d4, levent 0x0a
    { 1, KEY_MENU            , 0x00040000 }, // Found @0xffb0f8e0, levent 0x09
    { 1, KEY_AE_LOCK         , 0x00080000 }, //
	{ 0, 0, 0 }
};

#define NEW_SS (0x2000*2)
#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX     2         
#define USB_MASK            0x00040000  // Found @0xffb0f94c, levent 0x902
#define USB_IDX             2    
#define HOTSHOE_FLAG        0x10000000  // Found @0xffb0f7f8, levent 0x904
#define HOTSHOE_IDX         0

void kbd_fetch_data(long*);

long __attribute__((naked)) wrap_kbd_p1_f() ;

// #include "../generic/wurb2.c"
static void __attribute__((noinline)) mykbd_task_proceed()
{
	/* Initialize our own kbd_new_state[] array with the
	   current physical status. If we dont do this here,
	   the G11 will immediate switch off at the first call
       of _GetKbdState1/2 with a (uninitialized) array.
	   */
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

void __attribute__((naked,noinline))
mykbd_task(long ua, long ub, long uc, long ud, long ue, long uf)
{
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
//				"BL _kbd_p1_sub\n"
                "BL      my_kbd_read_keys\n"
               	"B	 _kbd_p1_f_cont\n"	

    );
 return 0; // shut up the compiler
}

void my_kbd_read_keys()
{ 
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2];

	/* ERR99: With this call, we got the state of the buttons on the
	   top of the G11. Like On/off, shoot, zoom, etc.
	   But none of the backside buttons, like cursor, menu, display,etc...*/
	_GetKbdState(kbd_new_state); //kbd_new_state FF849300

	/* With this we got also the rest of the buttons, so menu is working ;) */
	_kbd_read_keys_r2(kbd_new_state);

	      checkKeyPress();

      if (kbd_process() == 0){
	// leave it alone...
	physw_status[0] = kbd_new_state[0];
	physw_status[1] = kbd_new_state[1];
	physw_status[2] = kbd_new_state[2];
	//physw_status[0] |= alt_mode_key_mask;
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

       if(imgbuf)physw_status[1]  = physw_status[1] | menu_key_mask ;                                   // disable menu key

       if (switch_override == 1) 
       { 
        physw_status[0] = (physw_status[0] & (~SWITCH_MASK0)) | (switch_mod_state[0] & SWITCH_MASK0); // force movie mode
        physw_status[2] = (physw_status[2] & (~SWITCH_MASK2)) | (switch_mod_state[2] & SWITCH_MASK2);
       }

		if ((jogdial_stopped==0) && !state_kbd_script_run)
			{ jogdial_stopped=1; get_jogdial_direction(); }
		else if (jogdial_stopped && state_kbd_script_run)
			 jogdial_stopped=0; 

    }


    remote_key = (physw_status[2] & USB_MASK)==USB_MASK;
      if (remote_key)  	  remote_count += 1;
      else if (remote_count) {
         usb_power = remote_count;
         remote_count = 0;
      }

    if (conf.remote_enable) {
      physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);
     }
    else 	physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;

}


int get_usb_power(int edge)
{
	int x;

	if (edge) return remote_key;
	x = usb_power;
	usb_power = 0;
	return x;
}

void kbd_set_alt_mode_key_mask(long key)
{
    int i;
    for (i=0; keymap[i].hackkey; ++i) {
	if (keymap[i].hackkey == key) {
	    alt_mode_key_mask = keymap[i].canonkey;
	    alt_mode_key_reg  = keymap[i].grp;
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
	    ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)){
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
        { 1, MOVIE_MODE, 0x00000120, 0x00000000, 0x00000000 },
	  { 0, 0, 0, 0, 0 }
 };



long kbd_use_zoom_as_mf() 
{
 return 0;
}

long is_key_pressed_now(long key)
{
 int i;
 long kbd_tmp_state[3];
 _GetKbdState(kbd_tmp_state);
 _kbd_read_keys_r2(kbd_tmp_state);
 for (i=0;keymap[i].hackkey;i++)
  {
   if (keymap[i].hackkey == key)
    {
     return ((kbd_tmp_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
    }
  }
 return 0;
}

static int new_jogdial=0, old_jogdial=0;

/* Baseadr 0xC0240000 @FF860940
   Offset 104 @FF860948 in Jogdial.c
*/
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

#include "../generic/wurb2.c"
/*
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
*/

