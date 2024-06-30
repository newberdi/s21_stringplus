#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL)
    return S21_NULL;
  else if (str == S21_NULL)
    return S21_NULL;
  else if (start_index > s21_strlen(src))
    return S21_NULL;

  char *copy = S21_NULL;
  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);
    s21_size_t length = src_length + str_length;
    if (start_index <= src_length) {
      copy = calloc(length + 1, sizeof(char));
      if (copy != S21_NULL) {
        for (s21_size_t i = 0; i < start_index; i++) {
          copy[i] = src[i];
        }
        for (s21_size_t i = 0; i < str_length; i++) {
          copy[i + start_index] = str[i];
        }
        for (s21_size_t i = 0; i < src_length - start_index; i++) {
          copy[i + start_index + str_length] = src[i + start_index];
        }
        copy[length] = '\0';
      }
    }
  }
  return (void *)copy;
}