#ifndef BRICKGAME_STRUCTS
#define BRICKGAME_STRUCTS

/**
 * @file
 * @brief sctutures to operate with backend info of fielf and tiles
 */

/**
 * @brief sctuct of tile
 */
typedef struct {
  int type;
  int center;
  int coord1;
  int coord2;
  int coord3;
  double freeze;
} Tile;

/**
 * @brief sctuct of field
 */
typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

/**
 * @brief enum type of possible moves
 */
typedef enum { MoveLeft, MoveRight, MoveDown, Rotate } MoveType_t;

#endif