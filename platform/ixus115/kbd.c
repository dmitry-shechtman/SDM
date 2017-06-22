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



long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };


static KeyMap keymap[];

static int alt_mode_led=0;
extern void _GetKbdState(long*);

// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
#define KEYS_MASK0 (0x00000001)
#define KEYS_MASK1 (0xB5000000)
#define KEYS_MASK2 (0x0000003F)

/*#define KEYS_MASK0 (0xFFFFFFFF)
#define KEYS_MASK1 (0xFFFFFFFF)
#define KEYS_MASK2 (0xFFFF)*/


#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)
#define USB_MASK (0x4000000)
#define USB_REG 2
#define SD_READONLY_IDX     2
#define USB_IDX             2
#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);
#define DELAY_TIMEOUT 10000 

static KeyMap keymap[] = {

	// tiny bug: key order matters. KEY_SHOOT_FULL needs to come before KEY_SHOOT_HALF and KEY_SHOOT_FULL_ONLY

	{ 0, KEY_PLAYBACK    ,0x00000001 },
	{ 1, KEY_MENU        ,0x01000000 }, // Found @0xffb99680, levent 0x09
	{ 1, KEY_SET         ,0x04000000 }, // Found @0xffb99688, levent 0x08
	{ 1, KEY_ZOOM_OUT    ,0x10000000 }, // Found @0xffb99690, levent 0x03
	{ 1, KEY_ZOOM_IN     ,0x20000000 }, // Found @0xffb99698, levent 0x02
	{ 1, KEY_VIDEO       ,0x80000000 },
	{ 2, KEY_UP          ,0x00000001 }, // Found @0xffb996b0, levent 0x04
	{ 2, KEY_DOWN        ,0x00000002 }, // Found @0xffb996b8, levent 0x05
	{ 2, KEY_LEFT        ,0x00000004 }, // Found @0xffb996c0, levent 0x06
	{ 2, KEY_RIGHT       ,0x00000008 }, // Found @0xffb996c8, levent 0x07
	{ 2, KEY_SHOOT_FULL  ,0x00000030 }, // Found @0xffb996d8, levent 0x01
	{ 2, KEY_SHOOT_FULL_ONLY  ,0x00000020 },
	{ 2, KEY_SHOOT_HALF  ,0x00000010 }, // Found @0xffb996d0, levent 0x00
	{ 0, 0, 0 }
};

void kbd_set_alt_mode_key_mask(long key)
{
	// NOP ; -> obsolete, use to set variable alt_mode_key_mask but that was useless without the register # (0,1, or 2)
}


long __attribute__((naked)) wrap_kbd_p1_f();

static void __attribute__((noinline)) mykbd_task_proceed() {
	while (physw_run) {
		_SleepTask(*((int*)(0x1c44+0x8)));//10); @FF834508

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

//
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	asm volatile(
				"STMFD   SP!, {R1-R7,LR}\n"       //SX220 modified
				"MOV     R5, #0\n"
				"BL      my_kbd_read_keys\n"     // +
				"B       _kbd_p1_f_cont\n"       // continue
	);

	return 0;   // shut up the compiler
}


void my_kbd_read_keys() {

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

    extern void state_check_for_movie_af();
    state_check_for_movie_af(); // hack to prevent the "invisible af lock" caused by the movie af scan hack
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

static long last_kbd_key = 0;

void kbd_reset_autoclicked_key() 
{
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

#include "../generic/wurb2.c"


