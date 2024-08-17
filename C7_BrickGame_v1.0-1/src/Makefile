CC=gcc

BUILD=../build
DOCS=../docs
DISTR=../distr

OS = $(shell uname)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS_LCHECK = -lcheck -pthread -lrt -lm -lsubunit
	OPEN_CMD = xdg-open
	FLAGS = -Wall -Wextra -std=c11
	NCURSES = -lncursesw
# -lcursesw чтобы символы wchar заработали в линуксе
endif
ifeq ($(UNAME_S),Darwin)
	FLAGS_LCHECK = -lcheck
	OPEN_CMD = open
	FLAGS = -Werror -Wall -Wextra -std=c11
	NCURSES = -lncurses
endif

OBJECTS=brick_game/tetris/backend.c gui/cli/interface.c

all: install
	./$(BUILD)/tetris

gcov_report:
	rm -f *.g*
	$(CC) $(FLAGS) $(OBJECTS) tests.c $(NCURSES) $(FLAGS_LCHECK) -L. --coverage -o tetris_test_with_gcov
	./tetris_test_with_gcov
# --exclude 'gui/cli/interface.c' - не вклчать в отчет файл interface.c
	lcov -t "test" -o rep.info -c -d . --exclude 'gui/cli/interface.c'
	genhtml -o report rep.info
	$(OPEN_CMD) ./report/index.html
	rm -rf *.gcda *.gcno tests tests.info *.o

test: tetris.a
	clear 
	rm -rf tests
	$(CC) $(FLAGS) $(OBJECTS) tests.c $(FLAGS_LCHECK) tetris.a $(NCURSES) -L . -o tests
	./tests

tetris.a:
	@rm -rf *.a *.o
	$(CC) $(FLAGS) brick_game/tetris/backend.c -c $<
	@ar rcs tetris.a *.o
	@ranlib tetris.a

install: clean
	@mkdir $(BUILD) 
	$(CC) $(FLAGS) main.c $(OBJECTS) $(NCURSES) -o $(BUILD)/tetris

uninstall:
	@rm -rf $(BUILD)/tetris
	@rm -rf $(BUILD)

clean:
	@rm -rf $(BUILD)/tetris
	@rm -rf *.a *.o
	@rm -rf $(BUILD) $(DOCS) $(DISTR) 
	@rm -rf tests
	@rm -rf *.gcda *.gcno *.gch *_with_gcov *.css
	@rm -rf *.info
	@rm -rf ./report
	@rm -rf .clang-format
	@rm -rf *.gz

check_clang-format:
	@cp ../materials/linters/.clang-format .
	@clang-format -i *.c gui/cli/*.c gui/cli/*.h brick_game/tetris/*.c brick_game/tetris/*.h
	clang-format -n *.c gui/cli/*.c gui/cli/*.h brick_game/tetris/*.c brick_game/tetris/*.h
	@rm -rf .clang-format

check_memory:
# @make test
	@make all
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- $(BUILD)/tetris
else
	valgrind --tool=memcheck --leak-check=summary $(BUILD)/tetris
endif

# Цель dvi для генерации документации в формате DVI
dvi: documentation.tex
	@make clean
	@mkdir $(DOCS)
	@cp documentation.tex $(DOCS)
	cd $(DOCS) && latex $(DOCS)/documentation.tex

# Цель dist для создания архива с исходным кодом и другими необходимыми файлами
dist: clean
# Сначала создается временная директория dist, в которую копируются все важные файлы проекта: исходный код, Makefile, документация , и т.д.
# Затем создается архив project_dist.tar.gz, содержащий все файлы из dist.
# После создания архива временная директория dist удаляется.
	@mkdir $(DISTR)
	@cp -r $(OBJECTS) main.c Makefile documentation.tex $(DISTR)
	@tar -czvf project_dist.tar.gz $(DISTR)
	@rm -rf $(DISTR)

rebuild: clean install
