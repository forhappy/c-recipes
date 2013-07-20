all:LIS

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

LIS:LIS.o
	$(CC) -o $@ $^

LIS.o:LIS.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm LIS.o LIS
