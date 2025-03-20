#include "fsm.h"

GameInfo_t *start_fsm() {
  GameInfo_t *info = calloc(sizeof(GameInfo_t), 1);
  info->field = (int **)calloc(sizeof(int *), row);
  info->field[0] = (int *)calloc(sizeof(int), row * column);
  info->next = (int **)calloc(sizeof(int *), 4);
  info->next[0] = (int *)calloc(sizeof(int), 4 * 4);
  for (int i = 1; i < row; i++) {
    info->field[i] = (info->field[0] + i * column);
    if (i < 4) {
      info->next[i] = (info->next[0] + i * 4);
    }
  }
  info->speed = 0;
  info->level = 1;
  char filename[] = "data.txt";
  info->high_score = read_highscore(filename);
  return info;
}

GameState_t *init_game_state() {
  GameState_t *state = (GameState_t *)calloc(1, sizeof(GameState_t));
  *state = START_STATE;
  return state;
}

GameState_t *current_game_state() {
  static GameState_t *state = NULL;
  static int called = 0;
  if (state == NULL) {
    state = init_game_state();
    called++;
  }
  return state;
}

void destroy_game_state() {
  GameState_t *state = current_game_state();
  free(state);
}

GameInfo_t *get_current_info() {
  static GameInfo_t *info = NULL;
  if (info == NULL) {
    info = start_fsm();
  }
  return info;
}

void kill_fsm() {
  GameInfo_t *info = get_current_info();
  free(info->field[0]);
  free(info->next[0]);
  free(info->field);
  free(info->next);
  free(info);
}

void reset_info() {
  GameInfo_t *info = get_current_info();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      info->field[i][j] = 0;
      if (i < 4 && j < 4) {
        info->next[i][j] = 0;
      }
    }
  }
  if (info->high_score < info->score) {
    info->high_score = info->score;
  }
  info->level = 1;
  info->speed = 1;
  info->score = 0;
}

GameInfo_t updateCurrentState() {
  GameInfo_t *info = get_current_info();
  return *info;
}

int read_highscore(char *filename) {
  int highscore = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file != NULL) {
    char to_convert[100];
    fgets(to_convert, 100, file);
    int check = 1;
    size_t i = 0, len = strlen(to_convert);
    for (; i < len && check; i++) {
      if (to_convert[i] < '0' || '9' < to_convert[i]) {
        check = 0;
      }
    }
    if (check && i < 10) {
      highscore = atoi(to_convert);
    }
    fclose(file);
  }
  return highscore;
}

void write_high_score(char *filename, int highscore) {
  FILE *file;
  file = fopen(filename, "w");
  if (file != NULL) {
    fprintf(file, "%d", highscore);
    fclose(file);
  }
}

MoveType_t convert_to_move(UserAction_t input) {
  MoveType_t move = MoveDown;
  switch (input) {
    case Left:
      move = MoveLeft;
      break;
    case Right:
      move = MoveRight;
      break;
    case Down:
      move = MoveDown;
      break;
    case Action:
      move = Rotate;
      break;
    default:
      break;
  }
  return move;
}

UserAction_t get_action() {
  UserAction_t action;
  int ch = getch();
  switch (ch) {
    case KEY_DOWN:
      action = Down;
      break;
    case KEY_LEFT:
      action = Left;
      break;
    case KEY_RIGHT:
      action = Right;
      break;
    case ' ':
      action = Action;
      break;
    case KEY_BACKSPACE:
      action = Terminate;
      break;
    case 's':
    case 'S':
      action = Start;
      break;
    case 'p':
    case 'P':
      action = Pause;
      break;
    default:
      action = Up;
      break;
  }
  flushinp();
  return action;
}

void userInput(UserAction_t action, bool hold) {
  GameState_t *state = current_game_state();
  GameInfo_t *info = get_current_info();
  static int bag[7];
  static Tile tile, next;
  static int tick;
  switch (*state) {
    case PAUSE_STATE:
      if (action == Pause) {
        *state = MOVING_STATE;
      } else if (action == Terminate) {
        *state = EXIT_STATE;
      } else {
        *state = PAUSE_STATE;
      }
      break;
    case START_STATE:
      switch (action) {
        case Start:
          *state = SPAWN_STATE;
          generate_bag(bag);
          generate_tile(&next, bag);
          break;
        case Terminate:
          *state = EXIT_STATE;
          break;
        default:
          *state = START_STATE;
          break;
      }
      break;
    case SPAWN_STATE:
      copy_tile(&next, &tile);
      fill_next(info->next, bag);
      generate_tile(&next, bag);
      if (bag[6] == -1) {
        generate_bag(bag);
      }
      *state = COLLIDE_STATE;
      break;
    case MOVING_STATE:

      switch (action) {
        case Pause:
          *state = PAUSE_STATE;
          break;
        case Terminate:
          *state = EXIT_STATE;
          break;
        case Left:
        case Right:
        case Down:
        case Action:
          int status =
              change_placement(&tile, info->field, convert_to_move(action));
          if (status == 0) {
            *state = FREEZE_STATE;
          } else {
            *state = MOVING_STATE;
          }
          if (tick % (11 - info->speed) == 0) {
            int status = change_placement(&tile, info->field, MoveDown);
            if (!status) {
              *state = FREEZE_STATE;
            } else {
              *state = MOVING_STATE;
            }
          }
          break;
        default:
          if (tick % (11 - info->speed) == 0) {
            int status = change_placement(&tile, info->field, MoveDown);
            if (!status) {
              *state = FREEZE_STATE;
            } else {
              *state = MOVING_STATE;
            }
          }
          break;
      }
      break;
    case FREEZE_STATE:
      int cleared = check_full_lines(info->field, &tile);
      if (cleared) {
        info->score += add_score(cleared);
        info->level = (info->score / 600 + 1 < 10 ? info->score / 600 + 1 : 10);
        info->speed = info->level;
      }
      *state = SPAWN_STATE;
      break;
    case COLLIDE_STATE:
      if (!check_placement(&tile, info->field)) {
        *state = GAMEOVER;
      } else {
        *state = MOVING_STATE;
      }
      break;

    case GAMEOVER:
      if (info->score > info->high_score) {
        char filename[] = "data.txt";
        write_high_score(filename, info->score);
      }
      if (action == Start) {
        reset_info();
        *state = SPAWN_STATE;
      } else if (action == Terminate) {
        *state = EXIT_STATE;
      }
      break;
    case EXIT_STATE:
      break;
    default:
      break;
  }
  if (!hold) {
    tick++;
  }
}