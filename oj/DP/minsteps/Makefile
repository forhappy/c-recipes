all:minsteps

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

minsteps:minsteps.o
	$(CC) -o $@ $^

minsteps.o:minsteps.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm minsteps.o minsteps
