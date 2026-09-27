#modify this makefile so that it will work for this new assignment
CC = g++
CFLAGS = -std=c++11 -Wall

all: main.o
	$(CC) $(CFLAGS) main.o -o a.out

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test: a.out
	./a.out 1000 18 50
	./a.out 2000 12 80

clean:
	rm -f *.o a.out
