all:Solution

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

Solution:Solution.o
	$(CC) -o $@ $^

Solution.o:Solution.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm Solution.o Solution
