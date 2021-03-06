#include "platform.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
 extern int enabled_refresh_physical_screen;
 enabled_refresh_physical_screen=1;
 _RefreshPhysicalScreen(1);
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
	
	*p = 0x44;  //power off.
	
	while(1);
}

#define LED_PR 0xC0220060

void debug_led(int state)
{
  _LEDDrive(7, state<=1 ? !state : state);
}


void ubasic_set_led(int led, int state, int bright) {
 static char led_table[5]={4,5,7,8,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}


int get_flash_params_count(void){
 return 120; 
}

void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x874, 1);  //RotateJogDialRight CS825
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x875, 1);  //RotateJogDialLeft CS825
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

