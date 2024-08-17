#include "backend.h"

#include "../../gui/cli/interface.h"

/*
инициализируя тут по факту мы уже завели эту переменну.
и можем ее в функции внутри этого бэкэнд.с не отправлять
*/
static GameInfo_t GameInfo;
static FigureInfo_t FigureInfo;
static UserAction_t useraction;  // я немного не понял зачем вообще это писать,
                                 // но функция была в задании

// полная инициализация структуры гейминфо включая создание нулевых матриц
void init_GameInfo() {
  GameInfo.field = calloc(FIELD_H, sizeof(int *));
  for (int i = 0; i < FIELD_H; i++)
    GameInfo.field[i] = calloc(FIELD_W, sizeof(int));

  GameInfo.next = calloc(FIGURE_H, sizeof(int *));
  for (int i = 0; i < FIGURE_H; i++)
    GameInfo.next[i] = calloc(FIGURE_W, sizeof(int));

  GameInfo.level = 0;
  GameInfo.score = 0;
  GameInfo.speed = SPEED_START;
  GameInfo.pause = 0;

  FILE *file = fopen("brick_game/tetris/high_score.txt", "r");
  char str[1000] = {0};
  fgets(str, 1000, file);
  GameInfo.high_score = strtol(str, NULL, 10);
  fclose(file);
}

// освобождение памяти матриц в структуре гейминфо
void free_GameInfo() {
  for (int i = 0; i < FIELD_H; i++) free(GameInfo.field[i]);
  free(GameInfo.field);

  for (int i = 0; i < FIGURE_H; i++) free(GameInfo.next[i]);
  free(GameInfo.next);
}

// полная инициализация структуры фигуринфо включая создание нулевых матриц
void init_FigureInfo() {
  FigureInfo.figure = calloc(FIGURE_H, sizeof(int *));
  for (int i = 0; i < FIGURE_H; i++)
    FigureInfo.figure[i] = calloc(FIELD_W, sizeof(int));

  FigureInfo.next_figure = calloc(FIGURE_H, sizeof(int *));
  for (int i = 0; i < FIGURE_H; i++)
    FigureInfo.next_figure[i] = calloc(FIGURE_W, sizeof(int));

  FigureInfo.figure_number = 0;
  FigureInfo.x = X_START;
  FigureInfo.x_left = 0;
  FigureInfo.x_right = 0;
  FigureInfo.y = 0;
  FigureInfo.y_down = 0;
  FigureInfo.y_up = 0;
  FigureInfo.rotate = 0;
}

// освобождение памяти матриц в структуре Фигуринфо
void free_FigureInfo() {
  for (int i = 0; i < FIGURE_H; i++) free(FigureInfo.figure[i]);
  free(FigureInfo.figure);

  for (int i = 0; i < FIGURE_H; i++) free(FigureInfo.next_figure[i]);
  free(FigureInfo.next_figure);
}

GameInfo_t updateCurrentState() {
  for (int i = 0; i < FIELD_H; i++) {
    if (i <= FigureInfo.y_down && i >= FigureInfo.y_up &&
        FigureInfo.y_down < FIELD_H) {
      for (int j = FigureInfo.x + FigureInfo.x_left;
           j <= FigureInfo.x + FigureInfo.x_right; j++) {
        GameInfo.field[i][j] +=
            FigureInfo.figure[i - FigureInfo.y_up][j - FigureInfo.x];
      }
    }
  }

  // копируем фигуру из поля след в нект поле поля
  for (int i = 0; i < FIGURE_H; i++) {
    for (int j = 0; j < FIGURE_W; j++) {
      GameInfo.next[i][j] = FigureInfo.next_figure[i][j];
    }
  }

  return GameInfo;
}

FigureInfo_t ExportFigure() { return FigureInfo; }

