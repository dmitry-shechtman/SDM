#include "../generic/lib.c"

int get_flash_params_count(void){ // from 710 added 
 return 108; //seems to be ok
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

