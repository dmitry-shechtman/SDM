#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"

typedef struct {
    short grp;
    short hackkey;
    long canonkey;
} KeyMap;

static long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static KeyMap keymap[];
static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
static long alt_mode_key_mask = 0x00010800; // disp + set
static int alt_mode_led=0;
extern void _GetKbdState(long*);

#define DELAY_TIMEOUT 10000

// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
//#define KEYS_MASK0 (0x0007FC0F)     // physw_status[0] was 7FC05
#define KEYS_MASK0 (0x000FFC0F)     // physw_status[0] was 7FC05
#define KEYS_MASK1 (0x00200000)
#define KEYS_MASK2 (0x00002182)  

#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX     2         
#define USB_MASK (0x4000000)
#define USB_FLAG            0x04000000 // Found @0xff3bcf44, levent 0x902
#define USB_IDX 2
#define USB_IDX             2 

#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif

static KeyMap keymap[] = {

    /* tiny bug: key order matters. see kbd_get_pressed_key()
    * for example*/

    { 0, KEY_ZOOM_OUT        , 0x00000003 }, // fast out
    { 0, KEY_ZOOM_OUT_SLOW   , 0x00000001 }, // slow out
    { 0, KEY_ZOOM_OUT        , 0x00000002 }, //
    { 0, KEY_ZOOM_IN         , 0x0000000C }, //
    { 0, KEY_ZOOM_IN_SLOW    , 0x00000004 }, // slow in
    { 0, KEY_ZOOM_IN         , 0x00000008 }, // fast in
    { 0, KEY_DISPLAY         , 0x00000800 },
    { 0, KEY_UP              , 0x00001000 },
    { 0, KEY_RIGHT           , 0x00006000 },
    { 0, KEY_SET             , 0x00010000 },
    { 0, KEY_DOWN            , 0x00020000 },
    { 0, KEY_MENU            , 0x00040000 },
    { 0, KEY_VIDEO           , 0x00080000 },
    { 1, KEY_PLAYBACK        , 0x00200000 },
    { 2, KEY_LEFT            , 0x00000100 },
    { 2, KEY_SHOOT_FULL      , 0x00002002 },
    { 2, KEY_SHOOT_FULL_ONLY , 0x00000002 },
    { 2, KEY_SHOOT_HALF      , 0x00002000 },
    { 0, 0, 0 }
};


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
void my_blinkk(void) {
	int i;
	while(1) {
		*((volatile int *) 0xC0220130) = 0x46; // Turn on LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

		*((volatile int *) 0xC0220130) = 0x44; // Turn off LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

		*((volatile int *) 0xC0220130) = 0x46; // Turn on LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

		*((volatile int *) 0xC0220130) = 0x44; // Turn off LED
		for (i=0; i<0x900000; i++) { asm volatile ( "nop\n" ); }
	}
}

volatile int jogdial_stopped=0;

extern long __attribute__((naked)) wrap_kbd_p1_f();


static void __attribute__((noinline)) mykbd_task_proceed() {
	
	while (physw_run) {
        _SleepTask(*((int*)(0x1c44 +0x8))); //  @FF0248AC

		if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
        	_kbd_p2_f();
        }
    }
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline)) mykbd_task() {
	mykbd_task_proceed(); 

// function can be modified to restore SP here...
	_ExitTask();
}

/*
// copied from g12 and sx30, thx to philmoz
// Pointer to stack location where jogdial task records previous and current
// jogdial positions

extern short* jog_position;


void jogdial_control(int n)
{
    if (jogdial_stopped && !n)
    {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = (*(short*)0xC0240106);  // Rear dial
    }
    jogdial_stopped = n;
}
*/
// like SX110
void my_kbd_read_keys() {
		

    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2]; 

	_GetKbdState( kbd_new_state );
	_kbd_read_keys_r2( kbd_new_state);
	
