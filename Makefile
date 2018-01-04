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
	mkdir -p libdir
	cd lib; make all
	# cd src; make all

clean:
	@echo "Cleaning the libs"
	cd lib; make clean
	# cd src; make clean
