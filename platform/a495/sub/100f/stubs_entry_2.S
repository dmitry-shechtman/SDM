#include "stubs_asm.h"
#define NULL_SUB 0xFFC00B20

// Override stubs_entry.S
NHSTUB(SetScriptMode,               0xFFC00F70)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xFFD0F2AC)
NHSTUB(TurnOnMic,                   0xFFC43C28)
NHSTUB(TurnOffMic,                  0xFFC43C54)
NHSTUB(closefastdir,                0xFFDEBA54)
NHSTUB(platformsub_kbd_fetch_data,  0xFFC435CC)
NHSTUB(LockAndRefresh,              0xFFD7C5A8)
NHSTUB(UnlockAndRefresh,            0xFFD7C5EC)
NHSTUB(RefreshUSBMode, 0xFFC00B20) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(PTM_SetCurrentItem,          0xffd2e820)



