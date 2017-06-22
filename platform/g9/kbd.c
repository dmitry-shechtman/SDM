#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
extern void _GetKbdState(long* buffer);

typedef struct {
	short grp;
	short hackkey;
	long canonkey;
} KeyMap;

	typedef struct {
		short fun;      
		long hackkey;

		long canonkey0; 
		long canonkey1;
		long canonkey2;
	} SwitchMap;

	// for dialmode-control
	static long switch_mod_state[3]; 
	static SwitchMap switchmap[];    
	static int switch_override = 0;  

#define SWITCH_MASK0 (0x00000000)
#define SWITCH_MASK1 (0x00000F00) 
#define SWITCH_MASK2 (0x00000000)
extern char *imgbuf;         // edge outline buffer
static long menu_key_mask=0x08000000;
static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];
static KeyMap keymap[];
static long last_kbd_key = 0;
static long alt_mode_key_mask = 0x00001000;  
static long alt_mode_key_reg  = 1;      //KEY PRINT 
static int usb_power=0;
static int remote_key, remote_count;
extern int inf_focus;
static int shoot_counter=0;
#define DELAY_TIMEOUT 10000

#define KEYS_MASK0 (0xC0000000)
#define KEYS_MASK1 (0x1F1F1018)
#define KEYS_MASK2 (0x00000000)
 
#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)

#define USB_MASK (0x40000)
#define USB_IDX 2
#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif

void kbd_fetch_data(long*);

long __attribute__((naked)) wrap_kbd_p1_f() ;

#include "../generic/wurb2.c"

static void __attribute__((noinline)) mykbd_task_proceed()
{
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
    /*WARNING
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

    /*function can be modified to restore SP here...
     */

    _ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{

    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      my_kbd_read_keys\n"
               	"B	 _kbd_p1_f_cont\n"		
    );
    return 0; //shut up the compiler
}

void my_kbd_read_keys()
{
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2];
    _kbd_pwr_on();
 //   kbd_fetch_data(kbd_new_state);
	_GetKbdState(kbd_new_state); //FF849300 
          checkKeyPress();

      if (kbd_process() == 0){
	//leave it alone...
	physw_status[0] = kbd_new_state[0];
	physw_status[1] = kbd_new_state[1];
	physw_status[2] = kbd_new_state[2];
      if(imgbuf)physw_status[1]  = physw_status[1] | menu_key_mask ;

    } else {
      // override keys

platform_kbd_hook();
        physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) |
              (kbd_mod_state[0] & KEYS_MASK0);

        physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) |
              (kbd_mod_state[1] & KEYS_MASK1);

        physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) |
              (kbd_mod_state[2] & KEYS_MASK2);

        // override dialposition if requested
        if (switch_override == 1) { 
                physw_status[0] = (physw_status[0] & (~SWITCH_MASK0)) | (switch_mod_state[0] & SWITCH_MASK0);
                physw_status[1] = (physw_status[1] & (~SWITCH_MASK1)) | (switch_mod_state[1] & SWITCH_MASK1);
                physw_status[2] = (physw_status[2] & (~SWITCH_MASK2)) | (switch_mod_state[2] & SWITCH_MASK2);
        }
    }

    _kbd_read_keys_r2(physw_status);
    remote_key = (physw_status[2] & USB_MASK)==USB_MASK;
    if (remote_key) 
       remote_count += 1;
    else if (remote_count) {
        usb_power = remote_count;
	  remote_count = 0;
    }
    if (conf.remote_enable) {
       physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);
    }
    else
       physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
    _kbd_pwr_off();
}



int get_usb_power(int edge)
{
	int x;

	if (edge) return remote_key;
	x = usb_power;
	usb_power = 0;
	return x;
}

