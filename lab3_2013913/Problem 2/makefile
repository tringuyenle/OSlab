#this is makefile

all: cond_usg.o nosynch.o
	gcc -o run_cond_usg cond_usg.o -lpthread
	gcc -o run_nosynch nosynch.o -lpthread

cond_usg.o: cond_usg.c
	gcc -c cond_usg.c -lpthread

nosynch.o: nosynch.c
	gcc -c nosynch.c -lpthread

clean:
	rm -f *.o cond_usg
	rm -f *.o nosynch
