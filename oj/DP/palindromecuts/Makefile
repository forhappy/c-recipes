all:PalindromeCuts

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

PalindromeCuts:PalindromeCuts.o
	$(CC) -o $@ $^

PalindromeCuts.o:PalindromeCuts.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm PalindromeCuts.o PalindromeCuts
