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

HEADERS=myr/compiler.h\
		myr/err.h\
		myr/memory.h\
		myr/progname.h\
		myr/progname_main.h

HEADERS_inline=myr/inline/err.h

.PHONY: all clean install

all:

clean:

install:
	$(INSTALL) -m 0755 -d $(DESTDIR)$(PREFIX)/include/myr
	$(INSTALL) -m 0644 $(HEADERS) $(DESTDIR)$(PREFIX)/include/myr
	$(INSTALL) -m 0755 -d $(DESTDIR)$(PREFIX)/include/myr/inline
	$(INSTALL) -m 0644 $(HEADERS_inline) $(DESTDIR)$(PREFIX)/include/myr/inline
