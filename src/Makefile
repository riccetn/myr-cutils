#
# Myr C Utils library
#
# Written 2015 by Rickard Närström <rickard@narstrom.se>
#
# To the extent possible under law, the author(s) have dedicated all copyright
# and related and neighboring rights to this software to the public domain worldwide.
# This software is distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain Dedication along
# with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

include ../config.mk

OBJECTS=err.o\
		progname.o

PIC_OBJECTS=$(OBJECTS:%.o=%.pic)

STATIC=libmyrcutil.a
SHARED=libmyrcutil.so.0.0.1
SONAME=libmyrcutil.so.0
LIBNAME=libmyrcutil.so

INCLUDEDIR=../include
CFLAGS+=-I$(INCLUDEDIR)

.PHONY: all clean install
.SUFFIXES: .c .o .pic

all: static shared

shared: $(SHARED)

static: $(STATIC)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(PIC_OBJECTS)
	$(RM) $(STATIC) $(SHARED)

install: $(STATIC) $(SHARED)
	$(INSTALL) -m 0755 -d $(DESTDIR)$(LIBDIR)
	$(INSTALL) -m 0644 $(STATIC) $(DESTDIR)$(LIBDIR)
	$(INSTALL) -m 0755 $(SHARED) $(DESTDIR)$(LIBDIR)
	$(LN) $(SHARED) $(DESTDIR)$(LIBDIR)/$(SONAME)
	$(LN) $(SHARED) $(DESTDIR)$(LIBDIR)/$(LIBNAME)

$(STATIC): $(OBJECTS) Makefile
	$(RM) $@
	$(AR) cr $@ $(OBJECTS)
	$(RANLIB) $@

$(SHARED): $(PIC_OBJECTS) Makefile
	$(CCLD) -shared $(LDFLAGS) -Wl,-soname=$(SONAME) -o $@ $(PIC_OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.c.pic:
	$(CC) -fPIC $(CFLAGS) -c -o $@ $<

err.o err.pic: err.c $(INCLUDEDIR)/myr/err.h $(INCLUDEDIR)/myr/compiler.h $(INCLUDEDIR)/myr/progname.h Makefile
progname.o progname.pic: progname.c $(INCLUDEDIR)/myr/progname.h $(INCLUDEDIR)/myr/progname_main.h Makefile
