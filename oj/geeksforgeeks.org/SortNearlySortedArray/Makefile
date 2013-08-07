all:SortNearlySortedArray

CC=/usr/bin/g++
CPPFFLAGS=-Wall -std=c++0x -ggdb
LDFFLAGS=

SortNearlySortedArray:SortNearlySortedArray.o
	$(CC) -o $@ $^

SortNearlySortedArray.o:SortNearlySortedArray.cc
	$(CC) $(CPPFFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm SortNearlySortedArray.o SortNearlySortedArray
