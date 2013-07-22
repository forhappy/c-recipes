all:MaxSubSum

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

MaxSubSum:MaxSubSum.o
	$(CC) -o $@ $^

MaxSubSum.o:MaxSubSum.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm MaxSubSum.o MaxSubSum
