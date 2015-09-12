
include ../config.mk

HEADERS=myr/compiler.h\
		myr/err.h\
		myr/memory.h\
		myr/progname.h\
		myr/progname_main.h

.PHONY: all clean install

all:

clean:

install:
	$(INSTALL) -m 0755 -d $(DESTDIR)$(PREFIX)/include
	$(INSTALL) -m 0644 $(HEADERS) $(DESTDIR)$(PREFIX)/include
