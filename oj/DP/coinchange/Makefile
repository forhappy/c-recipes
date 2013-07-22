all:CoinChange

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

CoinChange:CoinChange.o
	$(CC) -o $@ $^

CoinChange.o:CoinChange.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm CoinChange.o CoinChange
