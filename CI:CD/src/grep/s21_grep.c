#include "s21_grep.h"

int main(int argc, char **argv) {
  Arguments arg = argument_parser(argc, argv);
  if (arg.error_occurred) {
    print_usage();
    return 1;
  }
  regex_t re;
  int error = regcomp(&re, arg.pattern, REG_EXTENDED | arg.i);
  if (error) {
    perror("Error compiling regex");
    return 1;
  }
  for (int i = optind; i < argc; i++) {
    process_file(arg, argv[i], &re);
  }
  regfree(&re);
  return 0;
}

Arguments argument_parser(int argc, char *argv[]) {
  Arguments arg = {0};
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        arg.e = 1;
        strcat(arg.pattern, "|");  // Simplified pattern addition
        strcat(arg.pattern, optarg);
        arg.len_pattern += strlen(optarg) + 1;
        break;
      case 'i':
        arg.i = REG_ICASE;
        break;
      case 'v':
        arg.v = 1;
        break;
      case 'c':
        arg.c = 1;
        break;
      case 'l':
        arg.l = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 'h':
        arg.h = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'f':
        arg.f = 1;
        add_reg_from_file(&arg, optarg);
        break;
      case 'o':
        arg.o = 1;
        break;
      case '?':
        print_usage();
        exit(1);
        break;
      default:
        break;
    }
  }
  if (argc == 1) {
    print_usage();
    exit(1);
  }
  if (arg.len_pattern == 0) {
    strcat(arg.pattern, argv[optind]);
    arg.len_pattern += strlen(argv[optind]);
    optind++;
  }
  if (argc - optind == 1) {
    arg.h = 1;
  }
  return arg;
}

void add_reg_from_file(Arguments *arg, char *filepath) {
  FILE *f = fopen(filepath, "r");
  if (f == NULL) {
    if (!arg->s) perror(filepath);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  while (getline(&line, &memlen, f) != -1) {
    strcat(arg->pattern, "|");
    strcat(arg->pattern, line);
    arg->len_pattern += strlen(line) + 1;
  }
  free(line);
  fclose(f);
}

void process_file(Arguments arg, char *path, regex_t *reg) {
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    if (!arg.s) perror(path);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  int read = 0;
  int line_count = 1;
  int count = 0;
  while ((read = getline(&line, &memlen, file)) != -1) {
    int result = regexec(reg, line, 0, NULL, 0);
    if ((result == 0 && !arg.v) || (arg.v && result != 0)) {
      if (!arg.c && !arg.l) {
        if (!arg.h) printf("%s:", path);
        if (arg.n) printf("%d:", line_count);
        if (arg.o) {
          print_match(reg, line);
        } else {
          output_line(line, read);
        }
      }
      count++;
    }
    line_count++;
  }
  free(line);
  if (arg.c && !arg.l) {
    if (!arg.h) printf("%s:", path);
    printf("%d\n", count);
  }
  if (arg.l && count > 0) printf("%s\n", path);
  fclose(file);
}

void print_usage(void) {
  printf(
      "Usage: grep [OPTION]... PATTERNS [FILE]...\nTry 'grep --help' for more "
      "information.\n");
}

void output_line(char *line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n') putchar('\n');
}

void print_match(regex_t *re, char *line) {
  regmatch_t match;
  int offset = 0;
  while (1) {
    int result = regexec(re, line + offset, 1, &match, 0);
    if (result != 0) {
      break;
    }
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      putchar(line[i + offset]);
    }
    putchar('\n');
    offset += match.rm_eo;
  }
}