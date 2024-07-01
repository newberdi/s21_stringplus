
CC = gcc
CCFLAGS = -Wall -Wextra -Wextra -g -std=c11
LDFLAGS = -lcheck -lsubunit -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
RM = rm -rf
BRANCHES = --rc lcov_branch_coverage=1


# Используйте LCOV для генерации отчетов
LCOV = $(shell which lcov || echo ~/.local/bin/lcov)
GHTML = $(shell which genhtml || echo ~/.local/bin/genhtml)

# имя библиотеки
LIB_NAME = s21_string.a
# имя тестового файла
TESTS_NAME = s21_string_test
# # имя тестового файла c тестами покрытия кода gcovr
# TESTS_LCOV_NAME = s21_string_tests_gcov

# файлы и директории функций библиотек
DIR = ./
HEADER_NAME = s21_string.h
SOURCES = $(shell find $(DIR) -name "*.c")
OBJECTS = $(SOURCES:.c=.o)

# файлы и директории тестов
TEST_DIR = tests/ s21_tests/
TEST_HEADER_NAME := s21_test.h
TEST_SRC = $(shell find $(TEST_DIR) -name "*.c")
TEST_OBJ = $(TEST_SRC:.c=.o)



all:$(LIB_NAME)

$(LIB_NAME):$(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o:%.c
	$(CC) $(CCFLAGS) -c $< -o $@

test: clean $(TESTS_NAME)
	./$(TESTS_NAME)

$(TESTS_NAME): $(TEST_OBJ) $(LIB_NAME)
	$(CC) $(CCFLAGS) $^ -L. -L/usr/local/lib -L/usr/include -l:$(LIB_NAME) -o $@ $(LDFLAGS)


gcov_report: clean
	$(MAKE) test CCFLAGS="$(CCFLAGS) $(GCOV_FLAGS)"
	./$(TESTS_NAME)
	$(LCOV) -t "$(TESTS_NAME)" -o test.info -c -d . $(BRANCHES)
	$(LCOV) --remove test.info '*/tests/*' '*/s21_tests/*' --output-file test.info $(BRANCHES)
	$(GHTML) -o report test.info $(BRANCHES)
	$(RM) *.gcda *.gcno
# open report/index.html

clean: clean_lcov clean_report
	$(RM) $(TESTS_NAME)
	$(RM) $(LIB_NAME)
	$(RM) $(OBJECTS)
	$(RM) $(TEST_OBJ)

clean_report:
	$(RM) report

clean_lcov:
	$(RM) $(TESTS_NAME)
	$(RM) *.gcda *.gcno
	$(RM) test.info 


clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(DIR)*.c *.h
	clang-format -n $(TEST_DIR)*.c $(TEST_DIR)*.h
	$(RM) .clang-format

val: clean $(TESTS_NAME)
	valgrind --tool=memcheck --leak-check=yes --quiet ./$(TESTS_NAME)

cpp:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem $(shell find . -name "*.c")
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem $(shell find . -name "*.h")