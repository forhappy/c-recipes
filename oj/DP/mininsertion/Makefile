all:MinInsertion

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

MinInsertion:MinInsertion.o
	$(CC) -o $@ $^

MinInsertion.o:MinInsertion.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm MinInsertion.o MinInsertion
