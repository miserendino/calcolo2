#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
DEBUGFLAGS := -O0 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -time
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio8.0 
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := lib.hpp

all: $(EXECUTABLES);
esercizio8.0:esercizio8.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(ROOTLIBS) $(ROOTFLAGS)
	.PHONY: clean cleanall

clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

