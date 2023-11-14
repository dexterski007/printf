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
void print_integer(long int n);
int len_count(int n);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hex_upper(va_list args);
int print_string_custom(va_list args);
int print_address(va_list args);
int print_S(va_list args);
int print_pointer(va_list args);
int print_plus_space_hash(char format, va_list args);
int print_length_modifier(char modifier, char format, va_list args);
int print_field_width(int width, char format, va_list args);
int print_precision(int precision, char format, va_list args);
int print_zero_flag(char format, va_list args);
int print_minus_flag(char format, va_list args);
int print_reversed_string(va_list args);
int print_rot13(va_list args);

#endif
