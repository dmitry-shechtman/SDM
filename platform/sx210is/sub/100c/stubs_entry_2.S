#include "stubs_asm.h"
#define NULL_SUB 0xFF810B1C

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                      NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_SUB)

// Additional
NHSTUB(LockAndRefresh,                  0xFFA1ED98)
NHSTUB(MakeAFScan,                      0xFF970F5C)
NHSTUB(UnlockAndRefresh,                0xFFA1EDDC)
# Unconfirmed 
NHSTUB(RefreshUSBMode, 0xFF810B04) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"

NHSTUB(PTM_SetCurrentItem,          0xff99cf68)

