CC = gcc
CFLAGS = -Wall
TARGET = matrix_mult

all: clean $(TARGET)

$(TARGET): matrix_mult.c
	$(CC) $(CFLAGS) -o $(TARGET) matrix_mult.c

clean:
	rm -f $(TARGET)
