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

include config.mk

SUBDIRS=src\
		include

SUBDIRS_CLEAN=$(SUBDIRS:%=%-clean)
SUBDIRS_INSTALL=$(SUBDIRS:%=%-install)

.PHONY: all build clean doc $(SUBDIRS) $(SUBDIRS_CLEAN) $(SUBDIRS_INSTALL)

build: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

all: build doc

doc:
	$(DOXYGEN)

static:
	$(MAKE) -C src static

shared:
	$(MAKE) -C src shared

clean: $(SUBDIRS_CLEAN)
$(SUBDIRS_CLEAN):
	$(MAKE) -C $(@:%-clean=%) clean

install: $(SUBDIRS_INSTALL)
$(SUBDIRS_INSTALL):
	$(MAKE) -C $(@:%-install=%) install
