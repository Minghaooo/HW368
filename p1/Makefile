CXX=g++
CXXFLAGS=-Wall 

all: build

MathLib.o: MathLib.h

clean:
	-rm MathLib.o
	-rm demo

build: demo.cpp MathLib.o
	$(CXX) $(CXXFLAGS) -o demo demo.cpp MathLib.o
