#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
DEBUGFLAGS := -O0 -D DEBUG -std=c++11 -pg -g -Wall -v -fmessage-length=0 -flto-report -pedantic -time -std=c++11
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio6.0 esercizio6.1	
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := vettore.hpp lib.hpp

all: $(EXECUTABLES);
esercizio6.0:esercizio6.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) 
esercizio6.1:esercizio6.1.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) 

.PHONY: clean cleanall
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

