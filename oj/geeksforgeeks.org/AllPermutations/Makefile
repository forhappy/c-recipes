all:AllPermutations

CC=g++
CPPfflAGS=-Wall -std=c++0x -g
LDfflAGS=

AllPermutations:AllPermutations.o
	$(CC) -o $@ $^

AllPermutations.o:AllPermutations.cc
	$(CC) $(CPPfflAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm AllPermutations.o AllPermutations
