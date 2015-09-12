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
