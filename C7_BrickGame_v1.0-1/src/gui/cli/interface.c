#include "interface.h"

#include "../../brick_game/tetris/backend.h"

// анимация стартового экрана
int start_animation() {
  char **start_matrix = malloc(POLE_H * sizeof(char *));
  for (int i = 0; i < POLE_H; i++)
    start_matrix[i] = malloc(POLE_W * sizeof(char));

  int exit = 0;
  file_to_matrix("gui/cli/start_pic.txt", start_matrix);
  print_start_pic(start_matrix);

  int startx = 13, starty = 24, width = 30, height = 4;
  WINDOW *win_start = newwin(height, width, starty, startx);
  box(win_start, 1, 1);

  wattron(win_start, A_BLINK);  // делаем мигание текста
  wchar_t symbol_s = L'\x24C8';
  mvwprintw(win_start, 1, 7, "TO START PRESS %lc", symbol_s);
  wchar_t symbol_q = L'\x24C6';
  mvwprintw(win_start, 2, 7, "TO EXIT PRESS %lc  ", symbol_q);
  wattroff(win_start, A_BLINK);
  wrefresh(win_start);

  char input_start_button;
  while (1) {
    input_start_button = getch();
    if (input_start_button == 's' || input_start_button == 'q' ||
        input_start_button == 'Q')
      break;
  }
  if (input_start_button == 's') exit = 1;

  for (int i = 0; i < POLE_H; i++) free(start_matrix[i]);
  free(start_matrix);
  return exit;
}

// вывод на экран стартовой матрицы для декомпозиции
void print_start_pic(char **start_matrix) {
  for (int i = 0; i < POLE_H; i++) {
    for (int j = 0; j < POLE_W; j++) {
      if (start_matrix[i][j] == '1') {
        if (i == 2 || i == 15 || i == 22 || j == 7 || j == 50 ||
            (j == 19 && i > 15) || (j == 37 && i > 15)) {
          // окантовка фигуры - белым цветос
          attron(COLOR_PAIR(4));
          printw(" ");
          attroff(COLOR_PAIR(4));
        } else if (i > 15 && j > 19 && j < 37) {
          // цифры 21 - зеленым цветом
          attron(COLOR_PAIR(10));
          printw(" ");
          attroff(COLOR_PAIR(10));
        } else {
          // все остальное (надпись тетрис) - желтым цветом
          attron(COLOR_PAIR(7));
          printw(" ");
          attroff(COLOR_PAIR(7));
        }
      } else
        printw(" ");
    }
    usleep(80000);
    refresh();
    printw("\n");
  }
}

// записываем матрицу из файла (все пиксельные "картинки")
void file_to_matrix(char *file_name, char **matrix) {
  FILE *file = fopen(file_name, "r");

  char c = '0';
  for (int i = 0; i < POLE_H; i++) {
    for (int j = 0; j < POLE_W; j++) {
      fscanf(file, "%c", &c);
      matrix[i][j] = c;
    }
  }
  fclose(file);
}

// вывод всего интерфейса основной части
void interface(GameInfo_t GameInf, FigureInfo_t Figure) {
  draw_backgroud();
  draw_high_score(GameInf.high_score);
  draw_help_menu();
  draw_play_arena(GameInf.field);
  draw_info_panel(GameInf);
  draw_window_next_figure(GameInf.next, Figure);
}

