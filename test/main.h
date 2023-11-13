#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct formats - structure
 *
 * @func: format
 * @id: function id
 *
 * this structure is for associating a format with a function
 */
struct formats
{
	char func;
	int (*id)(va_list, char[], int, int, int, int);
};

typedef struct formats strf;

/* functions0.c */

void p_buff(char buff[], int *b_ind);
int w_flag(const char *format, int *i);
int w_width(const char *format, int *i, va_list args);
int w_precis(const char *format, int *i, va_list args);
int w_size(const char *format, int *i);

/* _printf.c */

int _printf(const char *format, ...);

/* printer.c */

int printer(const char *format, int *i, va_list args,
	char *buff, int flag, int width, int precis, int size);
int char_write(char c, char *buff, int flag,
	int width, int precis, int size);
int num_write(int is_neg, int i, char *buff,
	int flag, int width, int precis, int size);
int num_prep(int i, char *buff, int flag,
	int width, int precis, int len, char space, char t);

/* functions1.c */

int print_char(va_list args, char *buff,
	int flag, int width, int precis, int size);
int print_perc(va_list args, char *buff,
	int flag, int width, int precis, int size);
int print_str(va_list args, char *buff,
	int flag, int width, int precis, int size);
int print_num(int n);
int print_bin(va_list args);
int print_uns(va_list args);

/* functions2.c */

int print_oct(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_cus(va_list args);
int print_poi(va_list args);

/* functions3.c */

int print_rev(va_list args);
int print_rot(va_list args);
int print_plus_space_hash(char format, va_list args);


/* functions4.c */

int print_length_modifier(char modifier, char format, va_list args);
int print_field_width(int width, char format, va_list args);
int print_precision(int precision, char format, va_list args);
int print_zero_flag(char format, va_list args);
int print_minus_flag(char format, va_list args);

/* functions5.c */

int isnum(char c);
int _isprint(char c);

#endif
