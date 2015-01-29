#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
#DEBUGFLAGS := -O0 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -std=c++11 -time
DEBUGFLAGS := -std=c++11 
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio4.0 
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := campo.hpp

all: $(EXECUTABLES);
esercizio3.0:esercizio4.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)  

.PHONY: clean cleanall

clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

