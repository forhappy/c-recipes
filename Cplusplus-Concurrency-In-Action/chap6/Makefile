all: TestThreadSafeStack

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb -I../third-party/googletest/include
LDFLAGS=-pthread -L../third-party/googletest/build -lgtest_main -lgtest

TestThreadSafeStack:TestThreadSafeStack.o
	$(CC) $(LDFLAGS) -o $@ $^

TestThreadSafeStack.o:TestThreadSafeStack.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

.PHONY:
	clean

clean:
	rm TestThreadSafeStack.o TestThreadSafeStack\
