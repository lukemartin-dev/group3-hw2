#modify this makefile so that it will work for this new assignment
CC = g++
CFLAGS = -std=c++11 -Wall

all: a.out

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

a.out: main.o
	$(CC) $(CFLAGS) main.o -o a.out

# Test target to run test cases during automated build
test: a.out
	@echo "--- Running Test 1: Standard Loan ---"
	./a.out 1000 18 50
	@echo "--- Running Test 2: Standard Loan 2 ---"
	./a.out 2000 12 80
	@echo "--- Running Test 3: Invalid Arguments (Expected Error) ---"
	-./a.out 1000 18 5  # Leading '-' allows make to continue even if exit code is non-zero

clean:
	rm -f *.o a.out
