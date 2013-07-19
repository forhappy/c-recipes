all:mincuts

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

mincuts:mincuts.o
	$(CC) -o $@ $^

mincuts.o:mincuts.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm mincuts.o mincuts
