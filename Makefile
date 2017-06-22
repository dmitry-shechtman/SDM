topdir=./
srcdir=./

include makefile.inc


SUBDIRS=lib platform core loader

all: all-recursive

clean: clean-recursive

distclean: distclean-recursive

fir: version firsub

firsub: all
	@echo \-\> $(BUILD_NUMBER)-$(PLATFORM)-$(PLATFORMSUB).FIR
	cp $(topdir)loader/$(PLATFORM)/main.bin $(topdir)/bin/main.bin
ifndef NOZERO100K
ifeq ($(OSTYPE),Windows)
	zero | dd bs=1k count=100 >> $(topdir)/bin/main.bin 2> $(DEVNULL)
else
	dd if=/dev/zero bs=1k count=100 >> $(topdir)/bin/main.bin 2> $(DEVNULL)
endif
endif

ifdef NEED_ENCODED_DISKBOOT
	@echo encode \-\> DISKBOOT.BIN
	$(ENCODE_DISKBOOT) $(topdir)/bin/main.bin $(topdir)/bin/DISKBOOT.BIN $(NEED_ENCODED_DISKBOOT) 
	rm $(topdir)/bin/main.bin

else
	mv $(topdir)/bin/main.bin $(topdir)/bin/DISKBOOT.BIN
endif
	@echo "**** Firmware created successfully"
	@echo "----------------------------------"
	@echo ""

infoline:
	@echo "**** BUILDING  #$(BUILD_NUMBER) FOR $(PLATFORM)-$(PLATFORMSUB)"

version: FORCE
	echo
	echo "**** Build: $(BUILD_NUMBER)"
	echo
	echo "BUILD_NUMBER := $(BUILD_NUMBER)" > version.inc

FORCE:

firzip: version firzipsub

firzipsub: clean infoline firsub
	@echo \-\> $(topdir)bin/SDM-CA-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER).zip
	rm -f $(topdir)bin/SDM-CA-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER).zip
ifdef PLATFORMOS
ifeq ($(PLATFORMOS),vxworks)
	zip -9j $(topdir)bin/SDM-CA-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER).zip $(topdir)bin/DISKBOOT.BIN  > $(DEVNULL)
 
	rm -f $(topdir)bin/DISKBOOT.BIN  
endif
  ifeq ($(PLATFORMOS),dryos)
	LANG=C echo -e "$(PLATFORM) fw:$(PLATFORMSUB) build:`date -R`" | \
	zip -9j $(topdir)bin/SDM-CA-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER).zip $(topdir)bin/DISKBOOT.BIN  > $(DEVNULL)
	rm -f $(topdir)bin/DISKBOOT.BIN 
 endif
endif

batch-zip: version
	$(MAKE) -s --no-print-directory PLATFORM=a450 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a460 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a470 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a470 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a470 PLATFORMSUB=102c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a480 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a490 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a495 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a495 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a495 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
    
	$(MAKE) -s --no-print-directory PLATFORM=a530 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a540 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a550 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a560 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a570 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a570 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a590 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a590 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a610 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a610 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
    
	$(MAKE) -s --no-print-directory PLATFORM=a620 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a630 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a640 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a650 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a700 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a710 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a720 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a800 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a800 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a810 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
    
	$(MAKE) -s --no-print-directory PLATFORM=a810 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a810 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a1000 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a1000 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2000 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2200 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2200 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2300 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2300 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2300 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
    
	$(MAKE) -s --no-print-directory PLATFORM=a2400 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2400 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2400 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a2500 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a3200 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a3200 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a3400 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a3400 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a3400 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=a4000 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=a4000 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub    
	$(MAKE) -s --no-print-directory PLATFORM=a4000 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100i NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100j NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=g9   PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g9   PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g9   PLATFORMSUB=100i NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g10   PLATFORMSUB=102a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g10   PLATFORMSUB=103b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g10   PLATFORMSUB=104a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g11  PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g11  PLATFORMSUB=100j NO_INC_BUILD=1 firzipsub   
	$(MAKE) -s --no-print-directory PLATFORM=g11  PLATFORMSUB=100l NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g12  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=g12  PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g12  PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g15  PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=g15  PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus50 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus50 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub	
	$(MAKE) -s --no-print-directory PLATFORM=ixus55 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus55 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus55 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus60 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=ixus60 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus65 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus70 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus70 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus70 PLATFORMSUB=102a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus75 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub    
	$(MAKE) -s --no-print-directory PLATFORM=ixus75 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus75 PLATFORMSUB=102a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus80  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus80  PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=ixus85  PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus90  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus90  PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus95  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus100  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus105 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub   
	$(MAKE) -s --no-print-directory PLATFORM=ixus105 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus105 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus115 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub   
	$(MAKE) -s --no-print-directory PLATFORM=ixus115 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=ixus115 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus130 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub 
	$(MAKE) -s --no-print-directory PLATFORM=ixus130 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub 
	$(MAKE) -s --no-print-directory PLATFORM=ixus132 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub 
	$(MAKE) -s --no-print-directory PLATFORM=ixus140 PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub 
	$(MAKE) -s --no-print-directory PLATFORM=ixus700 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus700 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus750 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus750 PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus750 PLATFORMSUB=100h NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=ixus800 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus800 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus850 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub    
	$(MAKE) -s --no-print-directory PLATFORM=ixus860 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus870 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus870 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus870 PLATFORMSUB=102b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus950 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus960 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus970 PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=ixus970 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=ixus980 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub   
	$(MAKE) -s --no-print-directory PLATFORM=ixus980 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s2is PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s2is PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s2is PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s3is PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s5is PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s5is PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s90 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=s90 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s90 PLATFORMSUB=101c NO_INC_BUILD=1 firzipsub   
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100h NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100i NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100k NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=100e NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=102a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s110 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s110 PLATFORMSUB=102b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=s110 PLATFORMSUB=103a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx1 PLATFORMSUB=200h NO_INC_BUILD=1 firzipsub 
	$(MAKE) -s --no-print-directory PLATFORM=sx1 PLATFORMSUB=201a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=102b NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=103a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx20 PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx20 PLATFORMSUB=102b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx20 PLATFORMSUB=102d NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100d NO_INC_BUILD=1 firzipsub    
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100i NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx50hs PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx50hs PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=sx100is  PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx100is  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx110is  PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx120is  PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx130is  PLATFORMSUB=101c NO_INC_BUILD=1 firzipsub    
	$(MAKE) -s --no-print-directory PLATFORM=sx130is  PLATFORMSUB=101f NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx150is  PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx160is  PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx170is  PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx170is  PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=sx200is  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx210is  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx220hs  PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx220hs  PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx220hs  PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx230hs  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx230hs  PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub    
	$(MAKE) -s --no-print-directory PLATFORM=sx230hs  PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx240hs  PLATFORMSUB=100a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx240hs  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub

	$(MAKE) -s --no-print-directory PLATFORM=sx240hs  PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx260hs  PLATFORMSUB=100b NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx260hs  PLATFORMSUB=100c NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=sx260hs  PLATFORMSUB=101a NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=tx1 PLATFORMSUB=100g NO_INC_BUILD=1 firzipsub
	$(MAKE) -s --no-print-directory PLATFORM=tx1 PLATFORMSUB=101b NO_INC_BUILD=1 firzipsub

