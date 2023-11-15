#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Function prototypes */

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
void print_integer(int n);
int len_count(int n);
int _isdigit(const char *str);

#endif
