#Makefile for the TNDS laboratory 	

include ../Makefile.arch

#CXX := clang++
OBJECTS := $(wildcard *.o)
DEBUGFLAGS := -O0 -std=c++11 -pg -g
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio10.0 esercizio10.1 esercizio10.2 esercizio10.3

PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := vettorelineare.hpp vettore.hpp equazionedifferenziale.hpp

all: $(EXECUTABLES);
esercizio10.0:esercizio10.0.cpp;@	$(CXX) $(CXXFLAGS) -o $(@F) $^ $(LIBS) 
esercizio10.1:esercizio10.1.cpp;@	$(CXX) $(CXXFLAGS) -o $(@F) $^ $(LIBS) $(ROOTFLAGS) $(ROOTLIBS)
esercizio10.2:esercizio10.2.cpp;@	$(CXX) $(CXXFLAGS) -o $(@F) $^ $(LIBS) $(ROOTFLAGS) $(ROOTLIBS)
esercizio10.3:esercizio10.3.cpp;@	$(CXX) $(CXXFLAGS) -o $(@F) $^ $(LIBS) $(ROOTFLAGS) $(ROOTLIBS)

.PHONY: clean cleanall
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

