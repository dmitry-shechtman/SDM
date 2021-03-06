#include "stubs_asm.h"
#define NULL_SUB 0xffc00b20

// Override stubs_entry.S
NHSTUB(SetScriptMode,               0xffc00f70)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist/aren't found in dryos
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xffd0f1fc)
NHSTUB(TurnOnMic,                   0xffc43c28)
NHSTUB(TurnOffMic,                  0xffc43c54)
NHSTUB(closefastdir,                0xffdeba50)
NHSTUB(platformsub_kbd_fetch_data,  0xffc435cc)
NHSTUB(UnlockAndRefresh, 0xffd7c53c)   
NHSTUB(LockAndRefresh, 0xffd7c4f8) 
NHSTUB(RefreshUSBMode, NULL_SUB) // *** FIND **** Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(PTM_SetCurrentItem,          0xffd2e770)


