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


static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];

static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);

#define DELAY_TIMEOUT 10000

#define KEYS_MASK0 (0x00020000)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x017001f4)

#define SD_READONLY_FLAG (0x40000)
#define USB_MASK (0x80000)
#define USB_IDX 2


static KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
    * for example
    */
 
    { 0, KEY_PLAYBACK   , 0x00020000 }, // Playback
    { 2, KEY_SHOOT_FULL , 0x00000030 }, // ? 0x00000010(KEY_SHOOT_HALF) + 0x00000030 (KEY_SHOOT_FULL)
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000020 },
    { 2, KEY_SHOOT_HALF , 0x00000010 },   
    { 2, KEY_UP         , 0x00100000 },
    { 2, KEY_DOWN       , 0x00200000 },
    { 2, KEY_LEFT       , 0x00400000 },
    { 2, KEY_RIGHT      , 0x00000004 },
    { 2, KEY_SET        , 0x00000100 },
    { 2, KEY_ZOOM_IN    , 0x00000080 },
    { 2, KEY_ZOOM_OUT   , 0x00000040 },
    { 2, KEY_MENU       , 0x01000000 },
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f() ;

static void __attribute__((noinline)) mykbd_task_proceed()
{
	while (physw_run){
		_SleepTask(10);
		
		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
}

void __attribute__((naked,noinline)) mykbd_task()
{
	mykbd_task_proceed();
	_ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
	asm volatile(
			"STMFD   SP!, {R1-R5,LR}\n"
			"MOV     R4, #0\n"
			//"BL      _kbd_read_keys\n"       // replaces kbd_fetch_data()
			"BL      my_kbd_read_keys\n"     // +
			"B       _kbd_p1_f_cont\n"       // continue
	);
	
	return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
	kbd_prev_state[0] = kbd_new_state[0];
	//kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];
	
	asm volatile(
        "BL      _kbd_read_keys\n"
	);
	
	//_platformsub_kbd_fetch_data(kbd_new_state);
	kbd_new_state[0] = physw_status[0];
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2];
	
	      checkKeyPress();

      if (kbd_process() == 0){
		// leave it alone...
	} else {
        // override keys

platform_kbd_hook();
        physw_status[0] = (kbd_new_state[0] | KEYS_MASK0) & (~KEYS_MASK0 | kbd_mod_state[0]);
        //physw_status[1] = (kbd_new_state[1] | KEYS_MASK1) & (~KEYS_MASK1 | kbd_mod_state[1]);
        physw_status[2] = (kbd_new_state[2] | KEYS_MASK2) & (~KEYS_MASK2 | kbd_mod_state[2]);
	}
	
	//_kbd_read_keys_r2(physw_status);

	remote_key = (physw_status[2] & USB_MASK) == USB_MASK;
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



/****************/

void kbd_key_press(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
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
	kbd_mod_state[2] |= KEYS_MASK2 & ~0x01700000;
}

long kbd_is_key_pressed(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			switch (keymap[i].hackkey) {
			case KEY_UP: case KEY_DOWN: case KEY_LEFT: case KEY_MENU:
				return ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 0:1;
			default:
				return ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
			}
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
		if (kbd_is_key_pressed(keymap[i].hackkey)) {
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

long kbd_use_zoom_as_mf() {
	return 0;
}

long is_key_pressed_now(long key)
{
 int i;
 long kbd_tmp_state[3];
 asm volatile("BL      _kbd_read_keys\n");
 kbd_tmp_state[0] = physw_status[0];
 kbd_tmp_state[1] = physw_status[1];
 kbd_tmp_state[2] = physw_status[2];
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


