#modify this makefile so that it will work for this new assignment
CC=g++
CFLAGS = -std=c++11 -Wall

all: main.o
	$(CC) $(CFLAGS) main.o -o a.out

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean: 
	rm -f *.o *.out
