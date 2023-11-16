#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct funcs - strucutre
 *
 * @funcs: identificator
 * @ck: function list
 */
struct funcs
{
	char funcs;
	int (*ck)(va_list, char buff[], int flag,
		int wid, int preci, int size);
};

typedef struct funcs functionsp;

int _printf(const char *format, ...);
int printer(const char *funcs, int *ind,
va_list args, char buff[], int flag, int wid, int preci, int size);
int pr_char(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_str(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_perc(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_int(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_bin(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_uns(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_oct(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_hex(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_HEXA(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int print_hex(va_list args, char map_to[],
char *buff, int flag, char flag_ch, int wid, int preci, int size);
int pr_n_char(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_point(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_rev(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int pr_crypto13(va_list args, char *buff,
	int flag, int wid, int preci, int size);
int char_printer(char c, char *buff,
	int flag, int wid, int preci, int size);
int string_printer(int chkposi, int ind, char *buff,
	int flag, int wid, int preci, int size);
int number_printer(int ind, char buff[], int flag, int wid, int preci,
	int len, char padd, char end);
int pointer_printer(char *buff, int ind, int len,
	int wid, int flag, char padd, char end, int padd_start);
int unsigned_printer(int chkneg, int ind,
	char *buff,	int flag, int wid, int preci, int size);
long int correct_size(long int num, int size);
int hex_map(char c, char *buff, int ind);
int printed_det(char c);
int chkdig(char c);
long int correct_uns(unsigned long int num, int size);
void manage_buffer(char *buff, int *index);
int get_flag(const char *format, int *ind);
int get_wid(const char *format, int *ind, va_list args);
int get_preci(const char *format, int *ind, va_list args);
int get_size(const char *format, int *ind);

#endif
