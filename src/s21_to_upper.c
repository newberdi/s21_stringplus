#include "s21_string.h"

// Returns a copy of string (str) converted to uppercase.
// In case of any error, return NULL

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t length = s21_strlen(str);
    result = (char *)calloc(length + 1, sizeof(char));

    for (s21_size_t i = 0; *str != '\0'; i++, str++) {
      if (*str >= 'a' && *str <= 'z') {
        result[i] = *str - 32;
      } else {
        result[i] = *str;
      }
    }
  }
  return result;
}