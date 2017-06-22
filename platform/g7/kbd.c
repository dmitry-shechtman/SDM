#include "lolevel.h"
#include "conf.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

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
#define SWITCH_MASK1 (0x00000B00) 
#define SWITCH_MASK2 (0x00000000)
extern char *imgbuf;         // edge outline buffer
static long menu_key_mask=0x08000000;
static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];
static KeyMap keymap[];
static long last_kbd_key = 0;
static long alt_mode_key_mask = 0x10000000;
static int usb_power=0;
static int shoot_counter=0;
static int remote_key=0;
static int remote_count=0;
#define KEYS_MASK0 (0xC0000000)
#define KEYS_MASK1 (0x3F1F1418)
#define KEYS_MASK2 (0x00000000)
extern int inf_focus;
#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)

#define USB_MASK (0x40000)
#define USB_IDX 2
#define HOTSHOE_FLAG        0x00040000
#define HOTSHOE_IDX         0
#define DELAY_TIMEOUT 10000

#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif

#include "../generic/wurb2.c"

extern void _platformsub_kbd_fetch_data(long*);
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
                "STMFD   SP!, {R4-R7,LR}\n"
                "SUB     SP, SP, #0xC\n"
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

    _platformsub_kbd_fetch_data(kbd_new_state);

          checkKeyPress();

      if (kbd_process() == 0)
    {
	//leave it alone...
	physw_status[0] = kbd_new_state[0];
	physw_status[1] = kbd_new_state[1];
	physw_status[2] = kbd_new_state[2];
      physw_status[1] |= alt_mode_key_mask;
      if(imgbuf)physw_status[1]  = physw_status[1] | menu_key_mask ;
    } 
   else 
    {
	// override keys

platform_kbd_hook();
	physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) |
			  (kbd_mod_state[0] & KEYS_MASK0);

	physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) |
			  (kbd_mod_state[1] & KEYS_MASK1);

	physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) |
			  (kbd_mod_state[2] & KEYS_MASK2);

        if (switch_override == 1) { 
                physw_status[0] = (physw_status[0] & (~SWITCH_MASK0)) | (switch_mod_state[0] & SWITCH_MASK0);
                physw_status[1] = (physw_status[1] & (~SWITCH_MASK1)) | (switch_mod_state[1] & SWITCH_MASK1);
                physw_status[2] = (physw_status[2] & (~SWITCH_MASK2)) | (switch_mod_state[2] & SWITCH_MASK2);
        }
    }

  _kbd_read_keys_r2(physw_status);
 
      remote_key = (physw_status[2] & USB_MASK)==USB_MASK;   // USB V+ present ?
      if (remote_key)                 // Yes
      { 
        remote_count += 1;      // so increment 1/100 sec counter
       } 
      else if (remote_count)  // no, V+ is now zero but there was a pulse ?
       { 
          usb_power = remote_count;  // so get pulse-duration to usb_power
          remote_count = 0; // and reset pulse-width counter
         }

      if (conf.remote_enable ) 
     {
        physw_status[2] = physw_status[2]  &  ~(SD_READONLY_FLAG | USB_MASK);        
  }
 
  else
  {
    physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG; 

    _kbd_pwr_off();

  }

#ifdef CAM_HOTSHOE_OVERRIDE
    HOTSHOE_OVERRIDE; /* macro defined in platform.h */
#endif

}

/****************/

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
   } 
    else if((key >29) && (key<35)){ // dialmode-switch
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
   }  else if((key >29) && (key<35))
     { // dialmode-switch
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

long kbd_use_zoom_as_mf() {
    return 0;
}

static KeyMap keymap[] = {
    
	{ 1, KEY_UP		, 0x00100000 },
	{ 1, KEY_DOWN		, 0x00080000 },
	{ 1, KEY_LEFT		, 0x00010000 },
	{ 1, KEY_RIGHT		, 0x00040000 },
	{ 1, KEY_SET		, 0x00020000 },
	{ 0, KEY_SHOOT_FULL	, 0xC0000000 },
      { 0, KEY_SHOOT_FULL_ONLY, 0x80000000 }, 
	{ 0, KEY_SHOOT_HALF	, 0x40000000 },
	{ 1, KEY_ZOOM_IN	, 0x00000010 },
	{ 1, KEY_ZOOM_OUT	, 0x00000008 },
	{ 1, KEY_MENU		, 0x08000000 },
	{ 1, KEY_DISPLAY	, 0x04000000 },
	{ 1, KEY_PRINT		, 0x00001000 },
	{ 1, KEY_ERASE		, 0x01000000 },
        { 1, KEY_EXPO_CORR      , 0x02000000 },
        { 1, KEY_MICROPHONE     , 0x10000000 },
//        { 1, KEY_DUMMY   	, 0x00000000 },
	{ 0, 0, 0 }
};

static SwitchMap switchmap[] = {
        { 1, MOVIE_MODE         , 0x00000000, 0x00000900, 0x00000000 },    
        { 0, 0, 0, 0, 0 } 
};

int get_usb_power(int edge)
{
  int x; 
  if(edge) return remote_key;  // pulse present status (not pulse-width)
  x = usb_power;                      // pulse width only updated when V+ goes low
  usb_power = 0; 
  return x;
}

long is_key_pressed_now(long key)
{
 int i;
 long kbd_tmp_state[3];
 _platformsub_kbd_fetch_data(kbd_tmp_state);
 for (i=0;keymap[i].hackkey;i++)
  {
   if (keymap[i].hackkey == key)
    {
     return ((kbd_tmp_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
    }
  }
 return 0;
}

