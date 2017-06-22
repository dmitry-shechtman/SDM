#include "stubs_asm.h"
#define NULL_SUB 0xF8000AE4

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

NHSTUB(MakeDirectory_Fut,           0xF8024794)
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(PTM_SetCurrentItem,          0xf82776ec)

