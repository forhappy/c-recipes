all: gtest-tutorial

CC = g++
CPPFLAGS = -Wall -ggdb -I ./deps/googletest/include
LDFLAGS = -lpthread -L./deps/googletest/build -lgtest_main -lgtest

gtest-tutorial: gtest-tutorial.o libmath.o
	$(CC) $(LDFLAGS) -o $@ $^

libmath.o: libmath.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

gtest-tutorial.o: gtest-tutorial.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

.PHONY:clean

clean:
	rm libmath.o gtest-tutorial.o gtest-tutorial
