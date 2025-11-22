CC = gcc
CFLAGS = -pedantic -std=c99 -Wall -Wextra

01: src/01-1.c
	$(CC) $(CFLAGS) $< -o $@.o
