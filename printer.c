#include "main.h"

/**
 * printer - printer chooser function
 *
 * @format: format specifier
 * @i: index
 * @args: arguments
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: 1 if succeeded -1 if not
*/

int printer(const char *format, int *i, va_list args, char *buff,
	int flag, int width, int precis, int size)

{
	int j = 0, ptot2 = 0, len007 = 0;
	strf func[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_perc}, {'\0', NULL}
		};

	for (j = 0; func[j].form != '\0'; j++)
		if (format[*i] == func[j].form)
			return (func[j].id(args, buff, flag, width, precis, size));

	if (func[j].form == '\0')
	{
		if (format[j] == '\0')
			return (-1);
		len007 += write(1, "%%", 1);
		if (format[j - 1] == ' ')
			len007 += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] != '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		len007 += write(1, &format[*i], 1);
		return (len007);
	}
	return (ptot2);
}

/**
 * char_write - prepares chars
 *
 * @c: char
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: number of chars
**/

int char_write(char c, char *buff, int flag,
	int width, int precis, int size)

{
	int i = 0;
	char space = ' ';

	(void)(precis);
	(void)(size);

	if (flag & 4)
		space = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (width > 1)
	{
		buff[1024 - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[1024 - i - 2] = space;

		if (flag & 1)
			return (write(1, &buff[0], 1) + (write(1, &buff[1024 - i - 1], width - 1)));
				else
			return (write(1, &buff[1024 - i - 1], width - 1) +
						write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

/**
 * num_write - prepares numbers
 *
 * @is_neg: flag for negative numbers
 * @i: index
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: number of char
**/

int num_write(int is_neg, int i, char *buff,
	int flag, int width, int precis, int size)

{
	int len = 1024 - i - 1;
	char space = ' ', t;

	(void)(size);


	if ((flag & 4) && !(flag & 1))
		space = '0';
	if (is_neg == 1)
		t = '-';
	else if (flag & 2)
		t = '+';
	else if (flag & 16)
		t = ' ';

	return (num_prep(i, buff, flag, width, precis, len, space, t));
}

/**
 * num_prep - prepares numbers for printing
 *
 * @i: index
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @len: length
 * @space: space before actual text
 * @t: +, - or space
 *
 * Return: number of char
**/

int num_prep(int i, char *buff, int flag, int width,
	int precis, int len, char space, char t)
{
	int j = 0, st = 1;

	if (precis == 0 && i == 1024 - 2 && buff[i] == '0' && width == 0)
		return (0);
	if (precis == 0 && i == 1024 - 2 && buff[i] == '0')
		buff[i] = space = ' ';
	if (precis > 0 && precis < len)
		space = ' ';
	while (precis > len)
		buff[--i] = '0', len++;
	if (t != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			buff[j] = space;
		buff[j] = '\0';
		if (flag & 1 && space == ' ')
		{
			if (t)
				buff[--i] = t;
			return (write(1, &buff[i], len) + write(1, &buff[1], j - 1));
		}
		else if (!(flag & 1) && space == ' ')
		{
			if (t)
				buff[--i] = t;
			return (write(1, &buff[i], len) +
				write(1, &buff[1], i - 1));
		}
		else if (!(flag & 1) && space == '0')
		{
			if (t)
				buff[--st] = t;
return (write(1, &buff[st], i - st) + write(1, &buff[1], len - (1 - st)));
		}
	}
	if (t)
		buff[--i] = t;
	return (write(1, &buff[i], len));
}


