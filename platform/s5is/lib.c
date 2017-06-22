#include "platform.h"
#include "lolevel.h"

#define LED_PR 0xC02200D4

void shutdown()
{
	volatile long *p = (void*)LED_PR;       // SD-write led on S5
	
	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");
	
	*p = 0x44;  // led off.
	
	while(1);
}

#define LED_AF_BEAM     5 // Does not seem to accept any value.
#define LED_AF 0xC02200E0
#define LED_BRIGHTNESS  200
#define LED_BLUE        4
#define LED_YELLOW      2 // LED_GREEN + LED_ORANGE

static void led_on(const int led, const int brightness)
{
	if (led < 0 || led > 6 || led == LED_YELLOW) return;
	static void* addr;
	if(led == LED_AF_BEAM) { // does not accept anything (so it seems), bypass
		*((long *) LED_AF) = 0x46;
	} else {
		addr = led_table + (led * 0x40) + 0x100;
		_UniqueLedOn(addr,brightness);
	}
}
 
static void led_off(const int led)
{
	if (led < 0 || led > 6 || led == LED_YELLOW) return;
	static void* addr;
	if(led == LED_AF_BEAM) { // does not accept anything (so it seems), bypass
		*((long *) LED_AF) = 0x44;
	} else {
		addr = led_table + (led * 0x40) + 0x100;
		_UniqueLedOff(addr);
	}
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
	if (state) 
           {
		if (bright > LED_BRIGHTNESS) bright = LED_BRIGHTNESS;
            led_on(led, bright);
            }
            else led_off(led);
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
void af_led(int state)
{

}

// #define LED_ORANGE 0xc0220088

void newled(int state)
{

}

void orange_led(int state)
{

}

// #define LED_GREEN 0xc022008C

void green_led(int state)
{

}
// #define LED_YELLOW 0xc0220090

void yellow_led(int state)
{

}


void timer_led(int state)
{
debug_led(state);
}
*/

int get_flash_params_count(void){
	return 111; // Found at ROM:FF972F9C (S5IS 1.01b)
}
