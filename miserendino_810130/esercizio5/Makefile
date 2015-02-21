#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
DEBUGFLAGS := -O0 -std=c++11 -pg -g -Wall -v -fmessage-length=0 -time
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio5.0 esercizio5.1 esercizio5.2 esercizio5.3
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := funzione.hpp posizione.hpp

all: $(EXECUTABLES);
sercizio5.0:esercizio5.0.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^  $(ROOTLIBS) $(ROOTFLAGS) $(LIBS)
sercizio5.3:esercizio5.3.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^  $(ROOTLIBS) $(ROOTFLAGS) $(LIBS)
esercizio5.1:esercizio5.1.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^  $(ROOTLIBS) $(ROOTFLAGS) $(LIBS)
esercizio5.2:esercizio5.2.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^  $(ROOTLIBS) $(ROOTFLAGS) $(LIBS)


.PHONY: clean cleanall
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

