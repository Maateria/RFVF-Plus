# Builds the executables in tools/. The Makefile includes this file, and also runs it alone
# (make -f make_tools.mk) before every ROM build, which is much cheaper than re-reading the whole Makefile.

MAKEFLAGS += --no-print-directory

TOOLDIRS := $(filter-out tools/agbcc tools/binutils tools/analyze_source tools/poryscript tools/wav2agb tools/hoenn_import,$(wildcard tools/*))

.PHONY: tools clean-tools $(TOOLDIRS)

tools: $(TOOLDIRS)

$(TOOLDIRS):
	@$(MAKE) -C $@

clean-tools:
	@$(foreach tooldir,$(TOOLDIRS),$(MAKE) clean -C $(tooldir);)
