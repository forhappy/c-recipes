all:CoinChange2

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

CoinChange2:CoinChange2.o
	$(CC) -o $@ $^

CoinChange2.o:CoinChange2.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm CoinChange2.o CoinChange2
