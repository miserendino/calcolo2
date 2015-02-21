#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
DEBUGFLAGS := -O0 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -std=c++11 -time
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio7.0 esercizio7.1 esercizio7.2
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := integratore.hpp

all: $(EXECUTABLES);
esercizio7.0:esercizio7.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)  
esercizio7.1:esercizio7.1.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)  
esercizio7.2:esercizio7.2.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)  

.PHONY: clean cleanall
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

