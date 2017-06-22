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

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);

static long alt_mode_key_mask = 0x000C0000;	// disp + set

extern void _GetKbdState(long*);

#define DELAY_TIMEOUT 10000

#define KEYS_MASK0			(0x05000000|0x00800000)
#define KEYS_MASK1			(0x00000001|0x00000002|0x00000003|0x00001000|0x00002000|0x00004000|0x00008000|0x00010000|0x00020000|0x00040000|0x00080000)
#define KEYS_MASK2			(0x00000000)

#define NEW_SS				(0x2000)

#define SD_READONLY_FLAG	0x00020000 // Found @0xffb56264 (1.00B), levent 0x90a
#define SD_READONLY_IDX		2

#define USB_MASK			0x04000000 // Found @0xffb5628c (1.00B), levent 0x902
#define USB_IDX				2

#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif

extern void usb_remote_key( void ) ;


static KeyMap keymap[] = {
	
	/* tiny bug: key order matters. see kbd_get_pressed_key() */
 
      { 0, KEY_PLAYBACK        ,0x01000000 }, // Found @0xffb561dc, levent 0x601	
	{ 0, KEY_MENU            ,0x04000000 }, // Found @0xffb561e4 (1.00B), levent 0x09
	{ 0, KEY_FACE            ,0x00800000 },
	{ 1, KEY_UP              ,0x00001000 }, // Found @0xffb56214 (1.00B), levent 0x04
	{ 1, KEY_RIGHT           ,0x00002000 }, // Found @0xffb5621c (1.00B), levent 0x07
	{ 1, KEY_DOWN            ,0x00004000 }, // Found @0xffb56224 (1.00B), levent 0x05
	{ 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb5622c (1.00B), levent 0x06
	{ 1, KEY_ZOOM_OUT        ,0x00010000 }, // Found @0xffb56234 (1.00B), levent 0x03
	{ 1, KEY_ZOOM_IN         ,0x00020000 }, // Found @0xffb5623c (1.00B), levent 0x02
	{ 1, KEY_SET             ,0x00040000 }, // Found @0xffb56244 (1.00B), levent 0x08
	{ 1, KEY_DISPLAY         ,0x00080000 }, // Found @0xffb5624c (1.00B), levent 0x0a
	{ 1, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb5620c (1.00B), levent 0x01
	{ 1, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb5620c (1.00B), levent 0x01
	{ 1, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb56204 (1.00B), levent 0x00
//    { 0, KEY_POWER           ,0x02000000 }, // Found @0xffb561e4 (1.00D), levent 0x600
	{ 0, 0, 0 }
};

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	
	//FF8346D4
	asm volatile(
		"STMFD	SP!, {R1-R7,LR} \n"
		"MOV	R5, #0 \n"
		//"BL		_kbd_read_keys \n"
		"BL		my_kbd_read_keys \n"	// pached
		"B		_kbd_p1_f_cont \n"
	);
	
	return 0; // shut up the compiler
}

static void __attribute__((noinline)) mykbd_task_proceed() {
	
	while (physw_run) {
		_SleepTask(*((int*)(0x1C30+0x8)));//10);	// @FF834218 (1.00B)
		
		if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
			_kbd_p2_f();
		}
	}
}

void __attribute__((naked,noinline)) mykbd_task() {
	
	mykbd_task_proceed();

	_ExitTask();
}

void kbd_set_alt_mode_key_mask(long key) {
	
	int i;
	for (i=0; keymap[i].hackkey; ++i) {
		if (keymap[i].hackkey == key) {
			alt_mode_key_mask = keymap[i].canonkey;
			return;
		}
	}
}

void my_kbd_read_keys() {
	
	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];
	
	_GetKbdState(kbd_new_state);
	_kbd_read_keys_r2(kbd_new_state);
	checkKeyPress();
	
	if (kbd_process() == 0) {
		// we read keyboard state with _kbd_read_keys()
		physw_status[0] = kbd_new_state[0];
		physw_status[1] = kbd_new_state[1];
		physw_status[2] = kbd_new_state[2];
	} else {
		// override keys

platform_kbd_hook();
		physw_status[0] = (kbd_new_state[0] | KEYS_MASK0) & (~KEYS_MASK0 | kbd_mod_state[0]); 
		physw_status[1] = (kbd_new_state[1] | KEYS_MASK1) & (~KEYS_MASK1 | kbd_mod_state[1]); 
		physw_status[2] = (kbd_new_state[2] | KEYS_MASK2) & (~KEYS_MASK2 | kbd_mod_state[2]);
	}
	
	
        //usb_remote_key(physw_status[USB_IDX]) ;
    remote_key = (physw_status[USB_IDX] & USB_MASK)==USB_MASK; 
    if (remote_key)
        remote_count += 1;
    else if (remote_count) 
     {
        usb_power = remote_count;
        remote_count = 0;
     }

        if (conf.remote_enable) {
                physw_status[USB_IDX] = physw_status[USB_IDX] & ~(SD_READONLY_FLAG | USB_MASK);
        } else {
                physw_status[USB_IDX] = physw_status[USB_IDX] & ~SD_READONLY_FLAG;
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

void kbd_key_press(long key) {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if (keymap[i].hackkey == key) {
			kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
			return;
		}
	}
}

void kbd_key_release(long key) {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if (keymap[i].hackkey == key) {
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
		if (keymap[i].hackkey == key) {
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


