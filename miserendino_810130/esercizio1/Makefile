#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
DEBUGFLAGS := -O0 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -time
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio1.4 esercizio1.3 esercizio1.2
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := lib.hpp lib2.hpp

all: $(EXECUTABLES);
esercizio1.4:esercizio1.4.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) 
esercizio1.2:esercizio1.2.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) 
esercizio1.3:esercizio1.3.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) 
	
	.PHONY: clean cleanall
clean: ;	/bin/rm -f $(OBJECTS)
cleanall: ; /bin/rm -f $(EXECUTABLES) $(OBJECTS)