//    kbd_new_state[0] = physw_status[0];  //sx220 changed from physw_status[0]
 //   kbd_new_state[2] = physw_status[2];
 //   kbd_new_state[3] = physw_status[3]; //sx220 added
	

	
          checkKeyPress();

      if (kbd_process() == 0) {
        // we read keyboard state with _kbd_read_keys()
		physw_status[0] = kbd_new_state[0];
		physw_status[1] = kbd_new_state[1];
		physw_status[2] = kbd_new_state[2];		
		// jogdial_control(0);
    } else {
        // override keys

platform_kbd_hook();
        physw_status[0] = (kbd_new_state[0] | KEYS_MASK0) & (~KEYS_MASK0 | kbd_mod_state[0]); 
        physw_status[1] = (kbd_new_state[1] | KEYS_MASK1) & (~KEYS_MASK1 | kbd_mod_state[1]); 
        physw_status[2] = (kbd_new_state[2] | KEYS_MASK2) & (~KEYS_MASK2 | kbd_mod_state[2]);
/*
        if ((jogdial_stopped==0) && !state_kbd_script_run) {
            jogdial_control(1);
            get_jogdial_direction();
        }
        else if (jogdial_stopped && state_kbd_script_run)
            jogdial_control(0);
*/
    }

    remote_key = (physw_status[2] & USB_MASK)==USB_MASK; 
    if (remote_key)
        remote_count += 1;
    else if (remote_count) {
        usb_power = remote_count;
        remote_count = 0;
    }
	
    if (conf.remote_enable) {
        physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);   // override USB and SD-Card Readonly Bits
    }																		  //SX220 DONE.
   
    physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;   // override SD-Card Readonly Bit
}

int get_usb_power(int edge) {

  int x;

    if (edge) return remote_key;
    x = usb_power;
    usb_power = 0;
    return x;
}

void kbd_key_press(long key) {
    
	int i;
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
            return;
        }
    }
}

void kbd_key_release(long key) {
 
   int i;
    for (i=0;keymap[i].hackkey;i++) {
        if (keymap[i].hackkey == key){
            kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
            return;
        }
    }
}

void kbd_key_release_all() {
    
	kbd_mod_state[0] |= KEYS_MASK0;
    kbd_mod_state[1] |= KEYS_MASK1;
    kbd_mod_state[2] |= KEYS_MASK2;
}

long kbd_is_key_pressed(long key) {
  
	int i;
    for (i=0;keymap[i].hackkey;i++) {
        if (keymap[i].hackkey == key) {
            return ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
        }
    }
    return 0;
}

long kbd_is_key_clicked(long key) {
    
	int i;
    for (i=0;keymap[i].hackkey;i++) {
        if (keymap[i].hackkey == key){
            return ((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
                ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0);
        }
    }
    return 0;
}

long kbd_get_pressed_key() {
    
	int i;
    for (i=0;keymap[i].hackkey;i++) {
        if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) {
            return keymap[i].hackkey;
        }
    }
    return 0;
}

long kbd_get_clicked_key() {

   int i;
    for (i=0;keymap[i].hackkey;i++) {
        if (((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) && ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)) {
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

long kbd_use_zoom_as_mf() 
{
 return 0;
}

#ifdef CAM_USE_ZOOM_FOR_MF
    long kbd_use_zoom_as_mf() {

        static long v;
        static long zoom_key_pressed = 0;

        if (kbd_is_key_pressed(KEY_ZOOM_IN) && (mode_get()&MODE_MASK) == MODE_REC) {
            get_property_case(PROPCASE_FOCUS_MODE, &v, 4);
            if (v) {
                kbd_key_release_all();
                kbd_key_press(KEY_RIGHT);
                zoom_key_pressed = KEY_ZOOM_IN;
               	return 1;
            }
        } else {
            if (zoom_key_pressed==KEY_ZOOM_IN) {
                kbd_key_release(KEY_RIGHT);
                zoom_key_pressed = 0;
                return 1;
            }
        }
        if (kbd_is_key_pressed(KEY_ZOOM_OUT) && (mode_get()&MODE_MASK) == MODE_REC) {
            get_property_case(PROPCASE_FOCUS_MODE, &v, 4);
            if (v) {
                kbd_key_release_all();
                kbd_key_press(KEY_LEFT);
                zoom_key_pressed = KEY_ZOOM_OUT;
                return 1;
            }
        } else {
            if (zoom_key_pressed==KEY_ZOOM_OUT) {
                kbd_key_release(KEY_LEFT);
                zoom_key_pressed = 0;
                return 1;
            }
        }
        return 0;
    }
#endif

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

#include "../generic/wurb2.c"


