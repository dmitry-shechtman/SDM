#include "platform.h"
#include "lolevel.h"

void shutdown()
{
    volatile long *p = (void*)0xC0220240; // G11
    
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x44;

    while(1);
}


#define LED_PR 0xC0220128 //EV LED

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}


void ubasic_set_led(int led, int state, int bright)
{
  static char led_table[7]={0,1,2,3,14,9,15};
 if(led >=4 && led <= 10)
  _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}


/*
// this version to Mike Mikkelson

#define LED_BASE 0xc0220000

void ubasic_set_led(int led, int state, int bright)
{
 int leds[] = {296,296,296,300,300,12336,300};
  if(led < 4 || led > 10 || led == 6) return;
  volatile long *p=(void*)LED_BASE + leds[led-4];
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}
*/

int get_flash_params_count(void){
 return 130; // ERR99 ToDo: Is this the correct G11 value?
}

void vid_bitmap_refresh()
{
	 extern int enabled_refresh_physical_screen; // screen lock counter
	 extern void _ScreenUnlock();

	 _ScreenLock();
	  enabled_refresh_physical_screen = 1;
	 _ScreenUnlock();
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
	return 2;               // G11 viewport is 480 pixels high
}


