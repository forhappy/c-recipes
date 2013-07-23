all:MatrixChain

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

MatrixChain:MatrixChain.o
	$(CC) -o $@ $^

MatrixChain.o:MatrixChain.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm MatrixChain.o MatrixChain
