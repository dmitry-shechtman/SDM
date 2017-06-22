
#include "platform.h"
#include "lolevel.h"

/*
*********************
SX150IS
********************** 
*/

/*
SX150
LED address:
same as sx210
orange 0xC0220010
green  0xC0220014
AF      0xC022000C
*/
#define LED_AF		0xC022000C
#define LED_ORANGE	0xC0220010
#define LED_GREEN	0xC0220014

#define DELAY 300000

#define LED_ON 		*((long*) LED_GREEN) = 0x46
#define LED_OFF		*((long*) LED_GREEN) = 0x44

#define LED_ON_RED 		*((long*) LED_ORANGE) = 0x46
#define LED_OFF_RED		*((long*) LED_ORANGE) = 0x44

#define LED_ON_AF 		*((long*) LED_AF) = 0x46
#define LED_OFF_AF		*((long*) LED_AF) = 0x44

long vid_get_bitmap_width(){ return 360; }
long vid_get_bitmap_screen_width() { return 360; }
long vid_get_bitmap_height(){ return 240; }
long vid_get_bitmap_screen_height() { return 240; }
long vid_get_bitmap_buffer_width() { return 720; }
long vid_get_bitmap_buffer_height() { return 240; }

void debug_led(int state)
{
    if (state)
		LED_ON;
    else
		LED_OFF;
} 

// Testing another refresh method
void vid_bitmap_refresh()
{
	extern int enabled_refresh_physical_screen;
	extern int full_screen_refresh;

	// i've tried refreshphysical screen (screen unlock) and that caused the canon and
	// function menu to not display at all. This seems to work and is called in a similar
	// way in other places where original OSD should be refreshed.
	extern void _LockAndRefresh(); // wrapper function for screen lock
	extern void _UnlockAndRefresh(); // wrapper function for screen unlock

	_LockAndRefresh();

	enabled_refresh_physical_screen=1;
	full_screen_refresh |= 3; 

	_UnlockAndRefresh();
}

void shutdown()
{
	volatile long *p = (void*)0xC022001C;    
	
	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");
	
	*p = 0x44;  // power off.
	
	while(1);
}

void switch_mode(int mode)
{
    if ( mode == 0 ) 
    {
     _Rec2PB();
     _set_control_event(0x80000000 | CAM_USB_EVENTID); // 0x10A5 ConnectUSBCable
    } 
    else if ( mode == 1 ) 
    {
     _set_control_event(CAM_USB_EVENTID); // 0x10A6 DisconnectUSBCable
     _PB2Rec();
    } 
}


void ubasic_set_led(int led, int state, int bright) 
{
 static char led_table[7]={0,1,0,1,0,9,0};
 _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 0x9f; 
}

void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x874, 2);  // RotateJogDialRight
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x875, 2);  // RotateJogDialLeft
}


#if defined(CAM_CHDK_PTP_LIVE_VIEW)
// Functions for PTP Live View system

int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_buffer()
{
    extern int active_bitmap_buffer;
    extern char* bitmap_buffer[];
    return bitmap_buffer[active_bitmap_buffer];
}

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char* palette_buffer[];
    return (palette_buffer[active_palette_buffer]+8);
}
#endif
