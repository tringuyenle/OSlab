#this is makefile

all: factorial.o readline.o  main.o 
	gcc factorial.o readline.o  main.o -o myfactorial

factorial.o: factorial.h factorial.c
	gcc -c factorial.c

readline.o: readline.h readline.c
	gcc -c readline.c

main.o: factorial.h readline.h main.c
	gcc -c main.c

clean:
	rm -f *.o factorial
	rm -f *.o readline
