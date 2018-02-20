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
	cd libsrv; make all
	cd lib7seg; make all
	cd libadc; make all
	cd libsensconv; make all
	cd libtmr; make all
	cd libbulb; make all
	cd libfan; make all
	cd libspi; make all
	cd libuart; make all
clean:
	@echo "Cleaning the libs"
	cd libsrv; make clean
	cd lib7seg; make clean
	cd libadc; make clean
	cd libsensconv; make clean
	cd libtmr; make clean
	cd libbulb; make clean
	cd libfan; make clean
	cd libspi; make clean
	cd libuart; make clean
	rm -rf libdir
