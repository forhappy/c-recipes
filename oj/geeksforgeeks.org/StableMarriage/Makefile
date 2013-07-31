all:StableMarriage

CC=g++
CPPfflAGS=-Wall -std=c++0x -g
LDfflAGS=

StableMarriage:StableMarriage.o
	$(CC) -o $@ $^

StableMarriage.o:StableMarriage.cc
	$(CC) $(CPPfflAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm StableMarriage.o StableMarriage
