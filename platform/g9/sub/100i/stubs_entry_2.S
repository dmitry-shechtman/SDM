#include "stubs_asm.h"
#define NULL_SUB 0xFF810958

// Override stubs_entry.S
NHSTUB(PutInNdFilter,               0xFFA0C578)
NHSTUB(PutOutNdFilter,              0xFFA0C5B0)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xFFA449F8)
NHSTUB(PostLEDMessage,              0xFF848910)
NHSTUB(RefreshUSBMode, 0xff83ec8c)

NHSTUB(PTM_SetCurrentItem,          0xff955d18)

