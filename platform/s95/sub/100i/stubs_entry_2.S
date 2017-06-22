#include "stubs_asm.h"
#define NULL_SUB 0xFF8391E0

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xff9896c0)
NHSTUB(closefastdir,                0xffad3f98)
NHSTUB(RefreshUSBMode, 0xFF8556A4) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(PTM_SetCurrentItem,          0xff9bb2b8)


