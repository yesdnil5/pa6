all: bookorder

bookorder: BookOrder.o Threads.o

Threads.o: Threads.c
	gcc -c -g Threads.c

BookOrder.o: BookOrder.c
	gcc -c -g BookOrder.c

clean:
	rm -rf *.o
