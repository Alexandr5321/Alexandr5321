#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p1 = str1;
  const char *end = str1 + s21_strlen(str1);

  while (p1 != end) {
    int found = 0;
    const char *p2 = str2;
    while (*p2 != '\0') {
      if (*p1 == *p2) {
        found = 1;
        break;
      }
      p2++;
    }
    if (found) {
      break;
    }
    p1++;
  }

  return p1 - str1;
}
