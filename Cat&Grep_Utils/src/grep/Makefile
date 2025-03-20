SHELL := /bin/bash
FLAGS = -Wall -Wextra -Werror -std=c11
PATH_TEST = ./test_grep/test.sh

all: s21_grep

s21_grep: s21_grep.c
	gcc $(FLAGS) s21_grep.c -o s21_grep

rebuild:
	make clean
	make all


test:
	$(PATH_TEST)

clean:
	rm -f s21_grep