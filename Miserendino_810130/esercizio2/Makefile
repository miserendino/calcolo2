#Makefile for the TNDS laboratory 	

OBJECTS := $(wildcard *.o)
DEBUGFLAGS := -O0 -pg -g -D DEBUG -Wall -v -fmessage-length=0 -flto-report -pedantic -time  -ftime-report
ROOTLIBS := $(shell root-config --glibs)
ROOTFLAGS := $(shell root-config --cflags)
EXECUTABLES := esercizio2.1 esercizio2.2 scatterplot
PARALLELFLAG := -fopenmp
CXXFLAGS := $(DEBUGFLAGS) 
LIBS := lib.hpp

all: $(EXECUTABLES);
esercizio2.1:esercizio2.1.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^  
esercizio2.2:esercizio2.2.cpp;@	$(CXX) $(CXXFLAGS) -o $@ $^ lib.hpp 
scatterplot:scatterplot.cpp; @	$(CXX) $(CXXFLAGS) -o $@ $^ $(ROOTFLAGS) $(ROOTLIBS)

.PHONY: clean cleanall
clean: ;		/bin/rm -f $(OBJECTS)
cleanall: ;	/bin/rm -f $(OBJECTS) && /bin/rm -f $(EXECUTABLES)

