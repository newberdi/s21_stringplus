#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

#define UINT_MAX 4294967295
#define INT_MAX 2147483647
#define USHRT_MAX 65535
#define SHRT_MAX 32767
#define SIZE 1000

// Suite *s21_sscanf_suite();
// Suite *test_sscanf_c();
// Suite *test_sscanf_d();
// Suite *test_sscanf_i();
// Suite *test_sscanf_o();
// Suite *test_sscanf_x();
// Suite *test_sscanf_p();
// Suite *test_sscanf_n();
// Suite *test_sscanf_s();
// Suite *test_sscanf_real();
// Suite *test_sscanf_empty();

Suite *s21_strlen_suite();
Suite *s21_memchr_suite();
Suite *s21_memcmp_suite();
Suite *s21_memcpy_suite();
Suite *s21_memset_suite();
Suite *s21_strtok_suite();
Suite *s21_strcspn_suite();
Suite *s21_strchr_suite();
Suite *s21_strncpy_suite();
Suite *s21_strncat_suite();
Suite *s21_strncmp_suite();
Suite *s21_strrchr_suite();
Suite *s21_strstr_suite();
Suite *s21_strpbrk_suite();
Suite *s21_strerror_suite();
// Suite *s21_sprintf_suite();

Suite *s21_to_upper_suite();
Suite *s21_to_lower_suite();
Suite *s21_insert_suite();
Suite *s21_trim_suite();

Suite *s21_all_2_suite();

Suite *suite_memchr_1();
Suite *suite_memcmp_1();
Suite *suite_memcpy_1();
Suite *suite_memset_1();
Suite *suite_strncat_1();
Suite *suite_strchr_1();
Suite *suite_strerror_1();
Suite *suite_strpbrk_1();
Suite *suite_strrchr_1();
Suite *suite_strstr_1();
Suite *suite_strtok_1();
Suite *suite_strlen_1();
Suite *suite_strcspn_1();
Suite *suite_strncmp_1();
Suite *suite_strncpy_1();

Suite *suite_to_upper_1();
Suite *suite_to_lower_1();
Suite *suite_insert_1();
Suite *suite_trim_1();

#endif
