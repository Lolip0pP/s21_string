CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g -O0
CHECKFLAGS=-lcheck -lm -lsubunit 

test:
	$(CC) -c *.c
	$(CC) -c tests/*.c
	$(CC) *.o $(CHECKFLAGS) $(CFLAGS) -o test
	rm -f *.o tests/*.o

clean:
	rm -rf **/*.o *.o test report.out *.gcno *.gcda *.gcov *.gch
	rm -f *.o tests/*.o
