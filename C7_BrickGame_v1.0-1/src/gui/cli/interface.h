#ifndef INTERFACE_H
#define INTERFACE_H

#define POLE_W 60
#define POLE_H 32

#define FIELD_H 20
#define FIELD_W 10

#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>  // для матриц - картинок
#include <string.h>  // чтобы разбирать файл чемпион.тхт
#include <unistd.h>  // для фукнции usleep() - приостановка выполнения программы на () микросекунд
#include <wchar.h>

#include "../../brick_game/tetris/backend.h"

void apply_use_color();

// анимация стартового экрана
int start_animation();
// записываем матрицу из файла (все пиксельные "картинки")
void file_to_matrix(char *file_name, char **matrix);
// вывод на экран стартовой матрицы. для декомпозиции
void print_start_pic(char **start_matrix);

// вывод всего интерфейса основной части
void interface(GameInfo_t GameInf, FigureInfo_t Figure);
// вывод на экран фона (сделал пресечением окон)
void draw_backgroud();
// вывод на экран поля лидера по очкам за время игры на машине (при анинсталле
// сведения сохраняются)
void draw_high_score(int high_score);
// вывод на экран поля помощи
void draw_help_menu();
// вывод на экран игрового поля
void draw_play_arena(int **field);
// вывод на экран поля информации (3 окна)
void draw_info_panel(GameInfo_t GameInf);
// вывод на экран поля следующей фигуры
void draw_window_next_figure(int **next, FigureInfo_t Figure);

// вывод на экран "картинки" с новым рекордом
void salut_new_record(int new_record);
void print_new_record(char **matrix);

// void print_matrix(char **matrix, int color);

// вывод на экран "картинки" с новым проигрышем в игре
void game_over(int points);
void print_game_over(char **matrix);

char quit_or_repeat();
void pause_menu();

// декаомпозиция.все инициализацию в одну функцию вставил
void init_all();
void deinit_all();

// дейсвтия про опусканию фигуры вниз
void new_game(GameInfo_t *GameInf, FigureInfo_t *Figure);
// // основное действо
// void action(int c, GameInfo_t *GameInf, FigureInfo_t Figure);
void game_finish(int c, GameInfo_t *GameInf, FigureInfo_t *Figure);

// // декомпозиця - два раза используется
// int pause_and_finish_key(int *c, GameInfo_t *GameInf);

#endif