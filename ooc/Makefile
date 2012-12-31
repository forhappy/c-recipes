all:main

main:main.o dog.o cat.o animal-base.o
	gcc -g -O0 -o $@ $^

main.o:main.c
	gcc -g -O0 -o $@ -c $^

cat.o:cat.c
	gcc -g -O0 -o $@ -c $^

dog.o:dog.c
	gcc -g -O0 -o $@ -c $^

animal-base.o:animal-base.c
	gcc -g -O0 -o $@ -c $^

.PHONY:clean

clean:
	rm main main.o dog.o cat.o animal-base.o