// вывод на экран фона (сделал пресечением окон)
void draw_backgroud() {
  // Определяем размеры и положение одной ячейки
  int startx = 0, starty = 0, width = 3, height = 2;

  // заполняем поле ячейками
  for (int i = 0; i < POLE_H; i += 1) {
    for (int j = 2; j < POLE_W - 6; j += 2) {
      if (!((i >= 1 && i <= 23 && j >= 7 && j <= 30) ||
            (i >= 1 && i <= 8 && j >= 32 && j <= 47) ||
            (i >= 9 && i <= 14 && j >= 32 && j <= 47) ||
            (i >= 15 && i <= 19 && j >= 32 && j <= 47) ||
            (i >= 20 && i <= 23 && j >= 32 && j <= 47))) {
        starty = i;
        startx = j;
        // Создаем новое окно
        WINDOW *win = newwin(height, width, starty, startx);
        wbkgd(win, COLOR_PAIR(3));
        // wbkgd(win, COLOR_PAIR(9));
        box(win, 0, 0);
        wrefresh(win);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
      }
    }
  }

  refresh();
  mvprintw(32, 18, "2024. frostdra@student.21-school.ru");
  refresh();
}

void draw_high_score(int high_score) {
  char str[1000] = {0};
  sprintf(str, "%d", high_score);

  // Создаем окно отражения лидер по очкам
  int startx = 34, starty = 20, width = 14, height = 4;
  WINDOW *win_score_lider = newwin(height, width, starty, startx);
  refresh();  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!

  wbkgd(win_score_lider, COLOR_PAIR(5));
  box(win_score_lider, 0, 0);
  wattron(win_score_lider, A_BOLD);  // устанавливаем шрифт жирным

  mvwprintw(win_score_lider, 0, 2, "HIGH SCORE");
  // пример
  wattron(win_score_lider, COLOR_PAIR(2));
  int len_score = 1 + (12 - strlen(str)) / 2;
  mvwprintw(win_score_lider, 2, len_score, "%d", high_score);
  wattroff(win_score_lider, COLOR_PAIR(2));
  wattroff(win_score_lider, A_BOLD);
  wrefresh(win_score_lider);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
}

// вывод на экран поля помощи
void draw_help_menu() {
  wchar_t symbol_left = L'\x140A';   // стрелка влево
  wchar_t symbol_right = L'\x1405';  // стрелка вправо
  wchar_t symbol_down = L'\x1401';   // стрелка вниз
  wchar_t symbol_p = L'\x24C5';      // кнопка p
  wchar_t symbol_q = L'\x24C6';      // кнопка q

  attron(COLOR_PAIR(3));
  attron(A_BOLD);
  mvprintw(25, 10, "%lc PAUSE", symbol_p);
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(3));
  mvprintw(27, 10, "%lc EXIT", symbol_q);
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(3));
  mvprintw(26, 36, "%lc MOVE LEFT", symbol_left);
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(3));
  mvprintw(28, 36, "%lc MOVE RIGHT", symbol_right);
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(3));
  mvprintw(30, 36, "%lc MOVE DOWN", symbol_down);
  attroff(COLOR_PAIR(3));
  attroff(A_BOLD);

  // Определяем размеры и положение окна
  int startx = 10, starty = 29, width = 16, height = 2;

  // Создаем новое окно
  WINDOW *win_space = newwin(height, width, starty, startx);
  wbkgd(win_space, COLOR_PAIR(3));
  box(win_space, 0, 0);
  wattron(win_space, A_BOLD);
  mvwprintw(win_space, 0, 6, "SPACE");
  mvwprintw(win_space, 1, 3, "TURN FIGURE");
  wattroff(win_space, A_BOLD);

  refresh();  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
  wrefresh(win_space);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
}

void draw_play_arena(int **field) {
  // Определяем размеры и положение окна
  int startx, starty, width, height;
  height = 22;
  width = 22;
  starty = 2;
  startx = 9;
  // Создаем новое окно
  WINDOW *win_play_arena = newwin(height, width, starty, startx);
  refresh();  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!

  box(win_play_arena, 0, 0);

  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (field[i][j] == 0) {
        wattron(win_play_arena, COLOR_PAIR(2));
        mvwprintw(win_play_arena, i + 1, j * 2 + 1,
                  "  ");  // +1 потомучто не рисуем на границе j*2 потому что
                          // "пиксель" - два пробела
        wattroff(win_play_arena, COLOR_PAIR(2));
      } else {
        wattron(win_play_arena, COLOR_PAIR(field[i][j]));
        mvwprintw(win_play_arena, i + 1, j * 2 + 1, "  ");
        wattroff(win_play_arena, COLOR_PAIR(field[i][j]));
      }
    }
  }

  wrefresh(win_play_arena);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
}

