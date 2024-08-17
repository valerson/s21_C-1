#include <check.h>
#include <ncurses.h>
#include <string.h>

#include "brick_game/tetris/backend.h"
#include "gui/cli/interface.h"

START_TEST(test_tetris_init) {
  init_GameInfo();
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  GameInfo_t GameInf = updateCurrentState();
  ck_assert_int_eq(GameInf.level, 0);
  ck_assert_int_eq(GameInf.score, 0);
  ck_assert_int_eq(GameInf.speed, 10);
  ck_assert_int_eq(GameInf.pause, 0);
  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_move_down_1) {
  for (int i = 0; i < 50; i++) {
    srand(time(NULL));
    setlocale(LC_ALL, "");

    init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
    init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

    start_figure();
    FigureInfo_t Figure = ExportFigure();
    if (i > 4 && i <= 18) {
      GameInfo_t GameInf = updateCurrentState();
      for (int j = 0; j < FIELD_W; j++) {
        if (j < X_START + 1) GameInf.field[i][j] = 1;
      }
    }

    get_params_figure(Figure.figure);

    while (!is_cant_move_down()) {
      cut_figure_from_field();
      move_down();
    }
    Figure = ExportFigure();
    get_params_figure(Figure.figure);

    if (i > 4 && i <= 18 && Figure.figure_number == 0 &&
        (Figure.rotate == 0 || Figure.rotate == 2))
      ck_assert_int_eq(Figure.y_down, i - 1);
    else
      ck_assert_int_eq(Figure.y_down, FIELD_H - 1);

    if (i > 4 && i <= 18) {
      GameInfo_t GameInf = updateCurrentState();
      for (int j = 0; j < FIELD_W; j++) {
        if (j < X_START + 1) GameInf.field[i][j] = 0;
      }
    }

    free_GameInfo();
    free_FigureInfo();
  }
}
END_TEST

START_TEST(test_move_down_2) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)
  GameInfo_t GameInf = updateCurrentState();
  for (int j = 0; j < FIELD_W; j++) {
    GameInf.field[FIELD_H - 1][j] = 1;
  }

  start_figure();
  FigureInfo_t Figure = ExportFigure();

  get_params_figure(Figure.figure);

  while (!is_cant_move_down()) {
    cut_figure_from_field();
    move_down();
  }
  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.y_down, FIELD_H - 2);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_move_down_3) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();

  get_params_figure(Figure.figure);

  while (!is_cant_move_down()) {
    cut_figure_from_field();
    move_down();
  }
  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.y_down, FIELD_H - 1);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_move_down_4) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();
  GameInfo_t GameInf = updateCurrentState();

  get_params_figure(Figure.figure);
  int y_down_start = Figure.y_down;

  func_move_down(&GameInf, Figure);
  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.y_down, y_down_start + 1);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_move_right_1) {
  for (int i = 0; i < 90; i++) {
    srand(time(NULL));
    setlocale(LC_ALL, "");

    init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
    init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

    start_figure();
    FigureInfo_t Figure = ExportFigure();

    if (i > 10 && i < 90) {
      GameInfo_t GameInf = updateCurrentState();
      for (int j = 0; j < FIELD_W; j++) {
        if (j > X_START) GameInf.field[0][j] = 1;
      }
    }

    get_params_figure(Figure.figure);

    int x_start = Figure.x;
    if (i > 10 && i < 90) {
      int k = 0;
      while (!is_cant_move_right()) {
        cut_figure_from_field();
        move_right();
        k++;
      }
      Figure = ExportFigure();
      get_params_figure(Figure.figure);
      ck_assert_int_eq(Figure.x, x_start + k);
    } else {
      if (!is_cant_move_right()) {
        cut_figure_from_field();
        move_right();
      }
      Figure = ExportFigure();
      get_params_figure(Figure.figure);
      ck_assert_int_eq(Figure.x, x_start + 1);
    }

    free_GameInfo();
    free_FigureInfo();
  }
}
END_TEST

