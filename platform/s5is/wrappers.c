#include "../generic/wrappers.c"
#include "keyboard.h"

long lens_get_focus_pos()
{
    static long v=MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run  || shooting_get_focus_mode())?v=_GetFocusLensSubjectDistance():v;
}

long lens_get_focus_pos_from_lens()
{
    static long v=MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run  || shooting_get_focus_mode())?v=_GetFocusLensSubjectDistanceFromLens():v;
}

long lens_get_target_distance()
{
    static long v=MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run  || shooting_get_focus_mode())?v=_GetCurrentTargetDistance():v;
}
 
 
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
