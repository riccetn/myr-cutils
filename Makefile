SUBDIRS=src\
		include

CLEAN_SUBDIRS=$(SUBDIRS:%=%-clean)

.PHONY: all clean $(SUBDIRS) $(CLEAN_SUBDIRS)

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

clean: $(CLEAN_SUBDIRS)
$(CLEAN_SUBDIRS):
	$(MAKE) -C $(@:%-clean=%) clean