// вырезаем фигуру из поля.
void cut_figure_from_field() {
  int h = 0;
  for (int i = 0; i < FIELD_H; i++) {
    if (i <= FigureInfo.y_down && i >= FigureInfo.y_up &&
        FigureInfo.y_down < FIELD_H) {
      int w = FigureInfo.x_levo;
      for (int j = FigureInfo.x + FigureInfo.x_left;
           j <= FigureInfo.x + FigureInfo.x_right; j++) {
        GameInfo.field[i][j] -= FigureInfo.figure[h][w];
        w++;
      }
      h++;
    }
  }
}

// генерация фигуры из файла
int create_figure(int ***figure) {
  int random = rand() % 7;         // рандом 0-6
  int random_rotate = rand() % 4;  // рандом 0-3
  FigureInfo.rotate = random_rotate;
  FigureInfo.figure_number = random;

  for (int i = 0; i < FIGURE_H; i++) {
    for (int j = 0; j < FIGURE_W; j++) {
      (*figure)[i][j] =
          Figures[FigureInfo.figure_number][FigureInfo.rotate][i][j];
    }
  }

  return random;
}

// Рандом следующей фигуры
void start_figure() {
  // создали текущую фигуру
  FigureInfo.figure_number = create_figure(&FigureInfo.figure);
  int rotate = FigureInfo.rotate;
  int figure_number = FigureInfo.figure_number;

  // получение параметров фигуры
  get_params_figure(FigureInfo.figure);

  // расположили фигуру по центру поля
  FigureInfo.x = X_START;

  // записали параметры-константы
  FigureInfo.y = FigureInfo.y_down;
  FigureInfo.x_levo = FigureInfo.x_left;

  // создали тследующую фигуру
  FigureInfo.next_figure_number = create_figure(&FigureInfo.next_figure);

  FigureInfo.next_figure_number = FigureInfo.figure_number;
  FigureInfo.next_figure_rotate = FigureInfo.rotate;

  FigureInfo.rotate = rotate;
  FigureInfo.figure_number = figure_number;
}

// получение параметров фигуры
void get_params_figure(int **figure) {
  // определяем  y_up и y_verh
  FigureInfo.x_right = 0;
  FigureInfo.x_left = 3;
  FigureInfo.y_up = 3;
  FigureInfo.y_down = 0;

  for (int i = 0; i < FIGURE_H; i++) {
    for (int j = 0; j < FIGURE_W; j++) {
      if (figure[i][j] != 0) {
        if (i > FigureInfo.y_down) FigureInfo.y_down = i;
        if (i < FigureInfo.y_up) FigureInfo.y_up = i;
        if (j > FigureInfo.x_right) FigureInfo.x_right = j;
        if (j < FigureInfo.x_left) FigureInfo.x_left = j;
      }
    }
  }
}

// проверка на возможность движения вниз
int is_cant_move_down() {
  int flag = 0;
  if (FigureInfo.y_down <
      FIELD_H - 1)  // проверяем, что можно опуститься по глубине поля
  {
    for (int i = 0; i < FIELD_W; i++) {
      if (FigureInfo.y == 0) {
        // текущее поле фигуры ==1, следующее поле фигуры ==1
        if (FigureInfo.figure[FigureInfo.y][i] != 0 &&
            GameInfo.field[(FigureInfo.y_down + 1) % FIELD_H]
                          [FigureInfo.x + i] != 0) {
          flag = 1;
        }
      } else if (FigureInfo.y <= 1 || FigureInfo.figure_number == 4 ||
                 FigureInfo.figure_number == 5) {
        // текущее поле фигуры ==0, текущее поле поля ==1
        if ((FigureInfo.figure[FigureInfo.y][i] != 0 &&
             GameInfo.field[(FigureInfo.y_down + 1) % FIELD_H]
                           [FigureInfo.x + i] != 0) ||
            (FigureInfo.figure[FigureInfo.y][i] == 0 &&
             FigureInfo.figure[(FigureInfo.y - 1) % FIELD_H][i] != 0 &&
             GameInfo.field[(FigureInfo.y_down) % FIELD_H][FigureInfo.x + i] !=
                 0)) {
          flag = 1;
        }
      } else {
        if ((FigureInfo.figure[FigureInfo.y][i] != 0 &&
             GameInfo.field[(FigureInfo.y_down + 1) % FIELD_H]
                           [FigureInfo.x + i] != 0) ||
            (FigureInfo.figure[FigureInfo.y][i] == 0 &&
             FigureInfo.figure[(FigureInfo.y - 1) % FIELD_H][i] != 0 &&
             GameInfo.field[(FigureInfo.y_down) % FIELD_H][FigureInfo.x + i] !=
                 0) ||
            (FigureInfo.figure_number != 5 && FigureInfo.figure_number != 6 &&
             FigureInfo.figure[FigureInfo.y][i] == 0 &&
             FigureInfo.figure[FigureInfo.y - 2][i] != 0 &&
             GameInfo.field[(FigureInfo.y_down - 1) % FIELD_H]
                           [FigureInfo.x + i] != 0)) {
          flag = 1;
        }
      }

      if (flag) break;
    }
  } else
    flag = 1;
  return flag;
}

