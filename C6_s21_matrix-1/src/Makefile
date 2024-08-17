CC=gcc
FLAGS = -Werror -Wall -Wextra -std=c11

OS = $(shell uname)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS_LCHECK = -lcheck -pthread -lrt -lm -lsubunit
	OPEN_CMD = xdg-open
else
endif
ifeq ($(UNAME_S),Darwin)
	FLAGS_LCHECK = -lcheck
	OPEN_CMD = open
endif

# собираем все файлы с s21_ в наименовании (тесты не будут затронуты)
SOURCES = $(wildcard s21_*.c)
TEST_SOURCES = tests.c

all: test

test: s21_matrix.a
	clear 
	rm -rf s21_test
	$(CC) $(FLAGS) *.c $(FLAGS_LCHECK) s21_matrix.a -L . -o s21_matrix_test 
	./s21_matrix_test


gcov_report: s21_matrix.a
	rm -f *.g*
	$(CC) $(FLAGS) *.c $(FLAGS_LCHECK) -L. --coverage -o s21_matrix_test_with_gcov
	./s21_matrix_test_with_gcov
	lcov -t "test" -o rep.info -c -d .
	genhtml -o report rep.info
	$(OPEN_CMD) ./report/index.html
	rm -rf *.gcda *.gcno s21_tests s21_tests.info *.o


s21_matrix.a: objects
# r - обновляем библиотеку c - создаем архив, если его нет  s - индексируем библиотку (можно не делать)
# rm -rf *.a
# $(CC) $(FLAGS) $(SOURCES) -c
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

clean:
	@rm -rf *.o *.a
	@rm -rf s21_test
	@rm -rf *.gcda *.gcno *.gch s21_matrix_test_with_gcov s21_matrix_test *.css
	@rm -rf *.info *.html
	@rm -rf ./report
	@rm -rf *.gcov

rebuild:
	make clean
	make all

clang:
	@cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	clang-format -n *.c *.h
	@rm -rf .clang-format

objects:
	$(CC) $(FLAGS) $(SOURCES) -c $<

check_memory:
	@make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./s21_matrix_test
else
	valgrind --tool=memcheck --leak-check=summary ./s21_matrix_test
endif
	make clean

