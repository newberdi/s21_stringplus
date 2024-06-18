#include "s21_string.h"

// Calculates the length of the initial segment of str1
// which consists entirely of characters not in str2

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int flag = 0;
  int len1 = s21_strlen(str1);
  int len2 = s21_strlen(str2);
  for (int i = 0; (i < len1) && !flag; i++, result++) {
    for (int j = 0; (j < len2) && !flag; j++) {
      if (str1[i] == str2[j]) {
        flag++;
      }
    }
  }
  return (result - 1);
}