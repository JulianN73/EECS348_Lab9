CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: matrix

matrix: Lab9.cpp
	$(CXX) $(CXXFLAGS) Lab9.cpp -o matrix

clean:
	rm -f matrix