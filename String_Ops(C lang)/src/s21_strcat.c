#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *pointer = dest;
  while (*pointer) {
    pointer++;
  }
  while (*src != '\0') {
    *pointer++ = *src++;
  }
  *pointer = *src;
  return dest;
}