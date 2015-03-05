#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
#DEBUGFLAGS := -O0 -std=c++11 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -time  
DEBUGFLAGS := -std=c++11
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio10.0
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := lib.hpp

all: $(EXECUTABLES);
esercizio10.0:esercizio10.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ 

.PHONY: clean cleanall
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

