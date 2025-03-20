CFLAGS=-Wall -Wextra -Werror -pedantic -std=c11

all: s21_cat

s21_cat:  s21_cat.c
	gcc $(CFLAGS) s21_cat.c -o s21_cat

rebuild:
	make clean
	make all

clean:
	rm -f s21_cat
