# This file is included from */sub/*/Makefile
#

include $(topdir)makefile.inc

CFLAGS+=-DLOW_LEVEL

all: libplatformsub.a

TARGET_PRIMARY = PRIMARY.BIN

#OBJS= should be defined in */sub/*/Makefile

libplatformsub.a: $(OBJS)

clean:
	rm -f $(OBJS) libplatformsub.a 

distclean: clean
	rm -f stubs_entry.S stubs_auto.S
	rm -rf .dep

include $(topdir)bottom.inc
