#include "stubs_asm.h"

#define NULLSUB 0xFF810B24

// Not found
NHSTUB(kbd_pwr_on,          		NULLSUB)

//Additional
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFA9B6C0)
NHSTUB(MakeAFScan,					0xFF8DA094)
NHSTUB(platformsub_kbd_fetch_data,	0xFF8602B4)
NHSTUB(TurnOnMic,                   0xFF860934)
NHSTUB(TurnOffMic,                  0xFF860960)
NHSTUB(RefreshUSBMode, NULLSUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(LockAndRefresh,				0xFF8A46A0)
NHSTUB(UnlockAndRefresh,			0xFF8A4704)


NHSTUB(PTM_SetCurrentItem,          0xff98dbac)