batch-clean:
	$(MAKE) -s --no-print-directory PLATFORM=a450 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a460 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a470 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a470 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a470 PLATFORMSUB=102c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a480 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a490 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a495 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a495 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a495 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a530 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a540 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a550 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a560 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a570 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a570 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a590 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a590 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a610 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a610 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a620 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a630 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a640 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a650 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a700 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a710 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a720 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a800 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a800 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a810 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a810 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a810 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a1000 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a1000 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2000 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2200 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2200 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2300 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2300 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2300 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2400 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2400 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2400 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a2500 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a3200 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a3200 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a3400 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a3400 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a3400 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a4000 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a4000 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=a4000 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=100g NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g1x   PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100g NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100i NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g7   PLATFORMSUB=100j NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g9   PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g9   PLATFORMSUB=100g NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g9   PLATFORMSUB=100i NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g10  PLATFORMSUB=102a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g10  PLATFORMSUB=103b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g10  PLATFORMSUB=104a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g11  PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g11  PLATFORMSUB=100j NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g11  PLATFORMSUB=100l NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g12  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g12  PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g12  PLATFORMSUB=100g NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g15  PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=g15  PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus50 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus50 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus55 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus55 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus55 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus60 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus60 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus65 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus70 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus70 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus70 PLATFORMSUB=102a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus75 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus75 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus75 PLATFORMSUB=102a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus80 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus80  PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus85  PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus90  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus90  PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus95  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus100  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus105  PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus105  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus105  PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus115 PLATFORMSUB=100c NO_INC_BUILD=1 clean   
	$(MAKE) -s --no-print-directory PLATFORM=ixus115 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus115 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus130 PLATFORMSUB=100a NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=ixus130 PLATFORMSUB=100c NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=ixus132  PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus140 PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus700 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus700 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus750 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus750 PLATFORMSUB=100g NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus750 PLATFORMSUB=100h NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus800 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus800 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus850 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus860 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus870 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus870 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus870 PLATFORMSUB=102b NO_INC_BUILD=1 clean
#	$(MAKE) -s --no-print-directory PLATFORM=ixus900 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus950 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus960 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus970 PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus970 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus980 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=ixus980 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s2is PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s2is PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s2is PLATFORMSUB=100g NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s3is PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s5is PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s5is PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s90 PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s90 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s90 PLATFORMSUB=101c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100h NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100i NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s95 PLATFORMSUB=100k NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=100d NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=100e NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s100 PLATFORMSUB=102a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s110 PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s110 PLATFORMSUB=102b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=s110 PLATFORMSUB=103a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx1 PLATFORMSUB=200h NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx1 PLATFORMSUB=201a NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=100c NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=101a NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=101b NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=102b NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx10 PLATFORMSUB=103a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx20 PLATFORMSUB=100f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx20 PLATFORMSUB=102b NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx20 PLATFORMSUB=102d NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100d NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100f NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100g NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx40hs PLATFORMSUB=100i NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx50hs PLATFORMSUB=100b NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx50hs PLATFORMSUB=100c NO_INC_BUILD=1 clean 
	$(MAKE) -s --no-print-directory PLATFORM=sx100is  PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx100is  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx110is  PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx120is  PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx130is  PLATFORMSUB=101c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx130is  PLATFORMSUB=101f NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx150is  PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx160is  PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx170is  PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx170is  PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx200is  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx210is  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx220hs  PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx220hs  PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx220hs  PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx230hs  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx230hs  PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx230hs  PLATFORMSUB=101b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx240hs  PLATFORMSUB=100a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx240hs  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx240hs  PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx260hs  PLATFORMSUB=100b NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx260hs  PLATFORMSUB=100c NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=sx260hs  PLATFORMSUB=101a NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=tx1 PLATFORMSUB=100g NO_INC_BUILD=1 clean
	$(MAKE) -s --no-print-directory PLATFORM=tx1 PLATFORMSUB=101b NO_INC_BUILD=1 clean


 

