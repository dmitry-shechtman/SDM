#include "../generic/wrappers.c"

long lens_get_focus_pos()
{
 return _GetFocusLensSubjectDistance();    
}

long lens_get_focus_pos_from_lens()
{
 return _GetFocusLensSubjectDistanceFromLens(); 
}


long lens_get_target_distance()
{
    return _GetCurrentTargetDistance();
}

 #define AF 0xC02200c0    // AF-Beam (red)
 #define DP 0xC02200c4    // direct-print (blue)
 #define OR 0xC02200c8    // orange state-led (bi-state with green)
 #define GR 0xC02200cc    // green state-led (bi-state with orange)
 #define YE 0xC02200d0    // Yellow state-led

void ubasic_set_led(int led, int state, int bright)
{ 
        struct led_control led_c; 
        char convert_table[11]={0,1,2,3,0,2,3,1,8,10,10};  // s3 to a710 (and a720) convert table

        //char convert_table[6]={0,1,2,3,8,10};  // Test a720, values 0-5 are valid

        // 0 gr  
        // 1 red 
        // 2 yel 
        // 3 pw  
        // 8 dp  
        // 9 af  

        led_c.led_num=convert_table[led%11]; 
        led_c.action=state<=1 ? !state : state; 
        led_c.brightness=bright; 
        led_c.blink_count=255; 
        _PostLEDMessage(&led_c); 
} 

int DoMFLock(void)
{
  if ((mode_get() & MODE_MASK) != MODE_PLAY) {
     _PT_MFOn();
     return(1);
  }
  return(0);
}
 
int UnlockMF(void)
{
  if ((mode_get() & MODE_MASK) != MODE_PLAY) {
     _PT_MFOff();
     return(1);
  }
  return(0);
}


