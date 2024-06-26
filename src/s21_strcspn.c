#include "s21_string.h"

// Calculates the length of the initial segment of str1
// which consists entirely of characters not in str2

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int flag = 1;

  for (int i = 0; str1[0] != '\0' && flag; i++) {
    if (s21_strchr(str2, str1[i]) == S21_NULL)
      result++;
    else
      flag = 0;
  }

  return result;
}