// движение фигуры вниз
void move_down() {
  FigureInfo.y_down += 1;
  FigureInfo.y_up += 1;
}

void update_figure() {
  // копируем фигуру из поля след в центр поля
  for (int i = 0; i < FIGURE_H; i++) {
    for (int j = 0; j < FIGURE_W; j++) {
      FigureInfo.figure[i][j] = GameInfo.next[i][j];
    }
  }
  int rotate = FigureInfo.next_figure_rotate;
  int figure_number = FigureInfo.next_figure_number;

  // получение параметров фигуры
  get_params_figure(FigureInfo.figure);

  // расположили фигуру по центру поля
  FigureInfo.x = X_START;

  // записали параметры-константы
  FigureInfo.y = FigureInfo.y_down;
  FigureInfo.x_levo = FigureInfo.x_left;
  // генерим новую след фигуру
  FigureInfo.next_figure_number = create_figure(&FigureInfo.next_figure);
  FigureInfo.next_figure_rotate = FigureInfo.rotate;
  FigureInfo.rotate = rotate;
  FigureInfo.figure_number = figure_number;
}

// дейсвтие - движение влево
void move_left() { FigureInfo.x -= 1; }

// проерка на движение налево
int is_cant_move_left() {
  // mvprintw(1, 1, "x_left %d", FigureInfo.x_levo);
  int flag = 0;
  if (FigureInfo.x + FigureInfo.x_left >
      0)  // проверяем, что можно переместиться влево по границам поля
  {
    // проверяем, что на след шаге нет фигуры
    for (int i = FigureInfo.y_down, i2 = FigureInfo.y; i >= FigureInfo.y_up;
         i--, i2--) {
      if (FigureInfo.x == 0) {
        // текущее поле фигуры ==1, следующее поле фигуры ==1
        if (FigureInfo.figure[i2][FigureInfo.x_left] != 0 &&
            GameInfo.field[i][(FigureInfo.x + FigureInfo.x_left - 1) %
                              FIELD_W] != 0) {
          flag = 1;
        }
      } else if (FigureInfo.x <= 1) {
        // текущее поле фигуры ==0, текущее поле поля ==1
        if ((FigureInfo.figure[i2][FigureInfo.x_left] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_left - 1) %
                               FIELD_W] != 0) ||
            (FigureInfo.figure[i2][FigureInfo.x_left] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_left + 1] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_left) % FIELD_W] !=
                 0)) {
          flag = 1;
        }
      } else {
        // текущее поле фигуры ==0, следующее поле фигуры ==0, послеследующее
        // поле фигуры ==1, текущее поле поля ==1 =====КОШМАР!!!!!
        if ((FigureInfo.figure[i2][FigureInfo.x_left] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_left - 1) %
                               FIELD_W] != 0) ||
            (FigureInfo.figure[i2][FigureInfo.x_left] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_left + 1] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_left) % FIELD_W] !=
                 0) ||
            (FigureInfo.figure[i2][FigureInfo.x_left] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_left + 1] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_left + 2] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_left) % FIELD_W] !=
                 0)) {
          flag = 1;
        }
      }

      if (flag) break;
    }
  } else {
    flag = 1;
  }
  return flag;
}

