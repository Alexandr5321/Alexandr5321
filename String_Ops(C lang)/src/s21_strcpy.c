#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *pointer = dest;
  while (*src != '\0') {
    *pointer++ = *src++;
  }
  *pointer = *src;
  return dest;
}