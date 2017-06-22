#include "stubs_asm.h"
#define NULL_SUB 0xFF810B24

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// Additional
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFAA164C)
NHSTUB(MakeAFScan,                  0xFF96CEC4)
NHSTUB(platformsub_kbd_fetch_data,  0xFF860268)
NHSTUB(TurnOnMic,                   0xFF8608E8)
NHSTUB(TurnOffMic,                  0xFF860914)
NHSTUB(TurnOffE1,                   0xff83bc20)
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(PTM_SetCurrentItem,          0xff9937e4)


