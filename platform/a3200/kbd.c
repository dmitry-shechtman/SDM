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

static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
extern void _platformsub_kbd_fetch_data(long*);

#define DELAY_TIMEOUT 10000

extern void _GetKbdState(long*);

// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
#define KEYS_MASK0 (0x00002000) //Logic OR of group 0 Keymap values
#define KEYS_MASK1 (0x00000000) //Logic OR of group 1 Keymap values
#define KEYS_MASK2 (0x0000F0FF) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x00020000 // Found @0xffb5d574, levent 0x90a
#define USB_MASK            0x04000000 // Found @0xffb5d594, levent 0x902
#define USB_FLAG            0x04000000 // ?? Found @0xff3bcf44 a3300, levent 0x902
#define USB_IDX 2
#define SD_READONLY_IDX     2

extern void usb_remote_key( void ) ;

static KeyMap keymap[] = {
	// Order IS important. kbd_get_pressed_key will walk down this table  
	// and take the first matching mask. Notice that KEY_SHOOT_HALF is  
	// always pressed if KEY_SHOOT_FULL is. --MarcusSt
 
    { 0, KEY_PLAYBACK        ,0x00002000 }, // Found @0xffb5d4cc, levent 0x601
//  { 0, KEY_POWER           ,0x00004000 }, // Found @0xffb5d4d4, levent 0x600
    { 2, KEY_SHOOT_FULL      ,0x00003000 }, // Found @0xffb5d544, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffb5d53c, levent 0x00
    { 2, KEY_SHOOT_FULL_ONLY ,0x00002000 }, // Found @0xffb5d544, levent 0x01
    { 2, KEY_FACE            ,0x00000040 }, //
    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb5d4e4, levent 0x04
    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb5d4ec, levent 0x05
    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb5d4f4, levent 0x06
    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb5d4fc, levent 0x07
    { 2, KEY_SET             ,0x00000010 }, // Found @0xffb5d504, levent 0x08
    { 2, KEY_DISPLAY         ,0x00000020 }, // Found @0xffb5d50c, levent 0x0a
    { 2, KEY_MENU            ,0x00000080 }, // Found @0xffb5d51c, levent 0x09
    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xffb5d54c, levent 0x03
    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xffb5d554, levent 0x02    
    { 0, 0, 0 }
};

// NOP
void kbd_set_alt_mode_key_mask(long key)
{
}


extern long __attribute__((naked)) wrap_kbd_p1_f() {

    asm volatile(
        "STMFD	SP!, {R1-R7,LR} \n"
        "MOV	R5, #0 \n"
	//"BL	_kbd_read_keys \n"
	"BL	my_kbd_read_keys \n"	// patched
	"B	_kbd_p1_f_cont \n"
	);
	return 0; // shut up the compiler
}
	
	
static void __attribute__((noinline)) mykbd_task_proceed() {
	
	while (physw_run) {
        _SleepTask(*((int*)(0x1C30 + 0x8))); //  @FF83410C + FF834114

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


void my_kbd_read_keys() {
		

    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2]; 

	_GetKbdState( kbd_new_state );
	_kbd_read_keys_r2( kbd_new_state);
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
        physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);   // override USB and SD-Card Readonly Bits
    }
   
    physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;   // override SD-Card Readonly Bit
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

void kbd_reset_autoclicked_key() {

	last_kbd_key = 0;
}

long kbd_use_zoom_as_mf() 
{
 return 0;
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

