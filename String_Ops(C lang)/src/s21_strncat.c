#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int len = s21_strlen(dest);
  unsigned char *ptr = (unsigned char *)src;
  for (size_t i = 0; i < n; i++) {
    dest[len + i] = *ptr;
    ptr++;
  }
  return dest;
}
