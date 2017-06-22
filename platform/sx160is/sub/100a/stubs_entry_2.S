#include "stubs_asm.h"
#define NULL_SUB 0xFF810AD4

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                      NULL_SUB)
NHSTUB(kbd_pwr_off,                     NULL_SUB)
NHSTUB(MakeDirectory_Fut,             0xff82be34)  //mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS

// These do not exist
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_SUB)
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"

NHSTUB(PTM_SetCurrentItem,          0xff9a4024)

