#include "backend.h"

int add_score(int cleared) {
  int score = 100;
  if (cleared == 2) {
    score += 200;
  } else if (cleared == 3) {
    score += 600;
  } else if (cleared == 4) {
    score += 1400;
  }
  return score;
}

void copy_tile(Tile *src, Tile *dst) {
  dst->center = src->center;
  dst->coord1 = src->coord1;
  dst->coord2 = src->coord2;
  dst->coord3 = src->coord3;
  dst->type = src->type;
  dst->freeze = src->freeze;
}

void generate_tile(Tile *tile, int *bag) {
  int piece = pull_a_piece(bag);
  generate_piece_struct(piece, tile);
  move_tile(tile, -20);
}

void fill_next(int **next, int *bag) {
  Tile tile;
  int piece = -1;
  for (int i = 0; (i < bag_size) && (piece == -1); i++) {
    piece = bag[i];
  }
  generate_piece_struct(piece, &tile);
  move_tile(&tile, -183);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      next[i][j] = 0;
    }
  }
  next[3 - (tile.center / 10)][tile.center % 10] = 1;
  next[3 - (tile.coord1 / 10)][tile.coord1 % 10] = 1;
  next[3 - (tile.coord2 / 10)][tile.coord2 % 10] = 1;
  next[3 - (tile.coord3 / 10)][tile.coord3 % 10] = 1;
}

void generate_bag(int *bag) {
  for (int i = 0; i < bag_size; i++) {
    bag[i] = i;
  }
  shuffle(bag);
}

void shuffle(int *bag) {
  srand(time(NULL));
  for (size_t i = 0; i < bag_size; i++) {
    size_t j = i + rand() / (RAND_MAX / (bag_size - i) + 1);
    int t = bag[j];
    bag[j] = bag[i];
    bag[i] = t;
  }
}

int pull_a_piece(int *bag) {
  int i = 0, piece = -1;
  while (i < bag_size && piece == -1) {
    if (bag[i] != -1) {
      piece = bag[i];
      bag[i] = -1;
    }
    i++;
  }
  return piece;
}

int check_game_over(int **play_field) {
  int game_over = 0;
  for (int i = row - 2; i < row && !game_over; i++) {
    for (int j = 0; j < column && !game_over; j++) {
      if (play_field[i][j]) {
        game_over = 1;
      }
    }
  }
  return game_over;
}

void clear_line(int **play_field, int line) {
  for (int i = 0; i < column; i++) {
    play_field[line][i] = 0;
  }
}

void collapse_lines(int **field, int start, int lines) {
  for (int j = 0; j < column; j++) {
    for (int i = start; i < row - lines; i++) {
      field[i][j] = field[i + lines][j];
      field[i + lines][j] = 0;
    }
  }
}

int check_full_lines(int **field, Tile *tile) {
  int y_finish =
          (tile->coord1 > tile->coord3 ? tile->coord1 : tile->coord3) / 10,
      y_start = y_finish - abs(tile->coord1 / 10 - tile->coord3 / 10),
      full_lines = 0;
  if (tile->type == 6 && y_finish == y_start) {
    y_finish = (tile->center > tile->coord2 ? tile->center : tile->coord2) / 10;
    y_start = y_finish - 1;
  }
  int lines_buffer = 0;
  for (int i = y_start; i <= y_finish; i++) {
    if (lines_buffer != full_lines) {
      i--;
      y_finish--;
    }
    lines_buffer = full_lines;
    int clear = 1;
    for (int j = 0; j < column && clear; j++) {
      if (field[i][j] == 0) {
        clear = 0;
      }
    }
    if (clear) {
      clear_line(field, i);
      collapse_lines(field, i, 1);
      full_lines++;
    }
  }
  return full_lines;
}

int generate_piece_struct(int type, Tile *tile) {
  int error = 0;
  tile->type = type;
  tile->freeze = 0;
  switch (type) {
    case 0:
      tile->coord1 = 214;
      tile->coord2 = 215;
      tile->coord3 = 204;
      tile->center = 205;
      break;
    case 1:
      tile->coord1 = 213;
      tile->center = 214;
      tile->coord2 = 215;
      tile->coord3 = 216;
      break;
    case 2:
      tile->center = 214;
      tile->coord1 = 215;
      tile->coord3 = 203;
      tile->coord2 = 204;
      break;
    case 3:
      tile->coord1 = 213;
      tile->center = 214;
      tile->coord2 = 204;
      tile->coord3 = 205;
      break;
    case 4:
      tile->coord2 = 213;
      tile->center = 214;
      tile->coord1 = 215;
      tile->coord3 = 203;
      break;
    case 5:
      tile->coord1 = 213;
      tile->center = 214;
      tile->coord2 = 215;
      tile->coord3 = 205;
      break;
    case 6:
      tile->coord2 = 214;
      tile->coord1 = 203;
      tile->center = 204;
      tile->coord3 = 205;
      break;
    default:
      error = 1;
      break;
  }
  return error;
}

