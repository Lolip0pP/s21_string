CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g -O0
CHECKFLAGS=-lcheck -lm -lsubunit 
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LDFLAGS=-lgcov

test:
	$(CC) -c *.c
	$(CC) -c tests/*.c
	$(CC) *.o $(CHECKFLAGS) $(CFLAGS) -o test
	rm -f *.o tests/*.o

gcov_report:
	$(CC) *.c tests/*.c $(CHECKFLAGS) $(CFLAGS) $(GCOVFLAGS) $(LDFLAGS) -o report.out
	./report.out
	find ./ -type f -iname '*.gcda'
	lcov -o report.info -c -d .
	rm -rf ./cov-report
	mkdir ./cov-report
	genhtml -o ./cov-report/ report.info
	rm *.gcno *.gcda report.out

clean:
	rm -rf **/*.o *.o test report.out *.gcno *.gcda *.gcov *.gch
	rm -f *.o tests/*.o 

