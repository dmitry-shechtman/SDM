#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"

#define KEY_MASK 0x17FF

#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)

typedef struct {
    long hackkey;
    long canonkey;
} KeyMap;

typedef struct 
{
	short fun;      //1 = permanent, 2 = toggle
	short hackkey;
	long canonkey0; 
	long canonkey1;
	long canonkey2;
} SwitchMap;

static long switch_mod_state[3]; 
static SwitchMap switchmap[];    
static int switch_override = 0;  

// dial-mode mask for bits that change

#define SWITCH_MASK0 (0xf0ffff0f)
#define SWITCH_MASK1 (0x00000680) 
#define SWITCH_MASK2 (0x0000b000) 
extern char *imgbuf;         // edge outline buffer
static long menu_key_mask=0x00000200;
long kbd_new_state[3];
long kbd_prev_state[3];
long kbd_mod_state = KEY_MASK;
long debug_kbd_state_diff;

static KeyMap keymap[];
static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key=0;
static int remote_count=0;
extern int inf_focus;
static int shoot_counter=0;
#define DELAY_TIMEOUT 10000
#define USB_MASK 0x8000000 
#define USB_IDX 1
volatile long *mmio1 = (void*)0xc0220204;

#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif

long __attribute__((naked)) wrap_kbd_p1_f() ;

// .........................................................................................................
long get_mmio(void)
{
 long x  = (long)*mmio1;	
 return x;	
}

int get_usb_bit() 
{
 register long usb_physw;
 usb_physw = *(long*)0xc0220204; 
 return(( usb_physw & USB_MASK)==USB_MASK);
}

#include "../generic/wurb1.c"

static void __attribute__((noinline)) hook_kbd_task_proceed()
{
    while (physw_run){
        _SleepTask(5);

        if (wrap_kbd_p1_f() == 1) // Readout key state via camera function
        {
            _kbd_p2_f();
        }

    }
}

void __attribute__((naked,noinline)) mykbd_task()
{
    /*WARNING
     * Stack pointer manipulation performed here!
     * This means (but not limited to):
     *  function arguments destroyed;
     *  function CAN NOT return properly;
     *  MUST NOT call or use stack variables before stack
     *  is setup properly;
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
        "MOV    SP, %0"
        :: "r"(((char*)newstack)+NEW_SS)
        : "memory"
    );

    hook_kbd_task_proceed();

    /*function can be modified to restore SP here...
     */

    _ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{

    asm volatile(
                "STMFD   SP!, {R4-R7,LR}\n"
                "SUB     SP, SP, #0xC\n"
                "BL      _kbd_read_keys\n"
                "BL      hook_kbd_handle_keys\n"
                "B       _kbd_p1_f_cont\n"        // Continue original function execution
    );
    return 0; //shut up the compiler
}

#define IN(base, value) ((value < base + 20) && (value > base - 20))

/**
 * Handles and forwards key settings to key processing routines
 */
void hook_kbd_handle_keys()
{
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2];

    kbd_new_state[0] = physw_status[0];
    kbd_new_state[1] = physw_status[1];
    kbd_new_state[2] = physw_status[2];
  
          checkKeyPress();

      if (kbd_process() == 0){
       if(imgbuf)physw_status[2]  = physw_status[2] | menu_key_mask ;
        // leave it ...
    } else {
        // Drop platform keys to none, and simulate ordered key presses
       platform_kbd_hook();
        physw_status[2] = (physw_status[2] & (~KEY_MASK)) | (kbd_mod_state & KEY_MASK);

      if (switch_override == 1) 
        { 
          physw_status[0] = (physw_status[0] & (~SWITCH_MASK0)) | (switch_mod_state[0] & SWITCH_MASK0); // set relevant bits to '0' then add new pattern
          physw_status[1] = (physw_status[1] & (~SWITCH_MASK1)) | (switch_mod_state[1] & SWITCH_MASK1);
          physw_status[2] = (physw_status[2] & (~SWITCH_MASK2)) | (switch_mod_state[2] & SWITCH_MASK2);
 
        }

       else if (switch_override == 2)                                                                   // playback mode
        {
          physw_status[2] = ((physw_status[2] & (~SWITCH_MASK2)) | (switch_mod_state[2] & SWITCH_MASK2))& 0xd000;
        }
    }

//  _kbd_read_keys_r2(physw_status);
      remote_key = (physw_status[1] & USB_MASK)==USB_MASK;   // USB V+ present ?
      if (remote_key)                 // Yes
      { 
        remote_count += 1;      // so increment 1/100 sec counter
       } 
      else if (remote_count)  // no, V+ is now zero but there was a pulse ?
       { 
          usb_power = remote_count;  // so get pulse-duration to usb_power
          remote_count = 0; // and reset pulse-width counter
       }

      if (conf.remote_enable) 
     {
        physw_status[1] = physw_status[1]  &  ~USB_MASK;        
     }
 
    // Drop SD readonly status
    physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
//    _kbd_pwr_off();

}

