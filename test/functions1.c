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
 * Return: number of chars
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
