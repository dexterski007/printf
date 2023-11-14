#include "main.h"

/**
 * print_char - print chars
 *
 * @args: arguments
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: number of chars to p
**/

int print_char(va_list args, char *buff, int flag,
	int width, int precis, int size)

{
	char c = va_arg(args, int);

	return (char_write(c, buff, flag, width, precis, size));
}

/**
 * print_perc - print percent
 *
 * @args: arguments
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: number of chars
**/

int print_perc(va_list args, char *buff, int flag,
	int width, int precis, int size)

{
	(void)(args);
	(void)(buff);
	(void)(flag);
	(void)(width);
	(void)(precis);
	(void)(size);

	return (write(1, "%%", 1));
}

/**
 * print_str - print str
 *
 * @args: arguments
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: number of chars
**/

int print_str(va_list args, char *buff,
	int flag, int width, int precis, int size)

{
	int len = 0, i = 0;
	char *s = va_arg(args, char *);

	(void)(buff);
	(void)(flag);
	(void)(width);
	(void)(precis);
	(void)(size);

	if (s == NULL)
	{
		s = ("null");
		if (precis >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len++;

	if (precis >= 0 && precis < len)
		len = precis;

	if (width > len)
	{
		if (flag & 1)
		{
			write(1, &s[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, s, len);
				return (width);
		}
	}
	return (write(1, s, len));
}

/**
 * print_num - print number
 *
 * @args: arguments
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: number of chars
**/

int print_num(va_list args, char *buff,
	int flag, int width, int precis, int size)
{
	int j = 1024 - 2;
	int is_neg = 0;
	long int p = va_arg(args, long int);
	unsigned long int dig;

	p = size_dig(p, size);

	if (p == 0)
		buff[j--] = '0';
	buff[1024 - 1] = '\0';

	dig = (unsigned long int)p;

	if (p < 0)
	{
		dig = (unsigned long int)((-1) * p);
		is_neg = 1;
	}
	while (dig > 0)
	{
		buff[j--] = (dig % 10) + '0';
		dig /= 10;
	}

	j++;

	return (num_write(is_neg, j, buff, flag, width, precis, size));
}
