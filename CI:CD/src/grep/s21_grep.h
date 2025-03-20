#ifndef S21_GREP_H
#define S21_GREP_H

#define _POSIX_C_SOURCE 200809L

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int len_pattern;
  char pattern[1024];
  int error_occurred;
} Arguments;

Arguments argument_parser(int argc, char *argv[]);
void process_file(Arguments arg, char *path, regex_t *reg);
void print_usage(void);
void add_reg_from_file(Arguments *arg, char *filepath);
void process_file(Arguments arg, char *path, regex_t *reg);
void print_usage(void);
void output_line(char *line, int n);
void print_match(regex_t *re, char *line);

#endif
