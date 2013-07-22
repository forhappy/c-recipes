all:EditDistance

CC=g++
CPPFLAGS=-Wall -g
LDFLAGS=

EditDistance:EditDistance.o
	$(CC) -o $@ $^

EditDistance.o:EditDistance.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm EditDistance.o EditDistance
