#Makefile for CS130A Lab 01
CXX=g++

CXXFLAGS=-g -Wall -std=c++11 -I/usr/lib64/ -I/usr/local/lib64/python3.8/site-packages/tensorflow/include/external/boringssl/src/include/ -l:libcrypto.so.1.1

all: 
	./main

main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp

transaction.o: transaction.cpp
    $(CXX) $(CXXFLAGS) -c transaction.cpp

clean:
	rm -f main main.o transaction.o