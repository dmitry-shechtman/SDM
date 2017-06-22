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

static long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
extern void _GetKbdState(long*);
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);

//SX50
#define SD_READONLY_FLAG    0x00000002 // Found @0xff49e5dc, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x10000000 // Found @0xff49e64c, levent 0x202
#define USB_IDX             2
#define HOTSHOE_FLAG        0x00080000 // Found @0xff49e624, levent 0x204
#define HOTSHOE_IDX         2

//CHECK
#define KEYS_MASK0 (0x00CFFDE0)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x0000C000) 
#define DELAY_TIMEOUT 10000

static KeyMap keymap[] = {
    { 0, KEY_SET             ,0x00000400 }, // Found @0xff49e55c, levent 0x08
    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff49e564, levent 0x0a
    { 0, KEY_DOWN            ,0x00001000 }, // Found @0xff49e56c, levent 0x05
    { 0, KEY_MENU            ,0x00002000 }, // Found @0xff49e574, levent 0x09
    { 0, KEY_LEFT            ,0x00004000 }, // Found @0xff49e57c, levent 0x06
    { 0, KEY_UP              ,0x00040000 }, // Found @0xff49e59c, levent 0x04
    { 0, KEY_RIGHT           ,0x00080000 }, // Found @0xff49e5a4, levent 0x07
    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff49e5fc, levent 0x100
    { 2, KEY_PLAYBACK        ,0x00001000 }, // Found @0xff49e604, levent 0x101
    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff49e61c, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff49e61c, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff49e614, levent 0x00
    { 0, KEY_PRINT	     ,0x00800000 },
    { 0, KEY_FLASH           ,0x00400000 },
    { 0, KEY_ERASE	     ,0x00020000 },	
    { 0, KEY_VIDEO           ,0x00010000 },
    { 0, KEY_ZOOM_IN	     ,0x00000060 }, // 2 bits used, 4 values (0x00000060)
    { 0, KEY_ZOOM_IN_SLOW    ,0x00000020 }, // 2 bits used, 4 values (0x00000060)
    { 0, KEY_ZOOM_IN         ,0x00000040 }, // 2 bits used, 4 values (0x00000060)
    { 0, KEY_ZOOM_OUT	     ,0x00000180 }, // 2 bits used, 4 values (0x00000180)
    { 0, KEY_ZOOM_OUT_SLOW   ,0x00000080 }, // 2 bits used, 4 values (0x00000180)
    { 0, KEY_ZOOM_OUT        ,0x00000100 }, // 2 bits used, 4 values (0x00000180)
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f() ;


static void __attribute__((noinline)) mykbd_task_proceed()
{
	while (physw_run){
		_SleepTask(physw_sleep_delay);

		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline))
mykbd_task()
{
    mykbd_task_proceed();

    _ExitTask();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
	asm volatile(
		"STMFD   SP!, {R1-R7,LR}\n"
		"MOV     R5, #0\n"
		//"BL      _kbd_read_keys \n"
		"BL		my_kbd_read_keys\n"
		"B       _kbd_p1_f_cont\n"
	);
	return 0; // shut up the compiler
}

// Set to 1 to disable jogdial events from being processed in firmware
volatile int jogdial_stopped=0;

void my_kbd_read_keys()
{
	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];

	_GetKbdState(kbd_new_state);
	_kbd_read_keys_r2(kbd_new_state);
      checkKeyPress();
	if (kbd_process() == 0){
//	if ((kbd_process() == 0)&&!inf_focus){
		// leave it alone...
          physw_status[0] = kbd_new_state[0];
          physw_status[1] = kbd_new_state[1];
          physw_status[2] = kbd_new_state[2];

	} else {
		// override keys
            platform_kbd_hook();
	 	physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) | (kbd_mod_state[0] & KEYS_MASK0);
		physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) | (kbd_mod_state[1] & KEYS_MASK1);
		physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) | (kbd_mod_state[2] & KEYS_MASK2);
	}

    remote_key = (physw_status[USB_IDX] & USB_MASK)==USB_MASK; 
    if (remote_key)
        remote_count += 1;
    else if (remote_count) 
     {
        usb_power = remote_count;
        remote_count = 0;
     }

    physw_status[SD_READONLY_IDX] = physw_status[SD_READONLY_IDX] & ~SD_READONLY_FLAG;
	if (conf.remote_enable) {
		physw_status[USB_IDX] = physw_status[USB_IDX] & ~USB_MASK;
	}
#ifdef CAM_HOTSHOE_OVERRIDE
    HOTSHOE_OVERRIDE; /* macro defined in platform.h */
#endif
}


/****************/

void kbd_set_alt_mode_key_mask(long key)
{
}

int get_usb_power(int edge) 
{
  int x;
  if (edge) return remote_key;
  x = usb_power;
  usb_power = 0;
  return x;
}

void kbd_key_press(long key)
{
	int i;

	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key)
		{
			kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
			return;
		}
	}
}

void kbd_key_release(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
			return;
		}
	}
}

void kbd_key_release_all()
{
	kbd_mod_state[0] |= KEYS_MASK0;
	kbd_mod_state[1] |= KEYS_MASK1;
	kbd_mod_state[2] |= KEYS_MASK2;
}

long kbd_is_key_pressed(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)
                return 1;
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


