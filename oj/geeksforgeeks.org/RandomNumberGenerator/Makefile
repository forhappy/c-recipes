all:RandomNumberGenerator

CC=g++
CPPFLAGS=-Wall -std=c++0x -g
LDFLAGS=

RandomNumberGenerator:RandomNumberGenerator.o
	$(CC) -o $@ $^

RandomNumberGenerator.o:RandomNumberGenerator.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm RandomNumberGenerator.o RandomNumberGenerator
