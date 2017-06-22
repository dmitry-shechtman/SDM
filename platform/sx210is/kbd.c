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

static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];
static KeyMap keymap[];
static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
extern char *imgbuf;              // edge outline buffer
extern int inf_focus;
static int shoot_counter=0;
static long alt_mode_key_mask = 0x00004000; // key_print
static int alt_mode_led=0;

#define DELAY_TIMEOUT 10000

#define KEYS_MASK0 (0x00002182)     // physw_status[0]
//#define KEYS_MASK1 (0x000FC005)

//#define KEYS_MASK1 (0x000FCF05)
// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
#define KEYS_MASK1 (0x000FFC05)
#define KEYS_MASK2 (0x00000000)  // physw_status[2]

#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)
#define USB_MASK (0x80000)
#define USB_IDX 3

#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif



volatile int jogdial_stopped=0;

long __attribute__((naked)) wrap_kbd_p1_f();

static void __attribute__((noinline)) mykbd_task_proceed() {
    while (physw_run) {
        _SleepTask(10);

        if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
            _kbd_p2_f();
        }
    }
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline)) mykbd_task() {
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

// ROM:FF83484C, like SX110
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      _kbd_read_keys\n"       // replaces kbd_fetch_data()
                "BL      my_kbd_read_keys\n"     // +
                "B       _kbd_p1_f_cont\n"       // continue at ROM:FF834858
    );
    return 0;   // shut up the compiler
}

// like SX110
void my_kbd_read_keys() {
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    //kbd_prev_state[2] = kbd_new_state[2];   // nothing to override

    // The following three lines replace the call to kbd_fetch_data()
    kbd_new_state[0] = physw_status[0];
    kbd_new_state[1] = physw_status[1];
    //kbd_new_state[2] = physw_status[2];

  /*static char osd_buf[64];
        sprintf(osd_buf, "1:%8x  ", physw_status[0]);
        draw_txt_string(28, 10, osd_buf, conf.osd_color);

        sprintf(osd_buf, "2:%8x  ", physw_status[1]);
        draw_txt_string(28, 11, osd_buf, conf.osd_color);

        sprintf(osd_buf, "3:%8x  ", physw_status[2]);
        draw_txt_string(28, 12, osd_buf, conf.osd_color);*/



          checkKeyPress();

      if (kbd_process() == 0) {
        // we read keyboard state with _kbd_read_keys()

        jogdial_stopped=0;
    } else {
        // override keys

platform_kbd_hook();
        physw_status[0] = (kbd_new_state[0] | KEYS_MASK0) & (~KEYS_MASK0 | kbd_mod_state[0]);
        physw_status[1] = (kbd_new_state[1] | KEYS_MASK1) & (~KEYS_MASK1 | kbd_mod_state[1]);
        //physw_status[2] = (kbd_new_state[2] | KEYS_MASK2) & (~KEYS_MASK2 | kbd_mod_state[2]);

        if ((jogdial_stopped==0) && !state_kbd_script_run) {
            jogdial_stopped=1;
            get_jogdial_direction();
        }
        else if (jogdial_stopped && state_kbd_script_run)
            jogdial_stopped=0;
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
    }
    else
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


/*
int Get_JogDial(void) {
    return (*(int*)0xC0240104)>>16;     // 0xC0240000 + 0x104
}

static int new_jogdial=0, old_jogdial=0;

long get_jogdial_direction(void) {
    old_jogdial=new_jogdial;
    new_jogdial=Get_JogDial();

    if (old_jogdial<new_jogdial) {
        //return JOGDIAL_LEFT;
        return JOGDIAL_RIGHT;
    } else if (old_jogdial>new_jogdial) {
        return JOGDIAL_LEFT;
        //return JOGDIAL_RIGHT;
    } else {
        return 0;
    }
}
*/

static KeyMap keymap[] = {

		//play button doesn't alter anything here...????

		//door open a19b -> 219b
		//power b -> 3
	{ 0, KEY_SHOOT_FULL	, 0x00002002 },  //   b ->    9
	{ 0, KEY_SHOOT_FULL_ONLY, 0x00000002 },
	{ 0, KEY_SHOOT_HALF	, 0x00002000 },  //a19b -> 819b
	{ 0, KEY_UP		    , 0x00000080 },  // 9b -> 1b
	{ 0, KEY_DOWN		, 0x00000100 },  // 19b -> 09b
	{ 1, KEY_LEFT		     , 0x00008000 },  // ffff -> efff --> 6fff (hard)  test ef3f ->633f
	{ 1, KEY_RIGHT		     , 0x00004000 },  // ffff -> dfff --> 9fff (hard)  test df3f ->d73f  -> f7ff -> ffff was 4000
	{ 1, KEY_SET		     , 0x00010000 },  // ASM1989 tested (JH) - fffff -> effff
	{ 1, KEY_ZOOM_IN         , 0x00000004 },  // f -> b (slow)
	{ 1, KEY_ZOOM_OUT        , 0x00000001 },  // f -> e (slow)
	{ 1, KEY_MENU		     , 0x00040000 },  // ASM1989 tested (JH) - fffff -> bffff
	{ 1, KEY_DISPLAY         , 0x00020000 },  // ASM1989 tested (JH) - fffff -> dffff
	{ 1, KEY_PRINT		     , 0x00080000 },  // ASM1989 tested (JH) - fffff -> 7ffff
     	{ 0, 0, 0 }
};

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
