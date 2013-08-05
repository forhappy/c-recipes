all: stack_test

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb -I../third-party/googletest/include
LDFLAGS=-pthread -L../third-party/googletest/build -lgtest_main -lgtest

stack_test:stack_test.o
	$(CC) $(LDFLAGS) -o $@ $^

stack_test.o:stack_test.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

.PHONY:
	clean

clean:
	rm stack_test.o stack_test\
