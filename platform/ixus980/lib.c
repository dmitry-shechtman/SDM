#include "platform.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
	_ScreenLock();
    _RefreshPhysicalScreen(1);
}

void shutdown()
{
    volatile long *p = (void*)0xc022001C; //from task_by (not really complete)
        
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x44;

    while(1);
}


#define LED_PR 0xc02200BC

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

int get_flash_params_count(void){
 return 120; //? _sub_FF962AB8__PropertyTableManagerCore_c__6, similar to s5is
}
/*
//based on SX10, values found by experiment
void ubasic_set_led(int led, int state, int bright) {
 static char led_table[]={0, //green
                          1, //orange, right
						  2,//yellow, left
						  3,//power
						  //4,5,6,7,
						  8,// blue
						  9 //af
						  };
 if((unsigned)led < sizeof(led_table))
  _LEDDrive(led_table[led], state<=1 ? !state : state);
// _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}
*/
void ubasic_set_led(int led, int state, int bright)
{
  static char led_table[7]={0,2,7,8,8,9,9};
 if(led >=4 && led <= 10)
  _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}

// from sx10
void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x874, 2);  //RotateJogDialRight
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x875, 2);  //RotateJogDialLeft
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

