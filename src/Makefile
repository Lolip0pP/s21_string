CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g -O0
CHECKFLAGS=-lcheck -lm -lsubunit 

test:
	$(CC) s21_string.c tests/*.c $(CHECKFLAGS) $(CFLAGS) -o test

clean:
	rm -rf **/*.o *.o test