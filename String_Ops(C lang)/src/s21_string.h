#ifndef S21_STRING_H
#define S21_STRING_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_sprintf.h"

#if defined(__APPLE__)
#define MAX 106
#define UNKNOWN "Unknown error: "
#elif defined(__linux__)
#define MAX 133
#define UNKNOWN "Unknown error "
#endif

#define ONE_PAGE 4096
#define s21_isNan(x) __builtin_isnan(x)
#define s21_NULL (void *)0

#define TRIM " \n\t\v\f\r"

typedef unsigned long long s21_size_t;

void *s21_memchr(const char *str, int c, s21_size_t len);
s21_size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strerror(int errnum);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int s21_memcmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(char *str1, char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strcat(char *dest, const char *src);
int s21_atoi(char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
int s21_sprintf(char *str, const char *format, ...);

#endif