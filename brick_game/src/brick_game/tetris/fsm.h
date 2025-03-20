#ifndef FMS_H
#define FMS_H

#include <string.h>

#include "backend.h"
#include "objects_structs.h"

/**
 * @file
 * @brief fsm generation, operation and destruction, functions for reading and
 * formalizing the input
 */

/**
 * @brief fsm states
 */
typedef enum {
  START_STATE,
  SPAWN_STATE,
  MOVING_STATE,
  FREEZE_STATE,
  COLLIDE_STATE,
  PAUSE_STATE,
  GAMEOVER,
  EXIT_STATE
} GameState_t;

/**
 * @brief frees memory allocated for the fields
 */
void kill_fsm();

/**
 * @brief allocates memory for structure GameInfo
 * @return pointer to the structure
 */
GameInfo_t *start_fsm();

/**
 * @brief allocates memory and reads highscore from file
 * @return pointer to alloczted structure
 */
GameState_t *init_game_state();

/**
 * @brief funciton to get current state of fsm
 * @return pointer to static field of game state
 */
GameState_t *current_game_state();

/**
 * @brief frees allocated memory in the static pointer of game state
 */
void destroy_game_state();

/**
 * @brief function to get current info from static field
 * @return pointer to the GameInfo_t structure
 */
GameInfo_t *get_current_info();

/**
 * @brief Updates current state of the field and game state
 * @return Structure with new field inside
 */
GameInfo_t updateCurrentState();

/**
 * @brief converts given input to in-game action
 * @return type of action
 */
MoveType_t convert_to_move(UserAction_t input);

/**
 * @brief reads input and formalizes it to UserAction_t struct
 * @return enum of formalized input
 */
UserAction_t get_action();

/**
 * @brief fsm runner function
 * @param action formalized user action
 * @param hold true\false
 */
void userInput(UserAction_t action, bool hold);

/**
 * @brief resets static GameInfo_t pointer to zero on game over
 */
void reset_info();

/**
 * @brief reads highscore from the file
 * @param filename name of file
 * @return highscore
 */
int read_highscore(char *filename);

/**
 * @brief writes highscore to the file
 * @param filename name of file
 * @param highscore to write
 */
void write_high_score(char *filename, int highscore);

#endif