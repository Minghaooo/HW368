# An example makefile

CXX=g++
CXXFLAGS=-Wall

all: build

HelloWorld.o: HelloWorld.h

clean:
	-rm HelloWorld.o
	-rm hello

build: runHello.cpp HelloWorld.o
	$(CXX) $(CXXFLAGS) -o hello runHello.cpp HelloWorld.o
