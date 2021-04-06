CXX=g++

CXXFLAGS=-g -Wall -std=c++11 -I/usr/lib64/ -I/usr/local/lib64/python3.8/site-packages/tensorflow/include/external/boringssl/src/include/ -l:libcrypto.so.1.1

main.o: main.cpp
    ${CXX} ${CXXFLAGS} -c main.cpp

transaction.o: transaction.cpp
    ${CXX} ${CXXFLAGS} -c transaction.cpp
	
all: main.o transaction.o
	$(CXX) $(CXXFLAGS) -o main main.o transaction.o

clean:
	/bin/rm -f *.o main