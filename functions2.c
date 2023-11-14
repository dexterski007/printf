#include "main.h"

/**
 * prep_uns - prep unsigned
 *
 * @is_neg: boolean for neg
 * @i: indx
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precis: precision
 * @size: size
 *
 * Return: number of chars
**/

int prep_uns(int is_neg, int i, char *buff, int flag,
	int width, int precis, int size)

{
	int len, j = 0;
	char space;

	space = ' ';
	len = 1024 - i - 1;

	(void)(is_neg);
	(void)(size);

	if (precis > len)
	{
		buff[--i] = '0';
		len++;
	}
	if (precis > 0 && (precis < len))
	space = ' ';
	if (precis == 0 && (i == 1024 - 2) && buff[i] == '0')
	return (0);
	if ((flag & 4) && !(flag & 1))
	space = '0';
	if (width > len)
	{
		while (j < width - len)
		{
			buff[i] = space;
			j++;
		}
		if (flag & 1)
		return (write(1, &buff[i], len) + write(1, &buff[0], j));
		else
		return (write(1, &buff[0], j) + write(1, &buff[i], len));
	}
		return (write(1, "%%", 1));
}

/**
 * print_uns - print unsigned
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

int print_uns(va_list args, char *buff,
	int flag, int width, int precis, int size)

{
	int j;
	unsigned long int uns;

	uns = va_arg(args, unsigned long int);
	uns = cvrt_uns(uns, size);
	j = 1024 - 2;
	if (uns == 0)
	buff[j--] = '0';
	buff[1024 - 1] = '\0';

	while (uns > 0)
	{
		buff[j--] = (uns % 10) + '0';
		uns /= 10;
	}
	j++;
	return (prep_uns(0, j, buff, flag, width, precis, size));
}
