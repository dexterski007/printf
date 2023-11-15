#include "main.h"

/**
 * print_hex - print hex
 *
 * @args: args
 * @map: map array
 * @buff: buffer
 * @flag: flag
 * @flag_ch: flacg check
 * @wid: width
 * @preci: preccision
 * @size: size
 * Return: count
 */
int print_hex(va_list args, char map[], char *buff,
	int flag, char flag_ch, int wid, int preci, int size)
{
	int i = 1024 - 2;
	unsigned long int dig = va_arg(args, unsigned long int);
	unsigned long int i_nbr = dig;

	(void)(wid);
	dig = correct_uns(dig, size);
	if (dig == 0)
		buff[i--] = '0';
	buff[1024 - 1] = '\0';
	while (dig > 0)
	{
		buff[i--] = map[dig % 16];
		dig /= 16;
	}
	if (flag & 8 && i_nbr != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}
	i++;
	return (unsigned_printer(0, i, buff, flag, wid, preci, size));
}

/**
 * pr_uns - print unsigned
 *
 * @args: args
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_uns(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	int i = 1024 - 2;
	unsigned long int dig = va_arg(args, unsigned long int);

	dig = correct_uns(dig, size);
	if (dig == 0)
		buff[i--] = '0';
	buff[1024 - 1] = '\0';
	while (dig > 0)
	{
		buff[i--] = (dig % 10) + '0';
		dig /= 10;
	}
	i++;
	return (unsigned_printer(0, i, buff, flag, wid, preci, size));
}

/**
 * pr_oct - print octal
 *
 * @args: args
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_oct(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	int i = 1024 - 2;
	unsigned long int dig = va_arg(args, unsigned long int);
	unsigned long int i_nbr = dig;

	(void)(wid);
	dig = correct_uns(dig, size);
	if (dig == 0)
	buff[i--] = '0';
	buff[1024 - 1] = '\0';
	while (dig > 0)
	{
		buff[i--] = (dig % 8) + '0';
		dig /= 8;
	}
	if (flag & 8 && i_nbr != 0)
		buff[i--] = '0';
	i++;
	return (unsigned_printer(0, i, buff, flag, wid, preci, size));
}

/**
 * print_HEX - print up hex
 *
 * @args: args
 * @buff: buff
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_HEXA(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	return (print_hex(args, "0123456789ABCDEF", buff,
		flag, 'X', wid, preci, size));
}

/**
 * pr_hex - print hex min
 *
 * @args: args
 * @buff: buff
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_hex(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	return (print_hex(args, "0123456789abcdef", buff,
		flag, 'x', wid, preci, size));
}
