#include "platform.h"
#include "lolevel.h"

void shutdown()
{
    volatile long *p = (void*)0xc022002c;
        
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x46;

    while(1);
}




#define LED_BRIGHTNESS  200
#define LED_BLUE        8

  
static void led_on(const int led, const int brightness)
{
    if (led < 4 || led > 10 || led == 6) return;
    static void* addr;
    addr = led_table + (led * 0x40);
    _UniqueLedOn(addr,brightness);
}
 
static void led_off(const int led)
{
    if (led < 4 || led > 10 || led == 6) return;
    static void* addr;
    addr = led_table + (led * 0x40);
    _UniqueLedOff(addr);
}

void debug_led(int state)
{
    if (state)
        led_on(LED_BLUE, LED_BRIGHTNESS);
    else
        led_off(LED_BLUE);
}                  


void ubasic_set_led(int led, int state, int bright)
{
	if (state) {
		if (bright > LED_BRIGHTNESS) bright = LED_BRIGHTNESS;
        led_on(led, bright);
	}
    else
        led_off(led);
}

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



/*
void newled(int state)
{
    if (state)
        led_on(LED_ORANGE, LED_BRIGHTNESS);
    else
        led_off(LED_ORANGE);
}

void af_led(int state)
{
    if (state)
        led_on(LED_AF_BEAM, LED_BRIGHTNESS);
    else
        led_off(LED_AF_BEAM);
}

void orange_led(int state)
{
    if (state)
        led_on(LED_ORANGE, LED_BRIGHTNESS);
    else
        led_off(LED_ORANGE);
}

void green_led(int state)
{
    if (state)
        led_on(LED_GREEN, LED_BRIGHTNESS);
    else
        led_off(LED_GREEN);
}

void yellow_led(int state)
{
    if (state)
        led_on(LED_YELLOW, LED_BRIGHTNESS);
    else
        led_off(LED_YELLOW);
}

void timer_led(int state)
{
    if (state)
        led_on(LED_TIMER, LED_BRIGHTNESS);
    else
        led_off(LED_TIMER);
}

*/

