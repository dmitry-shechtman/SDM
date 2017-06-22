#3160
PLATFORMID=12660

PLATFORMOS=dryos

MEMBASEADDR=0x1900
RESTARTSTART=0x50000
MEMISOSTART=0xCBC48

ROMBASEADDR=0xFF810000


PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)

NEED_ENCODED_DISKBOOT=1

KEYSYS=d3enc
