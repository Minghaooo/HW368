##
 # @file Make file for BOOK
 # @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 # @brief make file, with make clean
 # @version 0.1
 # @date 2020-02-14
 # 
 # @copyright Copyright (c) 2020
 # 
 ##
CXX=g++
CXXFLAGS=-Wall -std=c++11

all: build

BookDB.o: BookDB.h

clean:
	-rm BookDB.o
	-rm demo

build: demo.cpp BookDB.o
	$(CXX) $(CXXFLAGS) -o demo demo.cpp BookDB.o
