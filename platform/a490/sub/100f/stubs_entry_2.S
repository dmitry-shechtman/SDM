#include "stubs_asm.h"
#define NULL_SUB 0xFFC00B20

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xFFD0F178)
NHSTUB(TurnOnMic,                   0xFFC43C30)
NHSTUB(TurnOffMic,                  0xFFC43C5C)
NHSTUB(closefastdir,                0xFFDE8CA0) // Same as closedir
NHSTUB(platformsub_kbd_fetch_data,  0xFFC435D4)
NHSTUB(RefreshUSBMode, 0xFFC00B20) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(UnlockAndRefresh, 0xFFD7B090)			// "Window.c"
NHSTUB(LockAndRefresh, 0xFFD7B04C)				// "Window.c"


NHSTUB(PTM_SetCurrentItem,          0xffd2e664)

