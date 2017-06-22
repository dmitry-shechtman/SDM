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

static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);
extern void _GetKbdState(long*);

//void my_blinkk(void) {
//	int i;
////	while(1) {
//		*((volatile int *) 0xC0220134) = 0x46; // Turn on LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x44; // Turn off LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x46; // Turn on LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x44; // Turn off LED
//		for (i=0; i<0x900000; i++) { asm volatile ( "nop\n" ); }
////	}
//}

#define KEYS_MASK0 (0x00CFFDE0)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x0000C000) 

#define SD_READONLY_FLAG    0x00000002 // Found @0xff434b6c, levent 0x20a
#define SD_READONLY_IDX     1
#define DELAY_TIMEOUT 10000
#define USB_MASK            0x40000000 // Found @0xff434be4, levent 0x202
#define USB_IDX  2

extern void usb_remote_key( void ) ;


static KeyMap keymap[] = {

	{ 0, KEY_ZOOM_IN	     ,0x00000060 }, // 2 bits used, 4 values (0x00000060)
	{ 0, KEY_ZOOM_IN	     ,0x00000020 }, // 2 bits used, 4 values (0x00000060)
	{ 0, KEY_ZOOM_IN	     ,0x00000040 }, // 2 bits used, 4 values (0x00000060)
	{ 0, KEY_ZOOM_OUT	     ,0x00000180 }, // 2 bits used, 4 values (0x00000180)
	{ 0, KEY_ZOOM_OUT	     ,0x00000080 }, // 2 bits used, 4 values (0x00000180)
	{ 0, KEY_ZOOM_OUT	     ,0x00000100 }, // 2 bits used, 4 values (0x00000180)
    { 0, KEY_UP              ,0x00000400 }, // Found @0xff434aec, levent 0x04
    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff434af4, levent 0x05
    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff434afc, levent 0x06
    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xff434b04, levent 0x07
    { 0, KEY_SET             ,0x00004000 }, // Found @0xff434b0c, levent 0x08
	{ 0, KEY_VIDEO           ,0x00008000 },
	{ 0, KEY_ZOOM_ASSIST     ,0x00010000 },
    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xff434b24, levent 0x0a
    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff434b2c, levent 0x09
	{ 0, KEY_ERASE		     ,0x00080000 },
	{ 0, KEY_FLASH           ,0x00400000 },
	{ 0, KEY_PRINT		     ,0x00800000 },

    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff434b8c, levent 0x100
    { 2, KEY_PLAYBACK        ,0x00001000 }, // Found @0xff434b94, levent 0x101
    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff434bac, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff434bac, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff434ba4, levent 0x00

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

	//_kbd_read_keys_r2(physw_status);

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

	for (i=0;keymap[i].hackkey;i++)
    {
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
	for (i=0;keymap[i].hackkey;i++)
    {
		if (keymap[i].hackkey == key)
        {
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
	for (i=0;keymap[i].hackkey;i++)
    {
		if (keymap[i].hackkey == key)
        {
			if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)
                return 1;
		}
	}
	return 0;
}

long kbd_is_key_clicked(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++)
    {
		if (keymap[i].hackkey == key)
        {
			return ((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
			       ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0);
		}
	}
	return 0;
}

long kbd_get_pressed_key()
{
	int i;
	for (i=0;keymap[i].hackkey;i++)
    {
		if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)
        {
			return keymap[i].hackkey;
		}
	}
	return 0;
}

long kbd_get_clicked_key()
{
	int i;
	for (i=0;keymap[i].hackkey;i++)
    {
		if (((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
		    ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0))
        {
			return keymap[i].hackkey;
		}
	}
	return 0;
}

void kbd_reset_autoclicked_key()
{
	last_kbd_key = 0;
}

long kbd_get_autoclicked_key()
{
	static long last_kbd_time = 0, press_count = 0;
	register long key, t;

	key=kbd_get_clicked_key();
	if (key && (key != last_kbd_key))
    {
		last_kbd_key = key;
		press_count = 0;
		last_kbd_time = get_tick_count();
		return key;
	}
    else
    {
		if (last_kbd_key && kbd_is_key_pressed(last_kbd_key))
        {
			t = get_tick_count();
			if (t-last_kbd_time>((press_count)?175:500))
            {
				++press_count;
				last_kbd_time = t;
				return last_kbd_key;
			}
            else
            {
				return 0;
			}
		}
        else
        {
			last_kbd_key = 0;
			return 0;
		}
	}
}

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

#include "../generic/wurb2.c"


