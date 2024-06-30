#include "s21_test.h"

int main(void) {
  Suite *s1[] = {
      s21_strlen_suite(), suite_strlen_1(),
      s21_strcspn_suite(), suite_strcspn_1(),
      s21_strncmp_suite(), suite_strncmp_1(),
      s21_strncpy_suite(), suite_strncpy_1(),
      s21_memchr_suite(),  suite_memchr_1(),
      s21_memcmp_suite(), suite_memcmp_1(),
      s21_memcpy_suite(), suite_memcpy_1(),
      s21_memset_suite(), suite_memset_1(),
      s21_strncat_suite(), suite_strncat_1(),
      s21_strchr_suite(), suite_strchr_1(),
      s21_strerror_suite(), suite_strerror_1(),
      s21_strpbrk_suite(), suite_strpbrk_1(),
      s21_strrchr_suite(), suite_strrchr_1(),
      s21_strstr_suite(), suite_strstr_1(),
      s21_strtok_suite(), suite_strtok_1(),

      s21_to_upper_suite(), suite_to_upper_1(),
      s21_to_lower_suite(), suite_to_lower_1(),
      s21_insert_suite(), suite_insert_1(),
      s21_trim_suite(), suite_trim_1(),
      s21_all_2_suite(),

      //  suite_sprintf(),
      //  suite_sscanf(),

      NULL};

  for (int i = 0; s1[i] != NULL; i++) {
    fprintf(stderr,
            "------------------------------------------------------------------"
            "------------\n");
    SRunner *runner = srunner_create(s1[i]);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}