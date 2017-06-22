#include "keyboard.h"
#include "conf.h"
#include "platform.h"
#include "../generic/wrappers.c"

long lens_get_focus_pos()
{
    static long v=65535;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetFocusLensSubjectDistance():v;

}

long lens_get_focus_pos_from_lens()
{
    static long v=65500;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetFocusLensSubjectDistanceFromLens():v;
}

long lens_get_target_distance()
{
    static long v=65535;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || state_kbd_script_run)?v=_GetCurrentTargetDistance():v;

}

int DoMFLock(void)
{
  return(0);
 
}
 
int UnlockMF(void)
{
  return(0);
 
}

