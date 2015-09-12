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

INCLUDEDIR=../include
CFLAGS+=-I$(INCLUDEDIR)

TARGET=libmyrcutil.a

.PHONY: all clean
.SUFFIXES: .c .o

all: $(TARGET)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)

$(TARGET): $(OBJECTS) Makefile
	$(RM) $@
	$(AR) cr $@ $(OBJECTS)
	$(RANLIB) $@

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

err.o: err.c $(INCLUDEDIR)/myr/err.h $(INCLUDEDIR)/myr/compiler.h $(INCLUDEDIR)/myr/progname.h Makefile
progname.o: progname.c $(INCLUDEDIR)/myr/progname.h $(INCLUDEDIR)/myr/progname_main.h Makefile
