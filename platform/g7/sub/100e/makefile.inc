#0x3125
PLATFORMID=12581

PLATFORMOS=vxworks
CAM_MULTIPART=1
MEMBASEADDR=0x1900
RESTARTSTART=0x50000
MEMISOSTART=0xA7910

ROMBASEADDR=0xff810000

TARGET_PRIMARY=$(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/PRIMARY.BIN

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)
