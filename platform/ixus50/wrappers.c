#include "keyboard.h"
#include "conf.h"
#include "platform.h"
#include "../generic/wrappers.c"

long lens_get_focus_pos()
{
    static long v=MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetFocusLensSubjectDistance():v;
}

long lens_get_focus_pos_from_lens()
{
    static long v=MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetFocusLensSubjectDistanceFromLens():v;
}

long lens_get_target_distance()
{
    static long v=MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetCurrentTargetDistance():v;
}

 
int DoMFLock(void)
{
  if ((mode_get() & MODE_MASK) != MODE_PLAY) {
     int mf_lock;
     get_property_case(PROPCASE_FOCUS_MODE,&mf_lock,sizeof(mf_lock));
     if( mf_lock == 0 ) PostLogicalEventForNotPowerType(levent_id_for_name("PressSw1AndMF"),0);
     return(1);
  }
  return(0);
}
 
int UnlockMF(void)
{
  if ((mode_get() & MODE_MASK) != MODE_PLAY) {
     int mf_lock;
     get_property_case(PROPCASE_FOCUS_MODE,&mf_lock,sizeof(mf_lock));
     if( mf_lock == 1 ) PostLogicalEventForNotPowerType(levent_id_for_name("PressSw1AndMF"),0);
     return(1);
  }
  return(0);
}



