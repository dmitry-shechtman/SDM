#include "stubs_asm.h"

#define NULL_SUB 0xFFC00B1C

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeAFScan,                  0xFFD1E738)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(RefreshUSBMode, 0xffc3b4c4) 
NHSTUB(platformsub_kbd_fetch_data, 0xffc47dec)



NHSTUB(PTM_SetCurrentItem,          0xffd3f5b4)

