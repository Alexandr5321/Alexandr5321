#include "tetris.h"

int main() {
  tetris_loop();
  return 0;
}

void tetris_loop() {
  GameInfo_t info = updateCurrentState();
  GameState_t state = *current_game_state();
  bool break_flag = TRUE;

  start_curses();
  draw_border();
  print_controls();
  refresh();
  while (break_flag) {
    if (state == EXIT_STATE) {
      break_flag = FALSE;
    }
    userInput(get_action(), FALSE);
    state = *current_game_state();
    info = updateCurrentState();
    if (state != GAMEOVER) {
      clear();
      print_controls();
      draw_border();
      draw_field(info.field);
      draw_next(info.next);
      draw_stats(info.high_score, info.score, info.level);
    } else {
      clear();
      draw_gameover(info.score);
    }

    refresh();
  }

  kill_fsm();
  destroy_game_state();
  close_curses();
}