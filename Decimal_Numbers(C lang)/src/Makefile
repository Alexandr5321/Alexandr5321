#flags
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -g#-g for valgrind, -Wpedantic also can be added, -lm for <math.h>
VFLAGS=--track-origins=yes --tool=memcheck --vgdb=no --leak-check=full --show-leak-kinds=all --verbose
TFLAGS = -lcheck -lpthread
OPEN = open

#files
FUNCTIONS_C=s21_add.c s21_sub.c s21_div.c s21_mul.c arithmetics.c helpers.c s21_compare.c s21_from_decimal_to_float.c s21_from_decimal_to_int.c s21_from_float_to_decimal.c s21_from_int_to_decimal.c other_funcs.c
TEST_OBJS = $(wildcard tests/*.c)
FUNCTIONS_FOR_TESTS_C=s21_add.c s21_sub.c s21_div.c s21_mul.c arithmetics.c helpers.c print_s21_decimal.o s21_compare.c s21_from_decimal_to_float.c s21_from_decimal_to_int.c s21_from_float_to_decimal.c s21_from_int_to_decimal.c other_funcs.c

ifeq ($(shell uname), Linux)
	OPEN = xdg-open
	TFLAGS += -lrt -lsubunit -lgcov -lm
endif

#instructions
all: clean clang s21_decimal.a

s21_decimal.a:
	$(CC) -c $(CFLAGS) $(FUNCTIONS_C)
	ar rcs s21_decimal.a *.o

test:
	$(CC) $(CFLAGS) $(TEST_OBJS) print_s21_decimal.o s21_decimal.a -o s21_tests $(TFLAGS)
	./s21_tests

gcov_report: clean
	$(CC) $(CFLAGS) --coverage $(TEST_OBJS) $(FUNCTIONS_FOR_TESTS_C) -o s21_tests $(TFLAGS)
	./s21_tests
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	$(OPEN) html_report/index.html

clean:
	for file in $(wildcard *.gcda *.gcno report.info s21_tests *.o s21_decimal.a); do\
		if [ "$$file" != "print_s21_decimal.o" ]; then \
			rm $$file;\
		fi; \
	done

clang:
	for file in $(wildcard *.c *.h tests/*.c tests/*.h); do\
		clang-format -i $$file;\
	done

valgrind:
	valgrind $(VFLAGS) ./s21_tests 

rebuild: clean clang all
