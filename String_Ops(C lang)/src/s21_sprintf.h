#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>

#ifndef S21_NULL
#define S21_NULL ((void *)0)
#endif

#define BUFF_SIZE 4096

struct Flags {
  int plus;
  int minus;
  int space;
  int grid;
  int zero;
};

struct FormatData {
  struct Flags flags;
  int counter;
  int width;
  int precision;
  int has_precision;
  char length;
  char specifier;
};

int s21_sprintf(char *str, const char *format, ...);
const char *getFlags(const char *format, struct FormatData *formatData);
int processSpecifier(char **str, struct FormatData *formatData, va_list va,
                     int res);
const char *getLength(const char *format, struct FormatData *formatData);
const char *getPrecision(const char *format, struct FormatData *formatData,
                         va_list va);
const char *getWidth(const char *format, struct FormatData *formatData,
                     va_list va);
int processChar(char **str, va_list va, struct FormatData *formatData);
int processString(char *str, va_list va, struct FormatData *formatData);
int processFloat(char *str, struct FormatData *formatData, va_list va);
void writeE_Value(char *str, struct FormatData *formatData, long double value);
int floatToStr(char *valueStr, struct FormatData *formatData,
               long double value);
void floatConverter(char *valueStr, long double value,
                    struct FormatData *formatData);
const char *getSpecifier(const char *format, struct FormatData *formatData,
                         int *flag);
int processInt(char *str, struct FormatData *formatData, va_list va);
int writeInt(char *str, struct FormatData *formatData, long long value);
void intToStr(char *valueStr, long long int value,
              struct FormatData *formatData);
void helperSpecG(char *valueStr, struct FormatData *formatData);
int numberOfSymbolsInInt(long long int value);
void expToStr(char *valueStr, struct FormatData *formatData, int exp_counter,
              long double value);
void flagMinusHandler(char *str, char *valueStr, struct FormatData *formatData,
                      long double value);
int setSign(char *str, long double value, struct FormatData *formatData);
int decreaseZeroesWidth(struct FormatData *formatData);
int decreaseSignWidth(long double value, struct FormatData *formatData);
int addZeroes(char *str, struct FormatData *formatData);
int setZeroes(char *str, struct FormatData *formatData);
int setSpaces(char *str, struct FormatData *formatData);
void processN(va_list va, int res);
int writeFloat(char *str, struct FormatData *formatData, long double value);
void writeG_Value(char *str, struct FormatData *formatData, long double value);
int processUnsigned(char *str, struct FormatData *formatData, va_list va);
int writeUnsigned(char *str, struct FormatData *formatData,
                  unsigned long long value);
int unsignedToStr(char *valueStr, unsigned long long value,
                  struct FormatData *formatData);
int numberOfSymbolsInUnsigned(unsigned long long value);
int processX(char *str, struct FormatData *formatData, unsigned long value);
int decToHexOct(char *valueStr, unsigned long long value,
                struct FormatData *formatData, int base);
void upperStrX(char *valueStr);
void handleSpacesPrefix(char **str, struct FormatData *formatData,
                        unsigned long long value);
void handleGridFlag(char **str, struct FormatData *formatData,
                    unsigned long long value);
void handleGridFlagWithSpaces(char **str, struct FormatData *formatData,
                              unsigned long long value);
void handleOctalGridFlag(char **str, struct FormatData *formatData,
                         unsigned long long value);
void handleOctalGridFlagWithSpaces(char **str, struct FormatData *formatData,
                                   unsigned long long value);
int processO(char *str, struct FormatData *formatData,
             unsigned long long value);
int writeToStr(char *str, const char *format);
const char *formatParser(const char *format, struct FormatData *formatData,
                         int *flag, va_list va);
int processP(char *str, struct FormatData *formatData, va_list va);
void putPoint(char **valueStr, struct FormatData *formatData);
long double decimalPartFloat(char **valueStr, long double right_side,
                             long long *precision,
                             struct FormatData *formatData);
int numberOfSymbolsInFloat(long double value);
void remove_zero(char *str, struct FormatData *formatData);
int checkIfNanOrInf(char *valueStr, struct FormatData *formatData,
                    long double value);

#endif