// pieces description
//  0 - O 1 no spins, 1 - I 2 spins
//  2 - S 2 spins, 3 - Z 2 spins
//  4 - L 4 spins, 5 - J 4 spins
//  6 - T 4 spins

int rotate_a_piece(Tile *tile, Tile *rotated) {
  if (rotated != NULL) {
    rotated->type = tile->type;
    rotated->freeze = tile->freeze;
    rotated->center = tile->center;
    switch (tile->type) {
      case 6:
        check_bounds(tile, &(rotated->center), 1);
        rotated->coord1 = tile->coord2;
        rotated->coord2 = tile->coord3;
        if (rotated->coord1 / 10 > rotated->center / 10) {
          rotated->coord3 =
              (rotated->center / 10 - 1) * 10 + rotated->center % 10;
        } else if (rotated->coord1 / 10 < rotated->center / 10) {
          rotated->coord3 =
              (rotated->center / 10 + 1) * 10 + rotated->center % 10;
        } else {
          rotated->coord3 =
              rotated->center + (rotated->center > rotated->coord1 ? 1 : -1);
        }
        break;
      case 5:
        check_bounds(tile, &(rotated->center), 1);
        if (tile->coord1 / 10 == tile->coord2 / 10) {
          rotated->coord1 =
              rotated->center + (tile->coord2 > tile->coord1 ? 10 : -10);
          rotated->coord2 =
              rotated->center + (tile->coord2 > tile->coord1 ? -10 : 10);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord2 > rotated->coord1 ? 1 : -1);
        } else {
          rotated->coord1 =
              rotated->center + (tile->coord1 > tile->coord2 ? 1 : -1);
          rotated->coord2 =
              rotated->center + (tile->coord1 > tile->coord2 ? -1 : 1);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord1 > rotated->coord2 ? 10 : -10);
        }
        break;
      case 4:
        check_bounds(tile, &(rotated->center), 1);
        if (tile->coord1 / 10 == tile->coord2 / 10) {
          rotated->coord1 =
              rotated->center + (tile->coord1 > tile->coord2 ? -10 : 10);
          rotated->coord2 =
              rotated->center + (tile->coord1 > tile->coord2 ? 10 : -10);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord2 > rotated->coord1 ? -1 : 1);
        } else {
          rotated->coord1 =
              rotated->center + (tile->coord1 > tile->coord2 ? 1 : -1);
          rotated->coord2 =
              rotated->center + (tile->coord1 > tile->coord2 ? -1 : 1);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord1 > rotated->coord2 ? -10 : 10);
        }
        break;
      case 3:
        check_bounds(tile, &(rotated->center), 1);
        rotated->coord2 = tile->coord1;
        if (tile->coord1 / 10 == tile->center / 10) {
          rotated->coord1 =
              rotated->center + (tile->coord2 > tile->center ? -10 : 10);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord2 > rotated->coord1 ? 10 : -10);
        } else {
          rotated->coord1 =
              rotated->center + (tile->coord2 > tile->center ? -1 : 1);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord1 > rotated->coord2 ? 1 : -1);
        }
        break;
      case 2:
        check_bounds(tile, &(rotated->center), 1);
        rotated->coord1 = tile->coord2;
        if (tile->coord1 / 10 == tile->center / 10) {
          rotated->coord2 =
              rotated->center + (tile->coord1 > tile->center ? -1 : 1);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord2 > rotated->coord1 ? 10 : -10);
        } else {
          rotated->coord2 =
              rotated->center + (tile->coord1 > tile->center ? -10 : 10);
          rotated->coord3 =
              rotated->coord2 + (rotated->coord1 > rotated->coord2 ? -1 : 1);
        }
        break;
      case 1:
        check_bounds(tile, &(rotated->center), 2);
        if (tile->coord1 / 10 == tile->center / 10) {
          rotated->center =
              tile->center + (tile->coord1 > tile->center ? -10 : 10);
          rotated->coord1 =
              rotated->center + (tile->coord1 > tile->center ? -10 : 10);
          rotated->coord2 =
              rotated->center + (tile->coord1 > tile->center ? 10 : -10);
          rotated->coord3 =
              rotated->coord2 + (tile->coord1 > tile->center ? 10 : -10);
        } else {
          rotated->center =
              tile->center + (tile->coord1 > tile->center ? -1 : 1);
          rotated->coord1 =
              rotated->center + (tile->coord1 > tile->center ? 1 : -1);
          rotated->coord2 =
              rotated->center + (tile->coord1 > tile->center ? -1 : 1);
          rotated->coord3 =
              rotated->coord2 + (tile->coord1 > tile->center ? -1 : 1);
        }
        break;
      case 0:
        rotated->coord1 = tile->coord1;
        rotated->coord2 = tile->coord2;
        rotated->coord3 = tile->coord3;
        break;
    }
  }
  return 0;
}

