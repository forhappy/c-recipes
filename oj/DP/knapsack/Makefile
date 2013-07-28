all:Knapsack

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

Knapsack:Knapsack.o
	$(CC) -o $@ $^

Knapsack.o:Knapsack.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm Knapsack.o Knapsack
