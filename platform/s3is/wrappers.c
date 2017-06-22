#include "../generic/wrappers.c"
#include "keyboard.h"
#include "conf.h"
#include "platform.h"

long lens_get_focus_pos()
{
    static long v=65535;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetFocusLensSubjectDistance():v;
}

long lens_get_focus_pos_from_lens()
{
    static long v=65500;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run  || shooting_get_focus_mode())?v=_GetFocusLensSubjectDistanceFromLens():v;
}

long lens_get_target_distance()
{
    static long v=65535;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetCurrentTargetDistance():v;
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

