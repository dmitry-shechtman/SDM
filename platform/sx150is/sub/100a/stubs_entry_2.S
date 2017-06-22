#include "stubs_asm.h"
#define NULL_STUB 0xFF810B24

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                      NULL_STUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_STUB)

// Additional
NHSTUB(LockAndRefresh,                  0xFF8B32C4)
NHSTUB(UnlockAndRefresh,                0xFF8B1D9C)
NHSTUB(UpdateMBROnFlash,                0xFF876CB0)
NHSTUB(RefreshUSBMode, NULL_STUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(PTM_SetCurrentItem,          0xff9afb98)


