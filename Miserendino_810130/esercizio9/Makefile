#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
#DEBUGFLAGS := -O0 -std=c++11 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -time
DEBUGFLAGS := -std=gnu++11 -D DEBUG
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio9.0
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := esperimentoprisma.hpp
PWD := $(shell pwd)

all: $(EXECUTABLES);
esercizio9.0:esercizio9.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(ROOTLIBS) $(ROOTFLAGS) 

.PHONY: clean cleanall exec
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)
exec:esercizio9.0	; $(PWD)/$^
