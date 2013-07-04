all:AbstractFactory Decorator

CC=g++
CPPFLAGS=-Wall -g
LDFLAGS=

AbstractFactory:AbstractFactory.o
	$(CC) $(LDFLAGS) -o $@ $^

AbstractFactory.o:AbstractFactory.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Decorator:Decorator.o
	$(CC) $(LDFLAGS) -o $@ $^

Decorator.o:Decorator.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

.PHONY:clean

clean:
	rm AbstractFactory.o AbstractFactory Decorator.o Decorator
