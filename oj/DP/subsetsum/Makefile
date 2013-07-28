all:SubSetSum

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

SubSetSum:SubSetSum.o
	$(CC) -o $@ $^

SubSetSum.o:SubSetSum.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm SubSetSum.o SubSetSum
