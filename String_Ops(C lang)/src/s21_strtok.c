#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *index = S21_NULL;
  if (str != S21_NULL) {
    str += s21_strspn(str, delim);
    index = str;
  } else {
    if (*delim == '\0') {
      str = S21_NULL;
    } else {
      index += s21_strspn(index, delim);
      str = index;
    }
  }
  if (index != S21_NULL) {
    if (*index != '\0') {
      while (*index != '\0') {
        for (int i = 0; delim[i] != '\0'; i++) {
          if (*index == delim[i]) {
            if (index == str) {
              index++;
              str++;
            } else {
              *index = '\0';
              break;
            }
          }
        }
        if (*index == '\0') {
          if (*str == '\0') {
            str = S21_NULL;
          }
          index++;
          break;
        }
        index++;
      }
    } else {
      str = S21_NULL;
    }
  } else {
    str = S21_NULL;
  }
  return str;
}
