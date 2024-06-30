
CC = gcc
CCFLAGS = -Wall -Wextra -Wextra -std=c11
LDFLAGS = -lcheck -lsubunit -lm
RM = rm -rf
BRANCHES = --rc lcov_branch_coverage=1


# Используйте LCOV для генерации отчетов
LCOV = $(shell which lcov || echo ~/.local/bin/lcov)
GHTML = $(shell which genhtml || echo ~/.local/bin/genhtml)

# имя библиотеки
LIB_NAME = s21_string.a
# имя тестового файла
TESTS_NAME = s21_string_test
# имя тестового файла c тестами покрытия кода gcovr
TESTS_LCOV_NAME = s21_string_tests_gcov

# файлы и директории функций библиотек
DIR = ./
HEADER_NAME = s21_string.h
SOURCES = $(shell find $(DIR) -name "*.c")
OBJECTS = $(SOURCES:.c=.o)

# файлы и директории тестов
TEST_DIR = tests/
TEST_HEADER_NAME := s21_test.h
TEST_SRC = $(shell find $(TEST_DIR) -name "*.c")
TEST_OBJ = $(TEST_SRC:.c=.o)



all:$(LIB_NAME)

$(LIB_NAME):$(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o:%.c
	$(CC) $(CCFLAGS) -c $< -o $@

test:clean $(TESTS_NAME)
	./$(TESTS_NAME)

$(TESTS_NAME): $(TEST_OBJ) $(LIB_NAME)
	$(CC) $(CCFLAGS) $^ -L. -L/usr/local/lib -L/usr/include -l:$(LIB_NAME) -o $@ $(LDFLAGS)

gcov_report:clean_gcov clean_report $(TESTS_GCOV_NAME)
	./$(TESTS_GCOV_NAME)
	mkdir report
	$(GCOVR) -r . --html --html-details -o report/coverage.html --exclude=$(TEST_DIR)
	make clean_gcov
	open report/coverage.html

$(TESTS_GCOV_NAME):$(TEST_SRC) $(SOURCES)
	$(CC) $(CCFLAGS) -g -fprofile-arcs -ftest-coverage $^ -o $@ $(LDFLAGS)

clean:clean_gcov clean_report
	$(RM) $(TESTS_NAME)
	$(RM) $(LIB_NAME)
	$(RM) $(OBJECTS)
	$(RM) $(TEST_OBJ)

clean_report:
	$(RM) report

clean_gcov:
	$(RM) $(TESTS_GCOV_NAME)
	$(RM) *.gcda
	$(RM) *.gcno

val: clean $(TESTS_NAME)
	valgrind --tool=memcheck --leak-check=yes --quiet ./$(TESTS_NAME)