#include "platform.h"

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


#define LED_PR 0xC02200CC

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}



#define LED_AF 0xc0223030

void ubasic_set_led(int led, int state, int bright)
{
                                             // changeset 479
  int leds[] = {106,12,0,103,0,12132,12132}; //  green | yellow | not used | orange | blue | af beam | timer 
  if(led < 4 || led > 10 || led == 6) return;
  volatile long *p=(void*)LED_PR + leds[led-4];
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;

}

/*
void af_led(int state)
{


    volatile long *p=(void*)LED_AF;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;

}

#define LED_ORANGE 0xc0220133

void newled(int state)
{

    volatile long *p=(void*)LED_ORANGE;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;

}

void orange_led(int state)
{

    volatile long *p=(void*)LED_ORANGE;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;

}

#define LED_GREEN 0xc0220136

void green_led(int state)
{

    volatile long *p=(void*)LED_GREEN;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;

}
#define LED_YELLOW 0xc02200D8

void yellow_led(int state)
{

}


void timer_led(int state)
{
debug_led(state);
}
*/


int get_flash_params_count(void){
 return 114; //???
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
