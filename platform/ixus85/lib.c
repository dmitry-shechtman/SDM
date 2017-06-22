#include "platform.h"
#include "lolevel.h"
#include "leds.h"


long vid_get_bitmap_width(){ return 360; }
long vid_get_bitmap_screen_width() { return 360; }
long vid_get_bitmap_height(){ return 240; }
long vid_get_bitmap_screen_height() { return 240; }
long vid_get_bitmap_buffer_width() { return 360; }
long vid_get_bitmap_buffer_height() { return 240; }

void shutdown()
{
	// 0xC0220000+0x1C @ FF829C24
	volatile long *p = (void*)0xC022001C;

	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");

	*p = 0x44;

	while(1);
}

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

// 0x73 @ FF95D974
int get_flash_params_count(void) { return 115; }

void debug_led(int state)
{
	*(int*)LED_PR = state ? 0x46 : 0x44;
}

void ubasic_set_led(int led, int state, int bright) 
{
 static char led_table[7]={4,4,5,7,8,9,5};
 _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}