START_TEST(test_move_left_1) {
  for (int i = 0; i < 90; i++) {
    srand(time(NULL));
    setlocale(LC_ALL, "");

    init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
    init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

    start_figure();
    FigureInfo_t Figure = ExportFigure();

    if (i > 10 && i < 90) {
      GameInfo_t GameInf = updateCurrentState();
      for (int j = 0; j < FIELD_W; j++) {
        if (j < X_START + 1) GameInf.field[0][j] = 1;
      }
    }

    get_params_figure(Figure.figure);

    int x_start = Figure.x;
    if (i > 10 && i < 90) {
      int k = 0;
      while (!is_cant_move_left()) {
        cut_figure_from_field();
        move_left();
        k++;
      }
      Figure = ExportFigure();
      get_params_figure(Figure.figure);
      ck_assert_int_eq(Figure.x, x_start - k);
    } else {
      if (!is_cant_move_left()) {
        cut_figure_from_field();
        move_left();
      }
      Figure = ExportFigure();
      get_params_figure(Figure.figure);
      ck_assert_int_eq(Figure.x, x_start - 1);
    }

    free_GameInfo();
    free_FigureInfo();
  }
}
END_TEST

START_TEST(test_turn_1) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();

  get_params_figure(Figure.figure);

  int rotate_start = Figure.rotate;
  if (!is_cant_move_turn()) {
    cut_figure_from_field();
    move_turn();
  }
  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.rotate, (rotate_start + 1) % 4);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_update_figure) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();

  get_params_figure(Figure.figure);

  int next_figure = Figure.next_figure_number;
  update_figure();
  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.figure_number, next_figure);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_check_new_figure_1) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();

  int can_new_figure = check_new_figure_at_field();
  ck_assert_int_eq(can_new_figure, 0);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_check_full_line) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  GameInfo_t GameInf = updateCurrentState();
  start_figure();

  for (int j = 0; j < FIELD_W; j++) {
    GameInf.field[0][j] = 1;
  }
  check_full_line();
  GameInf = updateCurrentState();

  ck_assert_int_eq(GameInf.score, 100);
  ck_assert_int_eq(GameInf.level, 0);
  ck_assert_int_eq(GameInf.speed, 10);

  for (int j = 0; j < FIELD_W; j++) {
    GameInf.field[0][j] = 1;
    GameInf.field[1][j] = 1;
  }
  check_full_line();
  GameInf = updateCurrentState();

  ck_assert_int_eq(GameInf.score, 400);

  for (int j = 0; j < FIELD_W; j++) {
    GameInf.field[0][j] = 1;
    GameInf.field[1][j] = 1;
    GameInf.field[2][j] = 1;
  }
  check_full_line();
  GameInf = updateCurrentState();

  ck_assert_int_eq(GameInf.score, 1100);

  for (int j = 0; j < FIELD_W; j++) {
    GameInf.field[0][j] = 1;
    GameInf.field[1][j] = 1;
    GameInf.field[2][j] = 1;
    GameInf.field[3][j] = 1;
  }
  check_full_line();
  GameInf = updateCurrentState();

  ck_assert_int_eq(GameInf.score, 2600);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_new_record) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  GameInfo_t GameInf = updateCurrentState();
  GameInf.score = 1000;
  int high_score = GameInf.high_score;

  save_new_record();
  ck_assert_int_eq(GameInf.score, 1000);

  FILE *file = fopen("brick_game/tetris/high_score.txt", "w");
  char str[250] = "";
  sprintf(str, "%d", high_score);
  fputs(str, file);
  fclose(file);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_parsing_input_and_userinput_KEY_LEFT) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();
  get_params_figure(Figure.figure);

  int x_start = Figure.x;
  int c = KEY_LEFT;
  parsing_input(c, false);

  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.x, x_start - 1);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_parsing_input_and_userinput_KEY_LEFT_2) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();
  get_params_figure(Figure.figure);

  int x_start = Figure.x;
  int c = KEY_LEFT;
  parsing_input(c, true);

  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert(Figure.x < x_start - 2);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_parsing_input_and_userinput_KEY_RIGHT) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();
  get_params_figure(Figure.figure);

  int x_start = Figure.x;
  int c = KEY_RIGHT;
  parsing_input(c, false);

  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.x, x_start + 1);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_parsing_input_and_userinput_KEY_RIGHT_2) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();
  get_params_figure(Figure.figure);

  int x_start = Figure.x;
  int c = KEY_RIGHT;
  parsing_input(c, true);

  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert(Figure.x > x_start + 2);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_parsing_input_and_userinput_KEY_DOWN) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();

  get_params_figure(Figure.figure);

  int c = KEY_DOWN;
  parsing_input(c, false);
  // if (!is_cant_move_down())
  // {
  //     cut_figure_from_field();
  //     move_down();
  // }
  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.y_down, FIELD_H - 1);

  // start_figure();
  // FigureInfo_t Figure = ExportFigure();
  // get_params_figure(Figure.figure);

  // int y_down_start = Figure.y_down;
  // int y_up_start = Figure.y_up;
  // int c = KEY_DOWN;
  // parsing_input(c);

  // Figure = ExportFigure();
  // get_params_figure(Figure.figure);
  // ck_assert_int_eq(Figure.y_down, y_down_start);
  // ck_assert_int_eq(Figure.y_up, y_up_start);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_parsing_input_and_userinput_KEY_TURN) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)

  start_figure();
  FigureInfo_t Figure = ExportFigure();
  get_params_figure(Figure.figure);

  int rotate_start = Figure.rotate;
  int c = ' ';
  parsing_input(c, false);

  Figure = ExportFigure();
  get_params_figure(Figure.figure);
  ck_assert_int_eq(Figure.rotate, (rotate_start + 1) % 4);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

