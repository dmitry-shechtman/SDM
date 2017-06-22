#include "stubs_asm.h"
#define NULL_SUB 0xFF8118C0

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      NULL_SUB)
NHSTUB(ExitFromCompensationEVF,     NULL_SUB)
NHSTUB(VbattGet,                    0xFF82c54c)
NHSTUB(WriteSDCard,                 0xFF87E9CC)
NHSTUB(free,                        0xFFAD6680)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UIFS_WriteFirmInfoToFile,NULL_SUB)
// Additional
NHSTUB(SetScriptMode,               0xFF95E2B4)
NHSTUB(UniqueLedOff,                0xFF82df64)
NHSTUB(UniqueLedOn,                 0xFF82df20)
NHSTUB(RefreshUSBMode,                NULL_SUB)  // ****** check ********

NHSTUB(PTM_SetCurrentItem,          0xff96373c)

