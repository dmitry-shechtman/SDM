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

void ubasic_set_led(int led, int state, int bright)
{
 struct led_control led_c;
 char convert_table[11]={0,1,2,3,0,2,3,1,8,10,10};  // s3 to a710 convert table

 led_c.led_num=convert_table[led%11];
 led_c.action=state<=1 ? !state : state;
 led_c.brightness=bright;
 led_c.blink_count=255;
 _PostLEDMessage(&led_c);
}

 
 //--------------------------------------------------
 // DoMFLock : use _MFOn/_MFOff  or  _PT_MFOn/_PT_MFOff  or _SS_MFOn/_SS_MFOff if defined in stubs_entry.S
 //            otherwise use PostLogicalEventForNotPowerType(levent_id_for_name(PressSW1andMF),0); (see sx500hs for an example)
 
int DoMFLock(void)
{
  if ((mode_get() & MODE_MASK) != MODE_PLAY) {
     _MFOn();
     return(1);
  }
  return(0);
}
 
int UnlockMF(void)
{
  if ((mode_get() & MODE_MASK) != MODE_PLAY) {
     _MFOff();
     return(1);
  }
  return(0);
}
