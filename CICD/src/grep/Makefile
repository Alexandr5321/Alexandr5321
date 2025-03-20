SHELL := /bin/bash
PATH_TEST = ./test_grep/test.sh

all: s21_grep

s21_grep: s21_grep.c
	gcc s21_grep.c -o s21_grep

rebuild:
	make clean
	make all


test:
	$(PATH_TEST)

clean:
	rm -f s21_grep