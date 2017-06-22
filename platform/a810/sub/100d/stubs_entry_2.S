#include "stubs_asm.h"
#define NULL_SUB 0xFF810B4C

// Override stubs_entry.S
NHSTUB(DeleteFile_Fut,              0xff82fa00)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeDirectory_Fut,           0xff8305a4)

// Additional
NHSTUB(MakeAFScan,                  0xff95f1bc) //Obtained comparing code to a495 100f - Camera makes one AF, then crashes.
//NHSTUB(MakeAFScan,                  0xff831a04) //This is address of DoAFLock
NHSTUB(platformsub_kbd_fetch_data,  0xff856648)
NHSTUB(TurnOnMic,                   0xff856e48)
NHSTUB(TurnOffMic,                  0xff856e74)
NHSTUB(LockAndRefresh,              0xff895b34)
NHSTUB(UnlockAndRefresh,            0xff895b98)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(srand,                       NULL_SUB)  //overridable function
NHSTUB(rand,                        NULL_SUB)  //overridable function
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(PTM_SetCurrentItem,          0xff984c5c)


