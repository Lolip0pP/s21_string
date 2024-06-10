CC = gcc
OS = $(shell uname)

ifeq ($(OS), Linux)
	FLAGS = -Werror -Wall -Wextra -std=c11 -lm -lsubunit
	TEST_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	FLAGS = -Werror -Wall -Wextra -std=c11
	TEST_FLAGS = -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck
endif

SOURCE_STRING = $(wildcard *.c)
STRING_OBJS =   $(SOURCE_STRING:.c=.o)

all: s21_string.a

s21_string.a: $(STRING_OBJS) $(SSCANF_OBJS) $(SPRINTF_OBJS)
	ar rcs $@ $^

test: clean s21_string.a
	checkmk clean_mode=1 s21_tests.check > s21_tests.c
	$(CC) $(FLAGS) s21_tests.c s21_string.a -o tests $(TEST_FLAGS)
	./tests

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h
	make test
	leaks --atExit -- test

git:
	git add *
	git commit -m 'String_21 $(shell date +"%d.%m.%Y | %H:%M:%S")'
	git push origin elyserey
	git status

gcov_report: FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: LDFLAGS += -lgcov
gcov_report: clean s21_string.a test
	lcov --directory . --capture --output-file ./app.info
	genhtml ./app.info -o ./gcov_report
	open ./gcov_report/index.html


style: clean
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c
	clang-format -n *.h
	rm -rf .clang-format

clang: clean
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c
	clang-format -i *.h
	rm -rf .clang-format

clean:
	rm -rf *.a *.out *.o tests *.html *.css
	rm -rf *.g* *.info
	rm -rf *.o
