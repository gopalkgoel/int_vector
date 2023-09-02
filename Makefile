CC = gcc
CFLAGS = -Wall -Wextra
TARGET = tests

all: $(TARGET)

$(TARGET): testing.c int_vec.c int_vec.h
	$(CC) $(CFLAGS) -o $@ testing.c int_vec.c
	./$@

clean:
	rm -f $(TARGET)
