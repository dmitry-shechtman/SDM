#include "stubs_asm.h"

#define NULL_SUB 0xFFC00B1C

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeAFScan,                  0xFFD1E738)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

NHSTUB(GetDrive_FreeClusters, 0xffc55b78)
NHSTUB(RefreshUSBMode, 0xFFC3B4C4) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(platformsub_kbd_fetch_data, 0xffc47dec)


NHSTUB(PTM_SetCurrentItem,          0xffd3f5b4)