START_TEST(test_timer) {
  unsigned long long time_start = current_microseconds();
  usleep(1000000);
  unsigned long long time_finish = current_microseconds();
  ck_assert(time_finish - time_start >=
            1000000);  // проверяем, что прошло больше 1000000 мкрсек
}
END_TEST

START_TEST(test_quit_and_pause) {
  srand(time(NULL));
  setlocale(LC_ALL, "");

  init_GameInfo();  // инициализация структуры GameInfo (см backend.c)
  init_FigureInfo();  // инициализация структуры FugureInfo (см backend.c)
  GameInfo_t GameInf = updateCurrentState();

  int c = 'q';
  parsing_input(c, false);
  GameInf = updateCurrentState();
  ck_assert_int_eq(GameInf.pause, 2);

  c = 'p';
  parsing_input(c, false);
  GameInf = updateCurrentState();
  ck_assert_int_eq(GameInf.pause, 0);

  c = KEY_UP;
  int score = GameInf.score;
  parsing_input(c, false);
  GameInf = updateCurrentState();
  ck_assert_int_eq(GameInf.score, score);

  free_GameInfo();
  free_FigureInfo();
}
END_TEST

Suite *tetris_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_tetris");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_tetris_init);
  tcase_add_test(tc_core, test_move_down_1);
  tcase_add_test(tc_core, test_move_down_2);
  tcase_add_test(tc_core, test_move_down_3);
  tcase_add_test(tc_core, test_move_down_4);
  tcase_add_test(tc_core, test_move_right_1);
  tcase_add_test(tc_core, test_move_left_1);
  tcase_add_test(tc_core, test_turn_1);
  tcase_add_test(tc_core, test_update_figure);
  tcase_add_test(tc_core, test_check_new_figure_1);
  tcase_add_test(tc_core, test_check_full_line);
  tcase_add_test(tc_core, test_new_record);
  tcase_add_test(tc_core, test_parsing_input_and_userinput_KEY_LEFT);
  tcase_add_test(tc_core, test_parsing_input_and_userinput_KEY_LEFT_2);
  tcase_add_test(tc_core, test_parsing_input_and_userinput_KEY_RIGHT);
  tcase_add_test(tc_core, test_parsing_input_and_userinput_KEY_RIGHT_2);
  tcase_add_test(tc_core, test_parsing_input_and_userinput_KEY_DOWN);
  tcase_add_test(tc_core, test_parsing_input_and_userinput_KEY_TURN);
  tcase_add_test(tc_core, test_timer);
  tcase_add_test(tc_core, test_quit_and_pause);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s_tetris;
  SRunner *sr;

  s_tetris = tetris_suite();

  sr = srunner_create(s_tetris);

  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}