void move_tile(Tile *tile, int movement) {
  tile->center += movement;
  tile->coord1 += movement;
  tile->coord2 += movement;
  tile->coord3 += movement;
  tile->freeze = 0;
}

void check_bounds(Tile *tile, int *center, int shift_type) {
  int to_shift = 1;
  if (tile->center % 10 == 0 || (shift_type == 2 && *center % 10 == 1)) {
    if (shift_type == 2) {
      if (tile->coord1 / 10 != tile->center / 10) {
        to_shift += (2 - *center % 10);
      }
    }
    move_tile(tile, to_shift);
    *center += to_shift;
  } else if (tile->center % 10 == 9 || (shift_type == 2 && *center % 10 == 8)) {
    if (shift_type == 2) {
      if (tile->coord1 / 10 != tile->center / 10) {
        to_shift += (*center % 10 - 7);
      }
    }
    move_tile(tile, -to_shift);
    *center -= to_shift;
  }
}

int change_placement(Tile *tile, int **field, MoveType_t action) {
  int active = 1;
  if (tile->freeze > 1) {
    active = 0;
  } else {
    remove_tile(tile, field);
    if (action == MoveLeft && left_check(tile, field)) {
      move_tile(tile, -1);
    } else if (action == MoveRight && right_check(tile, field)) {
      move_tile(tile, 1);
    } else if (action == MoveDown && bottom_check(tile, field)) {
      move_tile(tile, -10);
    } else if (action == Rotate) {
      Tile rotated;
      rotate_a_piece(tile, &rotated);
      if (check_placement(&rotated, field)) {
        tile->center = rotated.center;
        tile->coord1 = rotated.coord1;
        tile->coord2 = rotated.coord2;
        tile->coord3 = rotated.coord3;
      }
    } else if (!bottom_check(tile, field)) {
      tile->freeze++;
    }
    place_tile(tile, field);
  }
  return active;
}

int check_placement(Tile *tile, int **field) {
  return !(tile->center < 0 || tile->coord1 < 0 || tile->coord2 < 0 ||
           tile->coord3 < 0 || field[tile->center / 10][tile->center % 10] ||
           field[tile->coord1 / 10][tile->coord1 % 10] ||
           field[tile->coord2 / 10][tile->coord2 % 10] ||
           field[tile->coord3 / 10][tile->coord3 % 10]);
}

int bottom_check(Tile *tile, int **field) {
  return !(tile->center / 10 == 0 || tile->coord1 / 10 == 0 ||
           tile->coord2 / 10 == 0 || tile->coord3 / 10 == 0 ||
           field[tile->center / 10 - 1][tile->center % 10] == 1 ||
           field[tile->coord1 / 10 - 1][tile->coord1 % 10] == 1 ||
           field[tile->coord2 / 10 - 1][tile->coord2 % 10] == 1 ||
           field[tile->coord3 / 10 - 1][tile->coord3 % 10] == 1);
}

int left_check(Tile *tile, int **field) {
  return !(tile->center % 10 == 0 || tile->coord1 % 10 == 0 ||
           tile->coord2 % 10 == 0 || tile->coord3 % 10 == 0 ||
           field[tile->center / 10][tile->center % 10 - 1] == 1 ||
           field[tile->coord1 / 10][tile->coord1 % 10 - 1] == 1 ||
           field[tile->coord2 / 10][tile->coord2 % 10 - 1] == 1 ||
           field[tile->coord3 / 10][tile->coord3 % 10 - 1] == 1);
}

int right_check(Tile *tile, int **field) {
  return !(tile->center % 10 == 9 || tile->coord1 % 10 == 9 ||
           tile->coord2 % 10 == 9 || tile->coord3 % 10 == 9 ||
           field[tile->center / 10][tile->center % 10 + 1] == 1 ||
           field[tile->coord1 / 10][tile->coord1 % 10 + 1] == 1 ||
           field[tile->coord2 / 10][tile->coord2 % 10 + 1] == 1 ||
           field[tile->coord3 / 10][tile->coord3 % 10 + 1] == 1);
}

void remove_tile(Tile *tile, int **field) {
  field[tile->center / 10][tile->center % 10] = 0;
  field[tile->coord1 / 10][tile->coord1 % 10] = 0;
  field[tile->coord2 / 10][tile->coord2 % 10] = 0;
  field[tile->coord3 / 10][tile->coord3 % 10] = 0;
}

void place_tile(Tile *tile, int **field) {
  field[tile->center / 10][tile->center % 10] = 1;
  field[tile->coord1 / 10][tile->coord1 % 10] = 1;
  field[tile->coord2 / 10][tile->coord2 % 10] = 1;
  field[tile->coord3 / 10][tile->coord3 % 10] = 1;
}