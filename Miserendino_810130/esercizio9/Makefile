#Makefile for the TNDS laboratory 	
include ../Makefile.arch

OBJECTS := $(wildcard *.o)
#DEBUGFLAGS := -O0 -std=c++11 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -time
DEBUGFLAGS := -std=c++11
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio9.0 esercizio9.1
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := esperimentoprisma.hpp funzione.hpp integratore.hpp random.hpp
PWD := $(shell pwd)

all: $(EXECUTABLES);
esercizio9.0:esercizio9.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(ROOTLIBS) $(ROOTFLAGS) 
esercizio9.1:esercizio9.1.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(ROOTLIBS) $(ROOTFLAGS) 

.PHONY: clean cleanall exec0 exec1
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)
exec0:esercizio9.0	; $(PWD)/$^
exec1:esercizio9.1	; $(PWD)/$^
