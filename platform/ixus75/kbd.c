#include "lolevel.h"
#include "platform.h"
#include "conf.h"
#include "core.h"
#include "keyboard.h"

typedef struct {
	short grp;
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

#define SWITCH_MASK0 (0x00000000)
#define SWITCH_MASK1 (0x0000000) 
#define SWITCH_MASK2 (0x0007000) 
extern char *imgbuf;         // edge outline buffer
static long menu_key_mask=0x00000400;
static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];
static KeyMap keymap[];
static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
static int shoot_counter=0;
extern int inf_focus;
#define USB_MASK (0x40000) 
#define USB_IDX 2


#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0xc0000000) // (0xc0800000)
#define KEYS_MASK2 (0x0ffc)

#define NEW_SS (0x2000)
#define SD_READONLY_FLAG (0x20000)
#define DELAY_TIMEOUT 10000

#ifndef MALLOCD_STACK
static char kbd_stack[NEW_SS];
#endif

long __attribute__((naked)) wrap_kbd_p1_f() ;

// -------------------------------------------------------------------------------------------------------------

static void __attribute__((noinline)) mykbd_task_proceed()
{
    while (physw_run){
	_SleepTask(10);

	if (wrap_kbd_p1_f() == 1){ // autorepeat ?
	    _kbd_p2_f();
	}
    }
}

void __attribute__((naked,noinline)) mykbd_task(long ua, long ub, long uc, long ud, long ue, long uf)
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
    _kbd_pwr_on();
    kbd_fetch_data(kbd_new_state);
/*
    static int taskFeatherID = 0;

    if (taskFeatherID == 0) 
    {
      taskFeatherID = _taskNameToId("tFeather");
      _printf("taskFeatherID:%x\n", taskFeatherID);
    }
*/

          checkKeyPress();

      if (kbd_process() == 0)
   {
	//leave it alone...
	physw_status[0] = kbd_new_state[0];
	physw_status[1] = kbd_new_state[1];
	physw_status[2] = kbd_new_state[2];
      if(imgbuf)physw_status[2]  = physw_status[2] | menu_key_mask ;

/*
#if CAM_FEATURE_FEATHER
        _taskResume(taskFeatherID);
#endif
*/

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
/*
#if CAM_FEATURE_FEATHER
        _taskSuspend(taskFeatherID);

        // We still need this sema when simulating key presses
        if ((kbd_mod_state[0] != KEYS_MASK0) ||(kbd_mod_state[1] != KEYS_MASK1)||(kbd_mod_state[2] != KEYS_MASK2)) 
        {
            _taskResume(taskFeatherID);
        }
#endif
*/

      if (switch_override == 1) 
        { 
          physw_status[0] = (physw_status[0] & (~SWITCH_MASK0)) | (switch_mod_state[0] & SWITCH_MASK0); // set relevant bits to '0' then add new pattern
          physw_status[2] = (physw_status[2] & (~SWITCH_MASK2)) | (switch_mod_state[2] & SWITCH_MASK2);
        }

       else if (switch_override == 2)                                                                   // playback mode
        {
          physw_status[0] = ((physw_status[0] & (~SWITCH_MASK0)) | (switch_mod_state[0] & SWITCH_MASK0)) & 0x00100008;
        }


    }



    _kbd_read_keys_r2(physw_status);

	if (conf.remote_enable) {
		remote_key = (physw_status[2] & USB_MASK)==USB_MASK;
		if (remote_key) 
			remote_count += 1;
		else if (remote_count) {
			usb_power = remote_count;
			remote_count = 0;
		}
		physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);
	}
	else
		physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;


    _kbd_pwr_off();

}



void kbd_key_press(long key)
{
    int i;
   if(key<30 || key>34)                                              // normal key
  {
    for (i=0;keymap[i].hackkey;i++){
	if (keymap[i].hackkey == key){
	    kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
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
	    kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
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



static KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
	{2, KEY_UP	, 0x00000010 },
	{2, KEY_DOWN	, 0x00000040 },
	{2, KEY_LEFT	, 0x00000080 },
	{2, KEY_RIGHT	, 0x00000020 },
	{2, KEY_SET	, 0x00000100 },
	{1, KEY_SHOOT_FULL, 0xC0000000 }, // note 3 here!
      {1, KEY_SHOOT_FULL_ONLY, 0x80000000 },
	{1, KEY_SHOOT_HALF, 0x40000000 },
	{2, KEY_ZOOM_IN	, 0x00000004 },
	{2, KEY_ZOOM_OUT, 0x00000008 },
	{2, KEY_MENU	, 0x00000400 },
	{2, KEY_DISPLAY	, 0x00000200 },
	{2, KEY_PRINT	, 0x00000800 },
      //  {2, KEY_DUMMY	, 0x00000800 },
	{ 0, 0 }
};

// Within the masked bits, these are values for each switch

static SwitchMap switchmap[] = 
 {
        { 1, MOVIE_MODE, 0x00000000, 0x00000000, 0x00006000 },
        { 1, PLAYBACK_MODE, 0x00000000, 0x00000000, 0x00000000 }, 
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

int get_usb_power(int edge)
{
	int x;
	if (edge) return remote_key;
	x = usb_power;
	usb_power = 0;
	return x;
}

long is_key_pressed_now(long key)
{
 int i;
 long kbd_tmp_state[3];
 kbd_fetch_data(kbd_tmp_state);
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

