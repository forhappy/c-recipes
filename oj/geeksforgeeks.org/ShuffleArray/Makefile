all:ShuffleArray

CC=g++
CPPfflAGS=-Wall -std=c++0x -g
LDfflAGS=

ShuffleArray:ShuffleArray.o
	$(CC) -o $@ $^

ShuffleArray.o:ShuffleArray.cc
	$(CC) $(CPPfflAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm ShuffleArray.o ShuffleArray
