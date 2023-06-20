CC=gcc

main: main.o  enrollee.c enrollee.h enrollee_dump
	$(CC) main.o enrollee.c enrollee.h -lm -o main

enrollee_dump: enrollee_dump.o
	$(CC) enrollee_dump.o -o enrollee_dump

enrollee_dump.o: enrollee_dump.c
	$(CC) -c enrollee_dump.c -o enrollee_dump.o

main.o: main.c enrollee.c enrollee.h
	$(CC) -c main.c -lm -o main.o

clean:
	rm -r build