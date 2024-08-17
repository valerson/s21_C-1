#include "brick_game/tetris/backend.h"
#include "gui/cli/interface.h"

int main() {
  init_all();
  start_figure();
  int c = 0;

  GameInfo_t GameInf =
      updateCurrentState();  // записываем в поле фигуру след фигуру
  FigureInfo_t Figure = ExportFigure();
  if (start_animation()) {
    clear();
    draw_backgroud();
    halfdelay(1);  // выкл ожидание ввода с клавы
    while (GameInf.pause != 2) {
      interface(GameInf, Figure);
      unsigned long long time_microsec_start = current_microseconds();
      do {
        c = getch();
        parsing_input(c, false);

        usleep(100000);  // Добавляем задержку в 100 миллисекунд
        unsigned long long time_microsec =
            current_microseconds();  // выход если времени прошло больше 1 сек *
                                     // скорость (коэфф)
        if ((time_microsec - time_microsec_start) >=
                (unsigned int)(1000000 * GameInf.speed / 10) ||
            GameInf.pause == 2)
          break;
      } while (1);
      func_move_down(&GameInf, Figure);
      if (GameInf.pause == 2)
        game_finish(c, &GameInf, &Figure);
      else
        Figure = ExportFigure();
    }
  }
  deinit_all();
  return 0;
}
