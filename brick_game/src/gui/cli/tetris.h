#ifndef TETRIS_H
#define TETRIS_H

#include "../../brick_game/tetris/backend.h"
#include "../../brick_game/tetris/fsm.h"
#include "../../brick_game/tetris/objects_structs.h"
#include "frontend.h"

/**
 * @mainpage Tetris
 * diagram of current fms
 * @image html fms.PNG
 * @section
 */

/**
 * @brief main loop function - makes calls for all the other main funcitons from
 * back and front
 */
void tetris_loop();

#endif