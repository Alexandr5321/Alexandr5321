#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *p1 = (unsigned char *)dest;
  unsigned char *p2 = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    p1[i] = p2[i];
  }
  return dest;
}