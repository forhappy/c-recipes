all:LCS

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

LCS:LCS.o
	$(CC) -o $@ $^

LCS.o:LCS.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm LCS.o LCS