void draw_window_next_figure(int **next, FigureInfo_t Figure) {
  int color_next_figure = 0;
  if (Figure.next_figure_number == 0)
    color_next_figure = 8;
  else if (Figure.next_figure_number == 1)
    color_next_figure = 13;
  else if (Figure.next_figure_number == 2)
    color_next_figure = 9;
  else if (Figure.next_figure_number == 3)
    color_next_figure = 7;
  else if (Figure.next_figure_number == 4)
    color_next_figure = 10;
  else if (Figure.next_figure_number == 5)
    color_next_figure = 14;
  else if (Figure.next_figure_number == 6)
    color_next_figure = 4;

  // Определяем размеры и положение окна
  int startx = 34, starty = 2, width = 14, height = 7;

  // Создаем окно след фигуры
  WINDOW *win_next = newwin(height, width, starty, startx);
  box(win_next, 0, 0);
  wattron(win_next, A_BOLD);  // устанавливаем шрифт жирным
  mvwprintw(win_next, 0, 1, "NEXT  FIGURE");

  wbkgd(win_next, COLOR_PAIR(6));

  for (int i = 0; i < FIGURE_H; i++) {
    for (int j = 0; j < FIGURE_W; j++) {
      if (next[i][j] == 0) {
        mvwprintw(win_next, i + 2, j * 2 + 3,
                  "  ");  // j*2 потому что "пиксель" - два пробела
        // mvwprintw(win_next, i + 2, j + 3, "0"); // j*2 потому что "пиксель" -
        // два пробела
      } else {
        wattron(win_next, COLOR_PAIR(color_next_figure));
        mvwprintw(win_next, i + 2, j * 2 + 3, "  ");
        // mvwprintw(win_next, i + 2, j + 3, "1");
        wattroff(win_next, COLOR_PAIR(color_next_figure));
      }
    }
  }

  wattroff(win_next, A_BOLD);

  wrefresh(win_next);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
}

void draw_info_panel(GameInfo_t GameInf) {
  char str_level[1000] = {0};
  sprintf(str_level, "%d", GameInf.level);

  char str_score[1000] = {0};
  sprintf(str_score, "%d", GameInf.score);

  // Определяем размеры и положение окна
  int startx = 34, starty = 10, width = 14, height = 4;
  WINDOW *win_level = newwin(height, width, starty, startx);
  refresh();  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
  box(win_level, 0, 0);
  wattron(win_level, A_BOLD);  // устанавливаем шрифт жирным
  mvwprintw(win_level, 0, 2, "   LEVEL   ");
  int len_level = 1 + (12 - strlen(str_level)) / 2;
  mvwprintw(win_level, 2, len_level, "%d", GameInf.level);
  wattroff(win_level, A_BOLD);
  wrefresh(win_level);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!

  // Создаем окно отражения очков
  starty = 15;
  WINDOW *win_score = newwin(height, width, starty, startx);
  refresh();  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
  box(win_score, 0, 0);
  wattron(win_score, A_BOLD);  // устанавливаем шрифт жирным
  mvwprintw(win_score, 0, 2, "   SCORE  ");
  int len_score = 1 + (12 - strlen(str_score)) / 2;
  mvwprintw(win_score, 2, len_score, "%d", GameInf.score);
  wattroff(win_score, A_BOLD);  // устанавливаем шрифт жирным
  wrefresh(win_score);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
}