/****************/


void kbd_key_press(long key)
{
    int i;
   if(key<30 || key>34)                                              // normal key
  {
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            kbd_mod_state &= ~keymap[i].canonkey;
            return;
        }
    }
  }
 else if ((key >29) && (key<35))                                        // dialmode-switch
  { 
        if (key == 34)                                      // playback mode
        {            
         switch_override = 2;
        } else 
        {
            switch_override = 1;
        }

    for (i=0; switchmap[i].hackkey; i++)
      {
       if (switchmap[i].hackkey == key)                     // find override key in table
          {
            switch_mod_state[0] |= switchmap[i].canonkey0;  // and get bit patterns to switch_mod_state[]
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
 if (key < 30 || key>34) // normal key
  { 
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            kbd_mod_state |= keymap[i].canonkey;
            return;
        }
    }
  }

  else if ((key >29) && (key<35))                                        // dialmode-switch
   { 
     switch_override = 0;
     for (i=0; switchmap[i].hackkey; i++)                    // find override key in table
        {
         if (switchmap[i].hackkey == key)
           {
              switch_mod_state[0] &= ~switchmap[i].canonkey0; // add inverse bit-pattern to switch_mod_state[]
              switch_mod_state[1] &= ~switchmap[i].canonkey1;
              switch_mod_state[2] &= ~switchmap[i].canonkey2;
             return;
           }
         }
    }
}

void kbd_key_release_all()
{
    kbd_mod_state |= KEY_MASK;
  switch_override = 0;  // disable dialmode-override
}

long kbd_is_key_pressed(long key)
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            return ((kbd_new_state[2] & keymap[i].canonkey) == 0) ? 1:0;
        }
    }
    return 0;
}

long kbd_is_key_clicked(long key)
{
    int i;
    
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            return ((kbd_prev_state[2] & keymap[i].canonkey) != 0) &&
                    ((kbd_new_state[2] & keymap[i].canonkey) == 0);
        }
    }
    return 0;
}

long kbd_get_pressed_key()
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if ((kbd_new_state[2] & keymap[i].canonkey) == 0){
            return keymap[i].hackkey;
        }
    }
    return 0;
}

long kbd_get_clicked_key()
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if (((kbd_prev_state[2] & keymap[i].canonkey) != 0) &&
            ((kbd_new_state[2] & keymap[i].canonkey) == 0)){
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
            if (t-last_kbd_time > ( press_count ? KBD_REPEAT_DELAY : KBD_INITIAL_DELAY) ) {
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
        get_property_case(12, &v, 4);
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
        get_property_case(12, &v, 4);
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

int get_usb_power(int edge)
{
	int x;

	if (edge) return remote_key;
	x = usb_power;
	usb_power = 0;
	return x;
}

static SwitchMap switchmap[] = 
 {
        { 1, MOVIE_MODE, 0x00000000, 0x00000680, 0x00003000 },
        { 1, PLAYBACK_MODE, 0x00000000, 0x00000000, 0x00009000 }, 
	  { 0, 0, 0, 0, 0 }
 };

static KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
	{ KEY_UP	, 0x00000001 },
	{ KEY_DOWN	, 0x00000002 },
	{ KEY_LEFT	, 0x00000008 },
	{ KEY_RIGHT	, 0x00000004 },
	{ KEY_SET	, 0x00000100 },
	{ KEY_SHOOT_FULL, 0x00000030 }, // note 3 here!
      { KEY_SHOOT_FULL_ONLY, 0x00000020 },
	{ KEY_SHOOT_HALF, 0x00000010 },
	{ KEY_ZOOM_IN	, 0x00000040 },
	{ KEY_ZOOM_OUT	, 0x00000080 },
	{ KEY_MENU	, 0x00000200 },
	{ KEY_DISPLAY	, 0x00000400 },
	{ KEY_PRINT	, 0x00001000 },
//	{ KEY_ERASE	, 0x00000800 },
	{ KEY_DUMMY	, 0x00001000 },
	{ 0, 0 }
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
     return ((kbd_tmp_state[2] & keymap[i].canonkey) == 0) ? 1:0;
    }
  }
 return 0;
}

