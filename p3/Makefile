##
 # @file Make file for SummarizeGrades
 # @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 # @brief make file, with make clean
 # run make to make the project , run make clean to clean the results
 # @version 0.1
 # @date 2020-02-14
 # 
 # @copyright Copyright (c) 2020
 # 
 ##

CXX=g++
CXXFLAGS=-Wall

all: build

SummarizeGrades.o: SummarizeGrades.h

clean:
	-rm demo.o
	-rm demo

build: demo.cpp demo.o
	$(CXX) $(CXXFLAGS) -o demo SummarizeGrades.cpp demo.o
