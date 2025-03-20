#include "s21_cat.h"

void SetOption(const char option, struct Options *options);
void ProcessFiles(char *file_path, struct Options options);

static const struct option LONG_OPTIONS[] = {{"number-nonblank", 0, NULL, 'b'},
                                             {"squeeze-blank", 0, NULL, 's'},
                                             {"number", 0, NULL, 'n'}};

static const char SHORT_OPTIONS[] = "AbeEnstTuv";

int main(int argc, char *argv[]) {
  struct Options options = {0};
  int long_options_index = 0;

  char current_option =
      getopt_long(argc, argv, SHORT_OPTIONS, LONG_OPTIONS, &long_options_index);
  while (current_option != -1) {
    SetOption(current_option, &options);
    current_option = getopt_long(argc, argv, SHORT_OPTIONS, LONG_OPTIONS,
                                 &long_options_index);
  }
  if (options.b) options.n = false;
  while (optind < argc) {
    ProcessFiles(argv[optind++], options);
  }
  return 0;
}

void SetOption(const char option, struct Options *options) {
  switch (option) {
    case 'b':
      options->b = true;
      break;
    case 's':
      options->s = true;
      break;
    case 'n':
      options->n = true;
      break;
    case 'v':
      options->v = true;
      break;
    case 'e':
      options->v = true;
      options->e = true;
      break;
    case 't':
      options->v = true;
      options->t = true;
      break;
    case 'E':
      options->e = true;
      break;
    case 'T':
      options->t = true;
      break;

    default:
      printf("cat: illegal option -- %c\nusage: cat [-belnstuv] [file ...]",
             option);
      break;
  }
}

void ProcessFiles(char *file_path, struct Options options) {
  FILE *fptr;
  fptr = fopen(file_path, "r");
  if (fptr == NULL) {
    fprintf(stderr, "cat: %s: No such file or directory\n", file_path);
  } else {
    int new_line = 1;
    int line_count = 1;
    char c = fgetc(fptr);
    while (c != EOF) {
      if (c == '\n' && options.s) {
        if (new_line < 3) {
          if (options.n && new_line) printf("%6d\t", line_count++);
          if (options.b && new_line && c != '\n')
            printf("%6d\t", line_count++);
          else if (options.b && new_line && options.e && c == '\n')
            printf("      \t");
          if (options.e) printf("$");
          printf("%c", c);
          new_line++;
        }
      } else {
        if (options.n && new_line) printf("%6d\t", line_count++);
        if (options.b && new_line && c != '\n')
          printf("%6d\t", line_count++);
        else if (options.b && new_line && options.e && c == '\n')
          printf("      \t");
        if (options.e && c == '\n') printf("$");
        if (options.v && c >= 0 && c < 32 && c != '\t' && c != '\n') {
          printf("^");
          c += 64;
        }
        if (options.t && c == '\t') {
          printf("^");
          c += 64;
        }
        if (options.v && c == 127) {
          printf("^");
          c = '?';
        }
        printf("%c", c);
      }
      new_line++;
      if (c != '\n') new_line = 0;
      c = fgetc(fptr);
    }

    fclose(fptr);
  }
}
