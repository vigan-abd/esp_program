####################################################################
# Makefile                                                         #
####################################################################

OUTDIR = documentation

.SUFFIXES:				# ignore builtin rules
.PHONY: clean doc

####################################################################
# Definitions                                                      #
####################################################################

all:
	@echo "Generate online documentation"
	mkdir -p $(OUTDIR)
	doxygen esp_program.dox
clean:
	@echo "Cleaning the libs"
	rm -rf $(OUTDIR)

doc:
	@echo "Generate online documentation"
	mkdir -p $(OUTDIR)
	doxygen esp_program.dox	
