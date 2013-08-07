all:MergeKSortedArray

CC=/usr/bin/g++
CPPFFLAGS=-Wall -std=c++0x -ggdb
LDFFLAGS=

MergeKSortedArray:MergeKSortedArray.o
	$(CC) -o $@ $^

MergeKSortedArray.o:MergeKSortedArray.cc
	$(CC) $(CPPFFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm MergeKSortedArray.o MergeKSortedArray
