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

#define LED_PR 0xc02200C4

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}


#define LED_BASE 0xc02200C0

void ubasic_set_led(int led, int state, int brightness)

{
  int leds[] = {12,16,4,8,4,0,4};
  if(led < 4 || led > 10 || led == 6) return;
  volatile long *p=(void*)LED_BASE + leds[led-4];
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

/*
void af_led(int state)
{
    volatile long *p=(void*)LED_BASE;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

#define LED_ORANGE 0xc02200C8

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

#define LED_GREEN 0xc02200CC

void green_led(int state)
{
    volatile long *p=(void*)LED_GREEN;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}
#define LED_YELLOW 0xc02200D0

void yellow_led(int state)
{
    volatile long *p=(void*)LED_YELLOW;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}



void timer_led(int state)
{
debug_led(state);
}
*/

#include "lolevel.h"

void switch_mode(int mode)
{
  if ( mode == 0 )
  {
    PostLogicalEventForNotPowerType(0x1003,0);
  } else if ( mode == 1 )
  {
   PostLogicalEventForNotPowerType(0x1001,0);
  }
}

