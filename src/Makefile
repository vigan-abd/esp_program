####################################################################
# Makefile                                                         #
####################################################################

.SUFFIXES:				# ignore builtin rules
.PHONY: clean all

####################################################################
# Definitions                                                      #
####################################################################

all:
	@echo "Building the nodes"
	cd node_3; make all
	cd node_2; make all
	cd node_1; make all
	cd node_0; make all

clean:
	@echo "Cleaning the nodes"
	cd node_3; make clean
	cd node_2; make clean
	cd node_1; make clean
	cd node_0; make clean

install:
	@echo "Installing the nodes"
	cd node_3; make install
	cd node_2; make install
	cd node_1; make install
	cd node_0; make install

