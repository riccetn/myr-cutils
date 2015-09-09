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

CC=clang
CCLD=clang
RM=rm -f
AR=ar
RANLIB=ranlib

CFLAGS=-Weverything -Werror -g

OBJECTS=err.o\
		progname.o

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

err.o: err.c err.h compiler.h progname.h Makefile
progname.o: progname.c progname.h progname_main.h Makefile
