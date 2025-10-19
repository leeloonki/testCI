CXX = g++
CXXFLAGS = -O2 -Wall -std=c++11

all: matrix

matrix: matrix.cpp
	$(CXX) $(CXXFLAGS) -o matrix matrix.cpp

test: matrix
	./matrix

clean:
	rm -f matrix

.PHONY: all test clean