#
# Myr C Utils library
#
# Written 2015 by Rickard Närström <rickard@narstrom.se>
#
# This is free and unencumbered software released into the public domain.
#
# Anyone is free to copy, modify, publish, use, compile, sell, or
# distribute this software, either in source code form or as a compiled
# binary, for any purpose, commercial or non-commercial, and by any
# means.
#
# In jurisdictions that recognize copyright laws, the author or authors
# of this software dedicate any and all copyright interest in the
# software to the public domain. We make this dedication for the benefit
# of the public at large and to the detriment of our heirs and
# successors. We intend this dedication to be an overt act of
# relinquishment in perpetuity of all present and future rights to this
# software under copyright law.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.

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
