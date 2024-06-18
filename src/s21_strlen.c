#include "s21_string.h"

// Computes the length of the string str up to
// but not including the terminating null character

s21_size_t s21_strlen(const char *str) {
  char *tmp = (char *)str;
  s21_size_t length = 0;

  while (*tmp != '\0') {
    length++;
    tmp++;
  }

  return length;
}