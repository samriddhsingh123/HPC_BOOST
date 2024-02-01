CC = gcc
CFLAGS = -Wall

all: fib merge_sort matmul heat

fib: fib.c
	$(CC) $(CFLAGS) -o fib fib.c

merge_sort: merge_sort.c
	$(CC) $(CFLAGS) -o merge_sort merge_sort.c

matmul: matrix_mult.c
	$(CC) $(CFLAGS) -o matmul matrix_mult.c

heat: heat.c
	$(CC) $(CFLAGS) -o heat heat.c

clean:
	rm -f fib merge_sort matmul heat