/****************/
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
    if (key < 30 || key>34) {  // normal key
       for (i=0;keymap[i].hackkey;i++){
          if (keymap[i].hackkey == key){
             kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
             return;
          }
       }
    } else if((key >29) && (key<35)){ // dialmode-switch
       switch_override = 1;
       for (i=0; switchmap[i].hackkey; i++){
          if (switchmap[i].hackkey == key){
             switch_mod_state[0] |= switchmap[i].canonkey0;
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
    if (key < 30 || key>34) { // normal key
       for (i=0;keymap[i].hackkey;i++){
          if (keymap[i].hackkey == key){
             kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
             return;
          }
       }
    }  else if((key >29) && (key<35)){ // dialmode-switch
       switch_override = 0;
       for (i=0; switchmap[i].hackkey; i++){
          if (switchmap[i].hackkey == key){
              switch_mod_state[0] &= ~switchmap[i].canonkey0;
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

long kbd_use_zoom_as_mf() {/*  Незачем, в G7 есть колесо для этого
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
    }*/
    return 0;
}


static KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
	{ 1, KEY_UP			, 0x00100000 }, // g7
	{ 1, KEY_DOWN		, 0x00080000 }, // g7
	{ 1, KEY_LEFT		, 0x00010000 }, // g7
	{ 1, KEY_RIGHT		, 0x00040000 }, // g7
	{ 1, KEY_SET		, 0x00020000 }, // g7
	{ 0, KEY_SHOOT_FULL	, 0xC0000000 }, // g7
      { 0, KEY_SHOOT_FULL_ONLY, 0x80000000 },
	{ 0, KEY_SHOOT_HALF	, 0x40000000 }, // g7
	{ 1, KEY_ZOOM_IN	, 0x00000010 }, // g7
	{ 1, KEY_ZOOM_OUT	, 0x00000008 }, // g7
	{ 1, KEY_MENU		, 0x08000000 }, // g7
	{ 1, KEY_DISPLAY	, 0x04000000 }, // g7
	{ 1, KEY_PRINT		, 0x00001000 }, // g7
	{ 1, KEY_ERASE		, 0x01000000 }, // g7
	{ 1, KEY_EXPO_CORR  , 0x02000000 }, // g7
	{ 1, KEY_MICROPHONE , 0x10000000 }, // g7
//	{ 0, KEY_PLAY	    , 0x00020000 }, // g9
//        { 1, KEY_DUMMY   	, 0x00000000 },//
	{ 0, 0, 0 }
};

static SwitchMap switchmap[] = {
        { 1, MOVIE_MODE         , 0x00000000, 0x00000D00, 0x00000000 },    
        { 0, 0, 0, 0, 0 } 
};

void kbd_fetch_data(long *dst)
{
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;

    dst[0] = *mmio0;
    dst[1] = *mmio1;
    dst[2] = *mmio2 & 0xffff;
}

long is_key_pressed_now(long key)
{
 int i;
 long kbd_tmp_state[3];
 _GetKbdState(kbd_tmp_state);
 for (i=0;keymap[i].hackkey;i++)
  {
   if (keymap[i].hackkey == key)
    {
     return ((kbd_tmp_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
    }
  }
 return 0;
}

// KEYS_MASK0 (0xC0000000)
// KEYS_MASK1 (0x3F1F1018)
// KEYS_MASK2 (0x00000000)

//	 1 - C2008000
//0b0000 0000 0000 0000  1000 0000 0000 0000  - 0x00008000 	- ?
//0b0000 0000 0000 0010  0000 0000 0000 0000  - KEY_PLAY		- MODE_REC  / MODE_PLAY
//0b0000 0010 0000 0000  0000 0000 0000 0000  - 0x02000000	
//0b0100 0000 0000 0000  0000 0000 0000  0000  - KEY_SHOOT_HALF
//0b1100 0000 0000 0000  0000 0000 0000  0000  - KEY_SHOOT_FULL

//	 2 - 1F1F1418
//0b0000 0000 0000 0000  0000 0000 0000 0111    -ISO            000 - 100; 001 - 80; 010 - 200; 011 - HI; 100 - 800; 101-1600; 110 - 400; 111 - AUTO;
//0b0000 0000 0000 0000  0000 0000 0000 1000  -KEY_ZOOM_OUT
//0b0000 0000 0000 0000  0000 0000 0001  0000  -KEY_ZOOM_OUT
//0b0000 0000 0000 0000  0000 0000 0010  0000  - 0x00000020	- ?
//0b0000 0000 0000 0000  0000 0000 0100  0000  - 0x00000040	- ?
//0b0000 0000 0000 0000  0000 0000 1000  0000  - 0x00000080	- ?
//0b0000 0000 0000 0000  0000  1111   0000 0000 -ShotMode  0010 - C1; 0011 - C2; 0100 - Av; 0101 - Tv; 0110 - M; 0111 - P; 1100 - PANORAME; 1101-VIDEO; 1110 - SCN; 1111 - AUTO;   
//0b0000 0000 0000 0000  0001 0000 0000  0000  - KEY_PRINT
//0b0000 0000 0000 0000  0010 0000 0000  0000  - 0x00002000	- ?
//0b0000 0000 0000 0000  0100 0000 0000  0000  - 0x00004000	- ?
//0b0000 0000 0000 0000  1000 0000 0000  0000  - 0x00008000	- ?

//0b0000 0000 0000 0001  0000 0000 0000  0000  - NOT KEY_LEFT
//0b0000 0000 0000 0010  0000 0000 0000  0000  - NOT KEY_SET
//0b0000 0000 0000 0100  0000 0000 0000  0000  - NOT KEY_RIGHT
//0b0000 0000 0000 1000  0000 0000 0000  0000  - NOT KEY_DOWN
//0b0000 0000 0001 0000  0000 0000 0000  0000  - NOT KEY_UP

//0b0000 0000 0010 0000  0000 0000 0000  0000  - 0x00200000	- ?
//0b0000 0000 0100 0000  0000 0000 0000  0000  - 0x00400000	- ?
//0b0000 0000 1000 0000  0000 0000 0000  0000  - 0x00800000	- ?

//0b0000 0001 0000 0000  0000 0000 0000  0000  - NOT KEY_ERASE
//0b0000 0010 0000 0000  0000 0000 0000  0000  - NOT KEY_EXPO_CORR
//0b0000 0100 0000 0000  0000 0000 0000  0000  - NOT KEY_DISPLAY
//0b0000 1000 0000 0000  0000 0000 0000  0000  - NOT KEY_MENU
//0b0001 0000 0000 0000  0000 0000 0000  0000  - NOT KEY_MICROPHONE

//0b0010 0000 0000 0000  0000 0000 0000  0000  - 0x20000000	- ?`
//0b0100 0000 0000 0000  0000 0000 0000  0000  - 0x40000000	- ?`
//0b1000 0000 0000 0000  0000 0000 0000  0000  - 0x80000000	- ?`
//	 3 -00020004
//0b0000 0000 0000 0000  0000 0000 0000  0100  - 0x00000004	-? COVER BATTERY
//0b0000 0000 0000 0010  0000 0000 0000  0000  - 0x00020000	-? COVER BATTERY
//0b0000 0000 0000 0100  0000 0000 0000  0000  - USB_MASK = 0x00040000


