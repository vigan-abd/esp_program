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
	cd libadc; make all
	cd libsensconv; make all
	# cd libuart; make all
clean:
	@echo "Cleaning the libs"
	cd libsrv; make clean
	cd libadc; make clean
	cd libsensconv; make clean
	# cd libuart; make clean
	rm -rf libdir
