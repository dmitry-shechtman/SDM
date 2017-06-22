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



#define LED_BRIGHTNESS  200
#define LED_BLUE        8


#define ON 0
#define OFF 1
#define BLINK 2

LED_CONTROL tx1_led;

static void tx1_debug_led()
{
 tx1_led.led_num = 0;
 tx1_led.action = BLINK;
 tx1_led.brightness = 255;
 tx1_led.blink_count = 10;
}
  
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


void set_led(int led, int state)

{
    if (state)
        led_on(led, LED_BRIGHTNESS);
    else
        led_off(led);

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


int get_flash_params_count(void){
 return 111;
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

