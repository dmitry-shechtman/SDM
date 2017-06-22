#include "platform.h"
#include "lolevel.h"
#include "gui.h"
#include "..\\..\\core\\draw_palette.h"

static char*    frame_buffer[2];

/*
void LeftShift()
{
 _MoveISLensToLeftLimitPosition();
}

void RightShift()
{
 _MoveISLensToRightLimitPosition();
}
*/

void shutdown()
{
    volatile long *p = (void*)0xc022012C; // from S90

    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");

    *p = 0x44;

    while(1);
}


#define LED_GREEN 0xc0220130

void debug_led(int state)
{
    if (state)
		*((long*) LED_GREEN) = 0x46;
    else
		*((long*) LED_GREEN) = 0x44;
}
void ubasic_set_led(int led, int state, int bright)
{
  static char led_table[7]={0,0,1,1,1,9,9};
 if(led >=4 && led <= 10)
  _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}

/*
void ubasic_set_led(int led, int state, int bright) 
{
	static char led_table[4]={0,1,9,10};

    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}
*/

// TODO - check this
int get_flash_params_count(void)
{
	return 0x9a;   // found in GetParameterData 
}

/*
// Phil changes should make the screen draw and refresh work better
void vid_bitmap_refresh()
{
	extern int full_screen_refresh;
	extern void _LockAndRefresh();
	extern void _ScreenUnlock();

	full_screen_refresh |= 3;
	_LockAndRefresh();
	_ScreenUnlock();
}
*/

void vid_bitmap_refresh()
{
	 extern int enabled_refresh_physical_screen; // screen lock counter
	 extern void _ScreenUnlock();

	_ScreenLock();
	enabled_refresh_physical_screen=1;
	_ScreenUnlock();
}

void shutdown_soft()
{
   _PostLogicalEventForNotPowerType(0x1005,0);
}

#include "lolevel.h"

void switch_mode(int mode)
{
  if ( mode == 0 )
  {
    _Rec2PB();
    _set_control_event(0x80000902); // 0x10A5 ConnectUSBCable
  } else if ( mode == 1 )
  {
    _set_control_event(0x902); // 0x10A6 DisconnectUSBCable
    _PB2Rec();
  }
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
	return 2;               // S95 viewport is 480 pixels high
}

long vid_get_bitmap_screen_width()
{
    return 360;
}


long vid_get_bitmap_screen_height()
{
	return 240;
}


int vid_get_viewport_width()
{
	return 360;
}


long vid_get_viewport_height()
{
   return 240;

}


// used when drawing to lcd
long vid_get_bitmap_buffer_width()
{
	return 960;
}


long vid_get_bitmap_buffer_height()
{
	return 270;
}

long vid_get_bitmap_width()
{
	return 360;
}

long vid_get_bitmap_height()
{
	return 240;
}

