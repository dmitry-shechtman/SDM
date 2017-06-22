#include "platform.h"
#include "lolevel.h"

void shutdown()
{
    volatile long *p = (void*)0xc02200a0;

    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");

    *p = 0x44;

    while(1);
}

#define LED_AF    0xC02200C0 // AutoFocus 9
#define LED_PR	0xc02200C4 // 8
#define LED_RED   0xc02200C8 // 7
#define LED_GRN	0xc02200CC // 4
#define LED_PWR	0xc02200D0 // 10 ?


void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

// _LedDrive function not found, try this
void ubasic_set_led(int led, int state, int bright)
{

  int leds[] = {12,4,4,8,4,0,16};
  if(led < 4 || led > 10 || led == 6) return;
  volatile long *p=(void*)LED_AF + leds[led-4];
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}


int get_flash_params_count(void){
 return 114;
}

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
