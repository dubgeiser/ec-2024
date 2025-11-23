CC = gcc
CFLAGS = -pedantic -std=c99 -Wall -Wextra

%: src/%.c
	$(CC) $(CFLAGS) $< -o $@.o

clean:
	rm -f *.o