void apply_use_color() {
  start_color();

  init_pair(0, COLOR_WHITE, COLOR_WHITE);
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_color(COLOR_MAGENTA, 500, 500, 500);

  // Определяем цветовую пару
  init_pair(3, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(4, COLOR_BLACK, COLOR_WHITE);
  init_pair(5, COLOR_RED, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_CYAN, COLOR_CYAN);
  init_pair(8, COLOR_RED, COLOR_RED);
  init_pair(9, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(10, COLOR_GREEN, COLOR_GREEN);
  init_pair(11, COLOR_GREEN, COLOR_BLACK);
  init_pair(12, COLOR_BLUE, COLOR_BLACK);
  init_pair(13, COLOR_BLUE, COLOR_BLUE);
  init_pair(14, COLOR_MAGENTA, COLOR_MAGENTA);

  init_pair(100, COLOR_BLACK, COLOR_BLACK);
}

void salut_new_record(int new_record) {
  char **salut_0 = malloc(POLE_H * sizeof(char *));
  for (int i = 0; i < POLE_H; i++) salut_0[i] = malloc(POLE_W * sizeof(char));
  file_to_matrix("gui/cli/waltboy.txt", salut_0);

  print_new_record(salut_0);

  int startx = 10, starty = 4, width = 35, height = 8;
  WINDOW *win_new_lider = newwin(height, width, starty, startx);

  box(win_new_lider, 0, 0);
  wattron(win_new_lider, A_BOLD);
  mvwprintw(win_new_lider, 1, 8, " CONGRATULATIONS!!!");
  mvwprintw(win_new_lider, 3, 3, "You have set a new record!!!");
  mvwprintw(win_new_lider, 4, 8, "%d points!!!", new_record);
  mvwprintw(win_new_lider, 6, 3, "Press any key except s and q)).");
  // usleep(80000);

  wattroff(win_new_lider, A_BOLD);
  wrefresh(win_new_lider);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!

  for (int i = 0; i < POLE_H; i++) free(salut_0[i]);
  free(salut_0);
}

void print_new_record(char **matrix) {
  int i = 0, color = 0;
  while (i <= 11) {
    if (i == 0 || i == 6)
      color = 1;
    else if (i == 1 || i == 7)
      color = 2;
    else if (i == 2 || i == 8)
      color = 5;
    else if (i == 3 || i == 9)
      color = 6;
    else if (i == 4 || i == 10)
      color = 11;
    else if (i == 5 || i == 11)
      color = 12;

    for (int i = 0; i < POLE_H; i++) {
      for (int j = 0; j < POLE_W; j++) {
        if (i > 24 || (j < 22 && (i > 18 && i <= 23))) {
          // надпись новый рекод - белым
          attron(COLOR_PAIR(2));
          mvprintw(i, j, "%c", matrix[i][j]);
          attroff(COLOR_PAIR(2));
        } else {
          attron(COLOR_PAIR(color));
          mvprintw(i, j, "%c", matrix[i][j]);
          attroff(COLOR_PAIR(color));
        }
      }
      refresh();
    }

    usleep(500000);
    refresh();
    i++;
  }
}

void game_over(int points) {
  //  создал под каждую стриницу свою матрицу
  char **game_over_matrix = malloc(POLE_H * sizeof(char *));
  for (int i = 0; i < POLE_H; i++)
    game_over_matrix[i] = malloc(POLE_W * sizeof(char));

  file_to_matrix("gui/cli/game_over.txt", game_over_matrix);

  print_game_over(game_over_matrix);

  // Определяем размеры и положение окна
  int startx = 10, starty = 8, width = 35, height = 8;
  // Создаем новое окно
  WINDOW *win_game_over = newwin(height, width, starty, startx);

  box(win_game_over, 0, 0);
  mvwprintw(win_game_over, 1, 8, " Auuuuuucccchhhhh!!!");
  mvwprintw(win_game_over, 3, 1, "Game is over whithout new record.");
  mvwprintw(win_game_over, 4, 4, "Your score is %d points!!!", points);
  mvwprintw(win_game_over, 6, 1, "Press any key except s and q)).");
  wrefresh(win_game_over);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!

  for (int i = 0; i < POLE_H; i++) free(game_over_matrix[i]);
  free(game_over_matrix);
}

void print_game_over(char **matrix) {
  int i = 0, color = 0;
  while (i <= 6) {
    if (i % 2 == 0)
      color = 5;
    else
      color = 6;

    for (int i = 0; i < POLE_H; i++) {
      for (int j = 0; j < POLE_W; j++) {
        if (i > 21) {
          // надпись game over - белым
          attron(COLOR_PAIR(2));
          mvprintw(i, j, "%c", matrix[i][j]);
          attroff(COLOR_PAIR(2));
        } else {
          attron(COLOR_PAIR(color));
          mvprintw(i, j, "%c", matrix[i][j]);
          attroff(COLOR_PAIR(color));
        }
      }
      refresh();
    }

    usleep(500000);
    refresh();
    i++;
  }
}

// void print_matrix(char **matrix, int color)
// {
//     for (int i = 0; i < POLE_H; i++)
//     {
//         for (int j = 0; j < POLE_W; j++)
//         {
//             attron(COLOR_PAIR(color));
//             mvprintw(i, j, "%c", matrix[i][j]);
//             attroff(COLOR_PAIR(color));
//             // if (matrix[i][j] == '1')
//             // {
//             //     attron(COLOR_PAIR(color));
//             //     mvprintw(i, j, "#");
//             //     attroff(COLOR_PAIR(color));
//             // }
//             // else
//             //     mvprintw(i, j, " ");
//         }
//         refresh();
//         // printw("\n");
//     }
// }

char quit_or_repeat() {
  char result = '0';
  // Определяем размеры и положение окна
  int startx = 0, starty = 0, width = 60, height = 33;
  // Создаем новое окно
  WINDOW *win_quit = newwin(height, width, starty, startx);
  // refresh(); // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!

  // box(win_quit, 0, 0);
  wborder(win_quit, ACS_DIAMOND, ACS_DIAMOND, ACS_DIAMOND, ACS_DIAMOND,
          ACS_DIAMOND, ACS_DIAMOND, ACS_DIAMOND, ACS_DIAMOND);
  wattron(win_quit, A_BOLD);
  wattron(win_quit, A_BLINK);
  mvwprintw(win_quit, 10, 25, "GAME OVER");
  wchar_t symbol_s = L'\x24C8', simbol_q = L'\x24C6';
  mvwprintw(win_quit, 15, 10, "Please, push %lc  to repeat or to quit %lc",
            symbol_s, simbol_q);
  wattroff(win_quit, A_BOLD);
  wattroff(win_quit, A_BLINK);
  result = getch();

  wrefresh(win_quit);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
  return result;
}

void pause_menu() {
  char c = '0';
  wchar_t symbol_p = L'\x24C5';  // кнопка p
  while (c != 'p' && c != 'P') {
    int startx = 5, starty = 5, width = 45, height = 20;
    // Создаем новое окно
    WINDOW *win_pause = newwin(height, width, starty, startx);

    wbkgd(win_pause, COLOR_PAIR(12));
    wborder(win_pause, ACS_BOARD, ACS_BOARD, ACS_BOARD, ACS_BOARD, ACS_BOARD,
            ACS_BOARD, ACS_BOARD, ACS_BOARD);
    wattron(win_pause, A_BOLD);
    wattron(win_pause, A_BLINK);

    wattron(win_pause, COLOR_PAIR(2));
    mvwprintw(win_pause, 2, 20, "PAUSE");
    wattroff(win_pause, A_BLINK);
    mvwprintw(win_pause, 4, 3, "Please, push %lc  to back the game", symbol_p);
    wattroff(win_pause, A_BOLD);
    mvwprintw(win_pause, 5, 3, "Points are accumulated as follows:");
    mvwprintw(win_pause, 6, 5, "* row is 100 points;");

    mvwprintw(win_pause, 7, 5, "* 2 rows is 300 points;");
    mvwprintw(win_pause, 8, 5, "* 3 rows is 700 points;");
    mvwprintw(win_pause, 9, 5, "* 4 rows is 1500 points.");

    mvwprintw(win_pause, 11, 3, "Each time a player earns 600 points, the");
    mvwprintw(win_pause, 12, 3, "level increases by 1.");

    mvwprintw(win_pause, 13, 3, "The maximum number of levels is 10.");
    mvwprintw(win_pause, 15, 3, "Fave fun, epta.");

    wattroff(win_pause, COLOR_PAIR(2));

    wrefresh(win_pause);  // САМОЕ ВАЖНОЕ!! БЕЗ ЭТОГО НЕ СРАБАТЫВАЕТ!!!!
    c = getch();
  }
  clear();
}

void init_all() {
  srand(time(NULL));
  setlocale(LC_ALL, "");
  initscr();    // инициализация ncurses
  curs_set(0);  // убираем отображение курсора
  noecho();

  keypad(stdscr, TRUE);  // вклбчение режима обработки стрелок (чтобы заработало
                         // KEY_LEFT-KEY_DOWN...)

  apply_use_color();

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)
}

void deinit_all() {
  free_GameInfo();
  free_FigureInfo();
  refresh();
  endwin();  // завершение работы с ncurses
}

// новая игра
void new_game(GameInfo_t *GameInf, FigureInfo_t *Figure) {
  // перезапуск игры

  free_GameInfo();
  init_GameInfo();

  free_FigureInfo();
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();  // геннерим след фигуру GameInfo
  *GameInf = updateCurrentState();  // записываем в поле фигуру след фигуру
  *Figure = ExportFigure();

  clear();
  halfdelay(1);  // выкл ожидание ввода с клавы
}

// // основное действо
// void action(int c, GameInfo_t *GameInf, FigureInfo_t Figure)
// {
//   if (c == KEY_LEFT) // влево стрелка
//   {
//     if (!is_cant_move_left())
//     {
//       cut_figure_from_field();
//       move_left();
//       *GameInf = updateCurrentState();
//       usleep(100000); // Добавляем задержку в 100 миллисекунд
//       interface(*GameInf, Figure);
//     }
//   }
//   else if (c == KEY_RIGHT) // вправо стрелка
//   {
//     if (!is_cant_move_right())
//     {
//       cut_figure_from_field();
//       move_right();
//       *GameInf = updateCurrentState();
//       usleep(100000); // Добавляем задержку в 100 миллисекунд
//       interface(*GameInf, Figure);
//     }
//   }
//   else if (c == ' ') // пробел
//   {
//     if (!is_cant_move_turn())
//     {
//       cut_figure_from_field();
//       move_turn();
//       *GameInf = updateCurrentState();
//       usleep(100000); // Добавляем задержку в 100 миллисекунд
//       interface(*GameInf, Figure);
//     }
//   }
//   else if (c == KEY_DOWN) // вниз стрелка
//   {
//     while (!is_cant_move_down())
//     {
//       cut_figure_from_field();
//       move_down();
//       *GameInf = updateCurrentState();
//     }
//   }
// }

void game_finish(int c, GameInfo_t *GameInf, FigureInfo_t *Figure) {
  usleep(2000000);
  cbreak();  // dозвращаем нормальный режим ожидания ввода
  if (GameInf->score > GameInf->high_score) {
    save_new_record();
    salut_new_record(GameInf->score);
  } else
    game_over(GameInf->score);

  while (1) {
    c = quit_or_repeat();
    if (c == 's' || c == 'q' || c == 'S' || c == 'Q') break;
  }

  if (c == 's' || c == 'S') new_game(GameInf, Figure);
}

// int pause_and_finish_key(int *c, GameInfo_t *GameInf)
// {
//   int flag = 0;
//   if (*c == 'p')
//   {
//     pause_menu();
//     *c = '0';
//   }
//   if (*c == 'q')
//   {
//     GameInf->pause = 2;
//     flag = 1;
//   }
//   return flag;
// }