// дейсвтие - движение вправо
void move_right() { FigureInfo.x += 1; }

// проерка на движение направо
int is_cant_move_right() {
  int flag = 0;
  if (FigureInfo.x + FigureInfo.x_right <
      FIELD_W -
          1)  // проверяем, что можно переместиться вправо по границам поля
  {
    // проверяем, что на след шаге нет фигуры
    for (int i = FigureInfo.y_down, i2 = FigureInfo.y; i >= FigureInfo.y_up;
         i--, i2--) {
      if (FigureInfo.x == 0) {
        // текущее поле фигуры ==1, следующее поле фигуры ==1
        if (FigureInfo.figure[i2][FigureInfo.x_right] != 0 &&
            GameInfo.field[i][(FigureInfo.x + FigureInfo.x_right + 1) %
                              FIELD_W] != 0) {
          flag = 1;
        }
      } else if (FigureInfo.x <= 1) {
        // текущее поле фигуры ==0, текущее поле поля ==1
        if ((FigureInfo.figure[i2][FigureInfo.x_right] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_right + 1) %
                               FIELD_W] != 0) ||
            (FigureInfo.figure[i2][FigureInfo.x_right] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_right - 1] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_right) % FIELD_W] !=
                 0)) {
          flag = 1;
        }
      } else {
        // текущее поле фигуры ==0, следующее поле фигуры ==0, послеследующее
        // поле фигуры ==1, текущее поле поля ==1 =====КОШМАР!!!!!
        if ((FigureInfo.figure[i2][FigureInfo.x_right] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_right + 1) %
                               FIELD_W] != 0) ||
            (FigureInfo.figure[i2][FigureInfo.x_right] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_right - 1] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_right) % FIELD_W] !=
                 0) ||
            (FigureInfo.figure[i2][FigureInfo.x_right] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_right - 1] == 0 &&
             FigureInfo.figure[i2][FigureInfo.x_right - 2] != 0 &&
             GameInfo.field[i][(FigureInfo.x + FigureInfo.x_right) % FIELD_W] !=
                 0)) {
          flag = 1;
        }
      }

      if (flag) break;
    }
  } else {
    flag = 1;
  }
  return flag;
}

// проерка на поворот фигуры
int is_cant_move_turn() {
  int flag = 0;
  int **temp = calloc(FIGURE_H, sizeof(int *));
  for (int i = 0; i < FIGURE_H; i++) temp[i] = calloc(FIELD_W, sizeof(int));
  int a1 = FigureInfo.y_down;
  int a2 = FigureInfo.y_up;
  int a3 = FigureInfo.x_left;
  int a4 = FigureInfo.x_right;
  int old_h_figure = FigureInfo.y;
  int old_down = FigureInfo.y_down;
  // Копирование повернутой фигуры в temp
  int rotate = (FigureInfo.rotate + 1) % 4;
  for (int i = 0; i < FIGURE_H; i++) {
    for (int j = 0; j < FIGURE_W; j++)
      temp[i][j] = Figures[FigureInfo.figure_number][rotate][i][j];
  }
  get_params_figure(temp);
  FigureInfo.y_down = old_down + (FigureInfo.y - old_h_figure);
  FigureInfo.y_up = FigureInfo.y_down - FigureInfo.y;
  // Проверка, что не вышли за границы поля
  if (FigureInfo.x + FigureInfo.x_left >= 0 &&
      FigureInfo.x + FigureInfo.x_right <= FIELD_W - 1) {
    for (int i = FigureInfo.y_up, ii = 0;
         i < FigureInfo.y_up + FIGURE_H && i < FIELD_H; i++) {
      for (int j = FigureInfo.x, jj = 0; j < FigureInfo.x + FIGURE_W; j++) {
        if (GameInfo.field[i][j] - FigureInfo.figure[ii][jj] + temp[ii][jj] >
                temp[ii][jj] ||
            (FigureInfo.figure_number == 0 &&
             FigureInfo.y_down > FIELD_H - FIGURE_H) ||
            (FigureInfo.figure_number != 0 && FigureInfo.figure_number != 3 &&
             FigureInfo.y_down == FIELD_H - 1)) {
          flag = 1;
          break;
        }
        jj++;
      }
      if (flag) break;
      ii++;
    }
  } else
    flag = 1;

  for (int i = 0; i < FIGURE_H; i++) free(temp[i]);
  free(temp);
  // вернули константы обратно
  FigureInfo.y_down = a1;
  FigureInfo.y_up = a2;
  FigureInfo.x_left = a3;
  FigureInfo.x_right = a4;
  return flag;
}

