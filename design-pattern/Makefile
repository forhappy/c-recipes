all:AbstractFactory Decorator Singleton Singleton-Registry

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

Singleton-Registry:Singleton-Registry.o
	$(CC) $(LDFLAGS) -o $@ $^

Singleton-Registry.o:Singleton-Registry.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Singleton:Singleton.o
	$(CC) $(LDFLAGS) -o $@ $^

Singleton.o:Singleton.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

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
	rm AbstractFactory.o AbstractFactory\
		Decorator.o Decorator\
		Singleton.o Singleton\
		Singleton-Registry.o Singleton-Registry
