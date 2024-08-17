CC=gcc
FLAGS = -Werror -Wall -Wextra -std=c11

# Определение операционной системы
# https://stackoverflow.com/questions/3466166/how-to-check-if-running-in-cygwin-mac-or-linux вот тут прочитал как систему определеять
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux) #это для Linux
	FLAGS_LCHECK = -lcheck -pthread -lrt -lm -lsubunit
endif

ifeq ($(UNAME_S),Darwin) #это macOS
	FLAGS_LCHECK = -lcheck
endif

all: clean s21_string.a

test: s21_string.a
# . - потому что библиотека в текущей директории
	rm -rf s21_program_test
	$(CC) $(FLAGS) s21_tests_string.c s21_tests_sprintf.c s21_tests_quest_1_functions.c s21_tests_sscanf.c $(FLAGS_LCHECK) -L . s21_string.o s21_sprintf.o s21_sscanf.o -o s21_program_test
	./s21_program_test
# leaks -atExit -- ./s21_program_test

gcov_report: s21_string.a
	rm -rf *.gcda *.gcno s21_program_test_with_gcov
# $(CC) $(FLAGS) s21_*.c $(FLAGS_LCHECK) -L . s21_string.a --coverage -o s21_program_test_with_gcov
	$(CC) $(FLAGS) s21_*.c $(FLAGS_LCHECK) -L . s21_string.a --coverage -o s21_program_test_with_gcov
	./s21_program_test_with_gcov
# https://ps-group.github.io/cxx/coverage_gcc
# -t <имя> устанавливает имя отчёта, при измерении покрытия кода тестами можно указать имя теста или набора тестов
# -o <имя> устанавливает имя выходного файла с промежуточной информацией
# -c указывает, что lcov должен использовать существующие данные о coverage
# -d <путь> устанавливает каталог, в котором надо искать данные о coverage, и мы передаём текущий каталог “.”
#	gcov -b -l -p -c s21_*.gcno
#	gcovr -o gcov_report.html --html --html-details
	lcov -t ./s21_program_test_with_gcov -o s21_tests.info -c -d .
	genhtml -o report s21_tests.info
# сделал сохранение html в папк репорт потому что много файлов создает, основная лиректория в помойку превращается

valgrind: s21_string.a
# . - потому что библиотека в текущей директории
	rm -rf s21_program_test
	$(CC) $(FLAGS) s21_tests_string.c s21_tests_sprintf.c s21_tests_quest_1_functions.c s21_tests_sscanf.c $(FLAGS_LCHECK) -L . s21_string.o s21_sprintf.o s21_sscanf.o -o s21_program_test
	valgrind ./s21_program_test
# leaks -atExit -- ./s21_program_test

s21_string.a: s21_string.o s21_sprintf.o s21_sscanf.o
# r - обновляем библиотеку c - создаем архив, если его нет  s - индексируем библиотку (можно не делать)
	ar rcs s21_string.a s21_string.o s21_sprintf.o s21_sscanf.o

s21_string.o: s21_string.c s21_string.h
	$(CC) $(FLAGS) -c -g s21_string.c -o s21_string.o

s21_sprintf.o: s21_sprintf.c s21_string.h s21_sprintf.h
	$(CC) $(FLAGS) -c -g s21_sprintf.c -o s21_sprintf.o

s21_sscanf.o: s21_sscanf.c s21_string.h s21_sscanf.h
	$(CC) $(FLAGS) -c -g s21_sscanf.c -o s21_sscanf.o

clean:
	rm -rf *.o *.a
	rm -rf s21_program_test
	rm -rf *.gcda *.gcno *.gch s21_program_test_with_gcov
	rm -rf *.info *.html
	rm -rf ./report
	rm -rf *.gcov

rebuild:
	make clean
	make all

clang:
	clang-format -i *.c *.h
	clang-format -n *.c *.h