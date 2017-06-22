#include "stubs_asm.h"
#define NULL_SUB 0xFF810B1C

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xFF98AA04)
NHSTUB(RefreshUSBMode, 0xFF810B04) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"

NHSTUB(PTM_SetCurrentItem,          0xff9be0f8)

