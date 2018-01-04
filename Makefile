####################################################################
# Makefile                                                         #
####################################################################

.SUFFIXES:				# ignore builtin rules
.PHONY: clean all

####################################################################
# Definitions                                                      #
####################################################################

all:
	@echo "Building the libs"
	cd lib; make all
	# cd src; make all
	# cd doc; make doc

clean:
	@echo "Cleaning the libs"
	cd lib; make clean
	# cd src; make clean
	# cd doc; make clean

doc:
	@echo "Generate online documentation"
	cd doc; make doc
