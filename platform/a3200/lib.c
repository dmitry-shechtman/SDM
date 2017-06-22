#include "platform.h"
#include "lolevel.h"

void shutdown()
{
	volatile long *p = (void*)0xC02200F4;

	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");

	*p = 0x44;  // power off.

	while(1);
}

long vid_get_bitmap_width(){ return 360; }
long vid_get_bitmap_screen_width() { return 360; }
long vid_get_bitmap_height(){ return 240; }
long vid_get_bitmap_screen_height() { return 240; }
long vid_get_bitmap_buffer_width() { return 720; }
long vid_get_bitmap_buffer_height() { return 240; }

#include "lolevel.h"

void switch_mode(int mode)
{
    if ( mode == 0 ) 
    {
     _Rec2PB();
     _set_control_event(0x80000902); // 0x10A5 ConnectUSBCable
    } 
    else if ( mode == 1 ) 
    {
     _set_control_event(0x902); // 0x10A6 DisconnectUSBCable
     _PB2Rec();
    } 
}


void ubasic_set_led(int led, int state, int bright) 
{
 static char led_table[7]={0,0,0,0,0,9,0};
 _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}

#define LED_PR 0xC02200F0


void debug_led(int state)
{
 *(int*)LED_PR=state ? 0x46 : 0x44;
}


int get_flash_params_count(void){
 return 0xa0;	// Found @0xff9941e4
}

int vid_get_viewport_width()
{
	return 360;
}

long vid_get_viewport_height()
{
	return 240;
}

void vid_bitmap_refresh() {
	
	extern int full_screen_refresh;
	extern void _ScreenUnlock();
	extern void _ScreenLock();

	full_screen_refresh |= 3;
	_ScreenLock();
	_ScreenUnlock();
}
