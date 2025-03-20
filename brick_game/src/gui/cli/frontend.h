#ifndef S21_FRONTEND_H
#define S21_FRONTEND_H

#define BLACK 1
#define WHITE 2
#define BOARD_SHIFT 1
#define NEXT_START_X 25
#define NEXT_START_Y 2
#define ROW 20
#define COLUMN 10
#define STATS_START_Y 8
#define STATS_START_X 50
#define GAME_OVER_Y 12
#define GAME_OVER_X 20

#include <ncurses.h>

/**
 * @file
 * @brief all frontend functions
 */

/**
 * @brief starts ncurses
 */
void start_curses();

/**
 * @brief closes ncurses
 */
void close_curses();

/**
 * @brief prints controls
 */
void print_controls();

/**
 * @brief draws next tile on the right side of the screen
 * @param next pointer to 4x4 matrix to draw
 */
void draw_next(int **next);

/**
 * @brief draws 10x20 play field from given matrix
 * @param field to draw
 */
void draw_field(int **field);

/**
 * @brief draws border around the field
 */
void draw_border();

/**
 * @brief function to paint the pixel of field
 * @param y y-coord on screen
 * @param x x-ccord on screen
 * @param color to paint
 */
void color_pixel(int y, int x, int color);

/**
 * @brief function to draw game over screen
 * @param score final score to display
 */
void draw_gameover(int score);

/**
 * @brief function to print stats on screen
 * @param highscore to print
 * @param score to print
 * @param level to print
 */
void draw_stats(int highscore, int score, int level);

#endif