// действие - поворот фигуры
void move_turn() {
  int old_h_figure = FigureInfo.y;
  int old_down = FigureInfo.y_down;

  // Копирование повернутой фигуры в FigureInfo.figure
  int rotate = (FigureInfo.rotate + 1) % 4;
  for (int i = 0; i < FIGURE_H; i++) {
    for (int j = 0; j < FIGURE_W; j++) {
      FigureInfo.figure[i][j] = Figures[FigureInfo.figure_number][rotate][i][j];
    }
  }
  FigureInfo.rotate = rotate;
  get_params_figure(FigureInfo.figure);
  FigureInfo.y = FigureInfo.y_down;
  FigureInfo.x_levo = FigureInfo.x_left;

  FigureInfo.y_down = old_down + (FigureInfo.y - old_h_figure);
  FigureInfo.y_up = FigureInfo.y_down - FigureInfo.y;
}

// проверка на возможность размещения стартовой фигуры
int check_new_figure_at_field() {
  int flag = 0;

  // for (int i = FigureInfo.y_up, ii = 0; i < FigureInfo.y_up + FIGURE_H && i <
  // FIELD_H; i++)
  for (int i = FigureInfo.y_up;
       i < FigureInfo.y_up + FigureInfo.y && i < FIELD_H; i++) {
    for (int j = FigureInfo.x; j < FigureInfo.x + FIGURE_W; j++) {
      if (GameInfo.field[i][j] != 0) {
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }

  return flag;
}

// проверка линии на заполенность и ее "сжигание"
void check_full_line() {
  int line_count = 0;
  for (int i = FIELD_H - 1; i >= 0; i--) {
    int line = 0;
    for (int j = 0; j < FIELD_W; j++) {
      if (GameInfo.field[i][j] != 0) line += 1;
    }

    if (line == FIELD_W)  // Если линия заполнена полностью
    {
      line_count += 1;  // Увеличиваем счетчик заполненных линий

      // "Сжигаем" линию, сдвигая все строки выше вниз
      for (int ii = i; ii > 0; ii--) {
        for (int j = 0; j < FIELD_W; j++)
          GameInfo.field[ii][j] = GameInfo.field[ii - 1][j];
      }

      // Обнуляем верхнюю строку, которая сдвинулась вниз
      for (int j = 0; j < FIELD_W; j++) GameInfo.field[0][j] = 0;

      // Так как текущая строка "i" стала новой строкой, ее нужно проверить
      // заново
      i++;
    }
  }
  if (line_count == 1)
    GameInfo.score += 100;
  else if (line_count == 2)
    GameInfo.score += 300;
  else if (line_count == 3)
    GameInfo.score += 700;
  else if (line_count == 4)
    GameInfo.score += 1500;
  if (GameInfo.level != 10) GameInfo.level = (int)(GameInfo.score / 600) % 11;
  if (GameInfo.level) GameInfo.speed = 10 - ((GameInfo.level - 1) * 1) - 1;
}

void save_new_record() {
  FILE *file = fopen("brick_game/tetris/high_score.txt", "w");
  char str[250] = "";
  sprintf(str, "%d", GameInfo.score);
  fputs(str, file);
  fclose(file);
}

void parsing_input(int input, bool hold) {
  switch (input) {
    case KEY_LEFT:
      userInput(Left, hold);
      break;
    case KEY_RIGHT:
      userInput(Right, hold);
      break;
    case ' ':
      userInput(Action, hold);
      break;
    case KEY_DOWN:
      userInput(Down, hold);
      break;
    case KEY_UP:
      userInput(Up, hold);
      break;
    case 'q':
    case 'Q':
      userInput(Terminate, hold);
      break;
    case 'p':
    case 'P':
      userInput(Pause, hold);
      break;
    case 'r':
    case 'R':
    case 'S':
    case 's':
      userInput(Start, hold);
      break;
  }
}

void userInput(UserAction_t action, bool hold) {
  useraction = action;
  switch (useraction) {
    case Left:
      if (!is_cant_move_left() && GameInfo.pause == 0) {
        if (hold) {
          while (hold && !is_cant_move_left()) {
            cut_figure_from_field();
            move_left();
            GameInfo = updateCurrentState();
            usleep(100000);  // Добавляем задержку в 100 миллисекунд
            interface(GameInfo, FigureInfo);
          }
        } else {
          cut_figure_from_field();
          move_left();
          GameInfo = updateCurrentState();
          usleep(100000);  // Добавляем задержку в 100 миллисекунд
          interface(GameInfo, FigureInfo);
        }
      }
      break;
    case Right:
      if (!is_cant_move_right() && GameInfo.pause == 0) {
        if (hold) {
          while (hold && !is_cant_move_right()) {
            cut_figure_from_field();
            move_right();
            GameInfo = updateCurrentState();
            usleep(100000);  // Добавляем задержку в 100 миллисекунд
            interface(GameInfo, FigureInfo);
          }
        } else {
          cut_figure_from_field();
          move_right();
          GameInfo = updateCurrentState();
          usleep(100000);  // Добавляем задержку в 100 миллисекунд
          interface(GameInfo, FigureInfo);
        }
      }
      break;
    case Action:
      if (!is_cant_move_turn() && GameInfo.pause == 0) {
        if (hold) {
          while (hold && !is_cant_move_turn()) {
            cut_figure_from_field();
            move_turn();
            GameInfo = updateCurrentState();
            usleep(100000);  // Добавляем задержку в 100 миллисекунд
            interface(GameInfo, FigureInfo);
          }
        } else {
          cut_figure_from_field();
          move_turn();
          GameInfo = updateCurrentState();
          usleep(100000);  // Добавляем задержку в 100 миллисекунд
          interface(GameInfo, FigureInfo);
        }
      }
      break;
    case Down:
      while (!is_cant_move_down()) {
        cut_figure_from_field();
        move_down();
        GameInfo = updateCurrentState();
      }
      break;
    case Terminate:
      GameInfo.pause = 2;
      break;
    case Pause:
      if (GameInfo.pause == 0) {
        pause_menu();
        action = 0;
        GameInfo.pause = 1;
      } else
        GameInfo.pause = 0;
      break;
    case Start: {
      if (GameInfo.pause == 2) new_game(&GameInfo, &FigureInfo);
      break;
    }
    case Up:
      break;
  }
}

// подсчет микросекунд (чтобы двигать фигуры внутри тайминга действия)
unsigned long long current_microseconds() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000000 + tv.tv_usec;
}

// сбор функций для движения фигуры вниз
void func_move_down(GameInfo_t *GameInf, FigureInfo_t Figure) {
  if (is_cant_move_down()) {
    update_figure();
    check_full_line();  // проверяем строки на наполнение и списываем полностью
                        // заполненные
    // проверка, что влезает новая фигура
    if (!check_new_figure_at_field())
      *GameInf = updateCurrentState();
    else {
      GameInf->pause = 2;
    }
  } else {
    cut_figure_from_field();
    move_down();
    *GameInf = updateCurrentState();
    usleep(100000);  // Добавляем задержку в 100 миллисекунд
    interface(*GameInf, Figure);
  }
}
