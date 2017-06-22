#include "../generic/lib.c"

#include "lolevel.h"

void switch_mode(int mode) { 
  if ( mode == 0 ) {
   _PostLogicalEventForNotPowerType(0x1003, 0); //PressPBButton
  } 
  else if ( mode == 1 ) {
    _PostLogicalEventForNotPowerType(0x1001, 0); //PressRecButton
  } 
}
