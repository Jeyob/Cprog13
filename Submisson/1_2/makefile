%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

CC = g++
FILES = must_follow_a.h must_follow_a.cpp

test: $(FILES)
	$(CC) -c must_follow_a.cpp

	cxxtestgen --error-printer -o 1.2b.cpp test_must_follow_a.cpp

	$(CC) -g -o test_1.2b.out -I ./cxxtest/ 1.2b.cpp must_follow_a.o

