all: TestThreadSafeStack

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

TestThreadSafeStack:TestThreadSafeStack.o
	$(CC) $(LDFLAGS) -o $@ $^

TestThreadSafeStack.o:TestThreadSafeStack.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

.PHONY:
	clean

clean:
	rm TestThreadSafeStack.o TestThreadSafeStack\
