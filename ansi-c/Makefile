all:ReverseBitsInByte

CC=g++
CPPFLAGS=-Wall -ggdb -std=c++0x
LDFLAGS=

ReverseBitsInByte:ReverseBitsInByte.o
	$(CC) -o $@ $^

ReverseBitsInByte.o:ReverseBitsInByte.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm ReverseBitsInByte.o ReverseBitsInByte
