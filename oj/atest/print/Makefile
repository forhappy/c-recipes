all:Print

CC=/usr/bin/g++
CPPFLAGS=-Wall -g
LDFLAGS=

Print:Print.o
	$(CC) -o $@ $^

Print.o:Print.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm Print.o Print
