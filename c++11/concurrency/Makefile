all:Thread

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

Thread:Thread.o
	$(CC) -o $@ $^

Thread.o:Thread.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm Thread.o Thread
