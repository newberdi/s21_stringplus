#include "s21_string.h"

// Returns a new string in which a specified string (str) is inserted
// at a specified index position (start_index) in the given string (src).
// In case of any error, return NULL

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (str == S21_NULL)
    return S21_NULL;
  else if (/*start_index < 0 ||*/ start_index > s21_strlen(src))
    return S21_NULL;

  s21_size_t length = s21_strlen(src) + s21_strlen(str);

  char *copy = calloc(length + 1, sizeof(char));

  for (s21_size_t i = 0; i < length;) {
    if (i != start_index) {
      copy[i] = *src;
      src++;
      i++;
    } else
      for (; *str != '\0'; i++, str++) copy[i] = *str;
  }

  return copy;
}
