#include "frontend.h"

void start_curses() {
  initscr();
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_WHITE);
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  halfdelay(1);
  curs_set(FALSE);
}

void close_curses() { endwin(); }

void draw_border() {
  for (int i = 0; i < ROW + 2; i++) {
    for (int j = 0; j < COLUMN + 2; j++) {
      if (i == 0 || j == 0 || i == ROW + 1 || j == COLUMN + 1) {
        color_pixel(i, j, WHITE);
      }
    }
  }
}

void draw_field(int **field) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      color_pixel(i + 1, j + 1, field[ROW - i - 1][j] + 1);
    }
  }
}

void draw_next(int **next) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      color_pixel(NEXT_START_Y + i, NEXT_START_X + j, next[i][j] + 1);
    }
  }
  mvprintw(NEXT_START_Y - 1, NEXT_START_X * 2, "NEXT TILE");
}

void draw_stats(int highscore, int score, int level) {
  mvprintw(STATS_START_Y, STATS_START_X, "score - %d", score);
  mvprintw(STATS_START_Y + 1, STATS_START_X, "highscore - %d", highscore);
  mvprintw(STATS_START_Y + 2, STATS_START_X, "level - %d", level);
}

void color_pixel(int y, int x, int color) {
  attron(COLOR_PAIR(color));
  mvaddch(y, x * 2, ' ');
  mvaddch(y, x * 2 + 1, ' ');
  attroff(COLOR_PAIR(color));
}

void draw_gameover(int score) {
  mvprintw(GAME_OVER_Y, GAME_OVER_X, "game over");
  mvprintw(GAME_OVER_Y + 1, GAME_OVER_X, "score - %d", score);
}

void print_controls() {
  mvprintw(22, 0, "s - to start");
  mvprintw(23, 0, "p - to pause/unpause");
  mvprintw(24, 0, "backspace - to quit");
  mvprintw(26, 0, "space - to rotate");
  mvprintw(27, 0, "arrow keys - to move");
}