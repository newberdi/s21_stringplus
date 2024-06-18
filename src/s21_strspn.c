#include "s21_string.h"

//  Returns the length of the initial portion of str1
// which consists only of characters that are part of str2

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  const char *i;
  const char *j;

  for (i = str1; *i != '\0'; i++) {
    for (j = str2; *j != '\0'; j++) {
      if (*i == *j) break;
    }
    if (*j == '\0') return result;
    result++;
  }
  return result;
}
