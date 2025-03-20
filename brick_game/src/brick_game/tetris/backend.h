#ifndef BACKEND_H
#define BACKEND_H

#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "objects_structs.h"

#define row 22
#define column 10
#define bag_size 7
#define piece_start_x 4
#define piece_start_y 21

/**
 * @file
 * @brief backend functions to operate with field matrix and tiles
 */

// proper funcs

/**
 * @brief enum type to formalize user input
 */
typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

/**
 * @brief Chooses action to do with field on user input
 * @param action Type of action
 * @param hold Tells if aby button was pressed
 */
void userInput(UserAction_t action, bool hold);

/**
 * @brief checks field for game over
 * @param play_field matrix to look for game over
 * @return 0 if game can continue, 1 if game cant continue
 */
int check_game_over(int **play_field);

/**
 * @brief Generates bag of 7 pieces
 * @param bag array to store pieces
 */
void generate_bag(int *bag);
/**
 * @brief shuffles given bag of 7 pieces
 * @param bag array to shuffle
 */
void shuffle(int *bag);
/**
 * @brief pulls a piece out of bag, replaces pulled piece with -1
 * @param bag array of pieces
 * @return piece from the bag
 */
int pull_a_piece(int *bag);

/**
 * @brief sets given line in field to zeroes
 * @param play_field game field to clear
 * @param line index of line in field to clear
 */
void clear_line(int **play_field, int line);

/**
 * @brief moves upper lines down given amount, 'collapsing' this floating
 * segment
 * @param field matrix to make changes in
 * @param start index of collapse begin segment
 * @param lines amount of lines to collapse down
 */
void collapse_lines(int **field, int start, int lines);

/**
 * @brief checks for full lines in the field, erases and moves upper tiles down
 * concidering where the piece was placed
 * @param play_field matrix of the field
 * @param piece_x x coord of the piece
 * @param piece_y u coord of the piece
 * @param shape shape of the piece
 * @return amount of full lines erased
 */
int check_full_lines(int **field, Tile *tile);

/**
 * @brief fills Tile structure
 * @param type type of the piece
 * @param tile structure tu put data in
 * @return error code
 */
int generate_piece_struct(int type, Tile *tile);

/**
 * @brief changes coordinates of given piece so its rotated
 * @param tile given tile to rotate
 * @param rotated new rotated tile
 * @return error code
 */
int rotate_a_piece(Tile *tile, Tile *rotated);

/**
 * @brief changes piece placement depending on user input
 * @param tile current tile
 * @param field matrix to change placement
 * @param action action to perform
 * @return 1 on active tile, 0 on non-active
 */
int change_placement(Tile *tile, int **field, MoveType_t action);

/**
 * @brief moves tile in x axis
 * @param tile tile to move
 * @param movement amount of blocks to move
 */
void move_tile(Tile *tile, int movement);

/**
 * @brief checks if tile will be in-bounds after rotation, fixes if int wont
 * @param tile tile to check
 * @param center of new tile
 * @param shift_type type of tile, changes amount of shift
 */
void check_bounds(Tile *tile, int *center, int shift_type);

/**
 * @brief checks if new place in the field is empty
 * @param tile tile ro check
 * @param field filed to check
 * @return 0 on not enough space
 */
int check_placement(Tile *tile, int **field);

/**
 * @brief checks if tile reached the bottom
 * @param tile tile to check
 * @param field to check
 * @return 1 on non-touch 0 on touch
 */
int bottom_check(Tile *tile, int **field);

/**
 * @brief checks if tile is blocked from left
 * @param tile tile to check
 * @param field to check
 * @return 1 on non-touch 0 on touch
 */
int left_check(Tile *tile, int **field);

/**
 * @brief checks if tile is blocked from right
 * @param tile tile to check
 * @param field to check
 * @return 1 on non-touch 0 on touch
 */
int right_check(Tile *tile, int **field);

/**
 * @brief removes tile of the field
 * @param tile to remove
 * @param field to remove in
 */
void remove_tile(Tile *tile, int **field);

/**
 * @brief places tile in the field
 * @param tile to place
 * @param tielf to place
 */
void place_tile(Tile *tile, int **field);

/**
 * @brief generates tile structure and moves ito the field
 * @param tile to place info in
 * @param bag to pull a tile from
 */
void generate_tile(Tile *tile, int *bag);

/**
 * @brief delay function
 * @param milliseconds time to wait out
 */
void frame_delay(int milliseconds);

/**
 * @brief fills the next piece matrix
 * @param next piece matrix
 * @param bag to pull out of
 */
void fill_next(int **next, int *bag);

/**
 * @brief calculates amount of earned points
 * @param cleared amount of scoring lines
 * @return score to add
 */
int add_score(int cleared);

/**
 * @brief copies data from tile to tile
 * @param src to write
 * @param dst to read
 */
void copy_tile(Tile *src, Tile *dst);

#endif