#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "stdlib.h"

typedef struct 
{
	short grp;
	short hackkey;
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
#define SWITCH_MASK1 (0x00020000) 
#define SWITCH_MASK2 (0x00600002) 
static long menu_key_mask=0x00000800;

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
extern long aHookList[];
extern long aHookNum;

#define DELAY_TIMEOUT 10000
#define KEYS_MASK0 (0x0000000F)
#define KEYS_MASK1 (0x00094800)
#define KEYS_MASK2 (0x00007041)

#define SD_READONLY_FLAG (0x20000)  // 1 << 0x11
#define SD_READONLY_REG 2

#define USB_MASK (0x80000)
#define USB_IDX 2
volatile int jogdial_stopped=0;

void kbd_fetch_data(long*);
long kbd_get_held_key();

long __attribute__((naked)) wrap_kbd_p1_f() ;


static void __attribute__((noinline)) mykbd_task_proceed()
{
    while (physw_run)
     {
	_SleepTask(10);

	if (wrap_kbd_p1_f() == 1)
      { // autorepeat ?
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
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      my_kbd_read_keys\n"
               	"B	 _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}

void my_kbd_read_keys()
{
	static char osd_buf[64];

	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];
	kbd_fetch_data(kbd_new_state);
      checkKeyPress();

      if (kbd_process() == 0)
		{
			physw_status[0] = kbd_new_state[0];
			physw_status[1] = kbd_new_state[1];
			physw_status[2] = (physw_status[2]  & (~KEYS_MASK2)) |
			(kbd_new_state[2] & KEYS_MASK2);
			physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
		}
		else
		{
               platform_kbd_hook();
			physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) |
					  (kbd_mod_state[0] & KEYS_MASK0);
			physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) |
					  (kbd_mod_state[1] & KEYS_MASK1);
			physw_status[2] = (physw_status[2]  & (~KEYS_MASK2)) |
						(kbd_mod_state[2] & KEYS_MASK2);  //fix needed as below
			physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
             if (switch_override == 1) 
              { 
               physw_status[1] = (physw_status[1] & (~SWITCH_MASK1)) | (switch_mod_state[1] & SWITCH_MASK1); // set relevant bits to '0' then add new pattern
               physw_status[2] = (physw_status[2] & (~SWITCH_MASK2)) | (switch_mod_state[2] & SWITCH_MASK2); // set relevant bits to '0' then add new pattern
              }
		}

    _kbd_read_keys_r2(physw_status);

    remote_key = (physw_status[2] & USB_MASK)==USB_MASK;
    if (remote_key)  remote_count += 1;
    else if (remote_count) 
      {
         usb_power = remote_count;
         remote_count = 0;
      }

    if (conf.remote_enable) 
     {
      physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);
     }
    else physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
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
    switch_override = 1;
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
    if (key) 
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

long kbd_get_held_key() 
{
    static long last_kbd_time = 0, press_count = 0;
    register long key, t;

    key=kbd_get_clicked_key();
    if (key) 
    {
        last_kbd_key = key;
        press_count = 0;
        last_kbd_time = get_tick_count();
        return 0;
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

	//SD780 - Keymap
	{ 0, KEY_UP		      , 0x00000008 },
	{ 0, KEY_DOWN		, 0x00000004 },
	{ 0, KEY_LEFT		, 0x00000001 },
	{ 0, KEY_RIGHT		, 0x00000002 },
	{ 1, KEY_SET		, 0x00004000 },
	{ 1, KEY_MENU		, 0x00000800 },
	{ 1, KEY_POWER		, 0x00010000 },  //SD780 Power button
	{ 2, KEY_SHOOT_FULL	, 0x00001001 },
      { 2, KEY_SHOOT_FULL_ONLY, 0x00001000 },
	{ 2, KEY_SHOOT_HALF	, 0x00000001 },
	{ 2, KEY_ZOOM_IN	      , 0x00004000 },
	{ 2, KEY_ZOOM_OUT	      , 0x00002000 },
	{ 2, KEY_DISPLAY	      , 0x00000040 },  										
	{ 0, 0, 0 }
};

static SwitchMap switchmap[] = 
 {
        { 1, MOVIE_MODE, 0x00000000, 0x00000000, 0x00200002},
	  { 0, 0, 0, 0, 0 }
 };

void kbd_fetch_data(long *dst)
{
	//SD780 0xFF8431EC GetKbdState
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


