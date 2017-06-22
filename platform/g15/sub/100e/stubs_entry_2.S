#include "stubs_asm.h"
#define NULL_SUB 0xFF022184

NHSTUB(kbd_pwr_off,						NULL_SUB)
NHSTUB(kbd_pwr_on,						NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent,		NULL_SUB)

NHSTUB(MakeDirectory_Fut,               0xff01d000)
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"

NHSTUB(PTM_SetCurrentItem,          0xff1f5bc8)

