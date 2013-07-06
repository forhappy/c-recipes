all:AbstractFactory Decorator Singleton Singleton-Registry Strategy\
	Template Builder FactoryMethod Prototype Adapter-Class Adapter-Object\
	Bridge Proxy

CC=g++
CPPFLAGS=-Wall -g -std=c++0x
LDFLAGS=

Proxy:Proxy.o
	$(CC) $(LDFLAGS) -o $@ $^

Proxy.o:Proxy.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Bridge:Bridge.o
	$(CC) $(LDFLAGS) -o $@ $^

Bridge.o:Bridge.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Adapter-Object:Adapter-Object.o
	$(CC) $(LDFLAGS) -o $@ $^

Adapter-Object.o:Adapter-Object.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Adapter-Class:Adapter-Class.o
	$(CC) $(LDFLAGS) -o $@ $^

Adapter-Class.o:Adapter-Class.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Prototype:Prototype.o
	$(CC) $(LDFLAGS) -o $@ $^

Prototype.o:Prototype.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

FactoryMethod:FactoryMethod.o
	$(CC) $(LDFLAGS) -o $@ $^

FactoryMethod.o:FactoryMethod.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Builder:Builder.o
	$(CC) $(LDFLAGS) -o $@ $^

Builder.o:Builder.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Template:Template.o
	$(CC) $(LDFLAGS) -o $@ $^

Template.o:Template.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

Strategy:Strategy.o
	$(CC) $(LDFLAGS) -o $@ $^

Strategy.o:Strategy.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^

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
		Strategy.o Strategy\
		Singleton-Registry.o Singleton-Registry\
		Template.o Template\
		Builder.o Builder\
		FactoryMethod.o FactoryMethod\
		Prototype.o Prototype\
		Adapter-Class.o Adapter-Class\
		Adapter-Object.o Adapter-Object\
		Bridge.o Bridge\
		Proxy.o Proxy
