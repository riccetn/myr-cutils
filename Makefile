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

SUBDIRS=src\
		include

SUBDIRS_CLEAN=$(SUBDIRS:%=%-clean)
SUBDIRS_INSTALL=$(SUBDIRS:%=%-install)

.PHONY: all clean $(SUBDIRS) $(SUBDIRS_CLEAN) $(SUBDIRS_INSTALL)

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

clean: $(SUBDIRS_CLEAN)
$(SUBDIRS_CLEAN):
	$(MAKE) -C $(@:%-clean=%) clean

install: $(SUBDIRS_INSTALL)
$(SUBDIRS_INSTALL):
	$(MAKE) -C $(@:%-install=%) install
