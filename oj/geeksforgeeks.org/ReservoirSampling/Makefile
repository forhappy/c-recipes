all:ReservoirSampling

CC=g++
CPPFLAGS=-Wall -std=c++0x -g
LDFLAGS=

ReservoirSampling:ReservoirSampling.o
	$(CC) -o $@ $^

ReservoirSampling.o:ReservoirSampling.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm ReservoirSampling.o ReservoirSampling
