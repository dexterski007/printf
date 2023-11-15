#include "main.h"

/**
 * pointer_printer - print pointer
 *
 * @buff: buffer
 * @ind: index
 * @len: length
 * @wid: width
 * @flag: flag
 * @space: char
 * @end: additional
 * @space_start: start char
 *
 * Return: total
 */
int pointer_printer(char *buff, int ind, int len,
	int wid, int flag, char space, char end, int space_start)
{
	int i;

	if (wid > len)
	{
		for (i = 3; i < wid - len + 3; i++)
			buff[i] = space;
		buff[i] = '\0';
		if (flag & 1 && space == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (end)
				buff[--ind] = end;
			return (write(1, &buff[ind], len) + write(1, &buff[3], i - 3));
		}
		else if (!(flag & 1) && space == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (end)
				buff[--ind] = end;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
		}
		else if (!(flag & 1) && space == '0')
		{
			if (end)
				buff[--space_start] = end;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[space_start], i - space_start) +
				write(1, &buff[ind], len - (1 - space_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (end)
		buff[--ind] = end;
	return (write(1, &buff[ind], 1024 - ind - 1));
}

/**
 * char_printer - char ptinter
 *
 * @c: char
 * @buff: buffer
 * @flag:  flag
 * @wid: width
 * @preci: precision
 * @size: Size
 *
 * Return: count
 */
int char_printer(char c, char *buff,
	int flag, int wid, int preci, int size)
{
	int j = 0;
	char space = ' ';

	(void)(preci);
	(void)(size);

	if (flag & 4)
		space = '0';
	buff[j++] = c;
	buff[j] = '\0';

	if (wid > 1)
	{
		buff[1024 - 1] = '\0';
		for (j = 0; j < wid - 1; j++)
			buff[1024 - j - 2] = space;

		if (flag & 1)
			return (write(1, &buff[0], 1) +
			write(1, &buff[1024 - j - 1], wid - 1));
		else
			return (write(1, &buff[1024 - j - 1], wid - 1) +
			write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

/**
 * unsigned_printer - printer of unsigned
 *
 * @chkneg: negative flag
 * @ind: index
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 *
 * Return: count
 */
int unsigned_printer(int chkneg, int ind,
	char *buff,
	int flag, int wid, int preci, int size)
{
	int len = 1024 - ind - 1, i = 0;
	char space = ' ';

	(void)(chkneg);
	(void)(size);

	if (preci == 0 && ind == 1024 - 2 && buff[ind] == '0')
		return (0);
	if (preci > 0 && preci < len)
		space = ' ';
	while (preci > len)
	{
		buff[--ind] = '0';
		len++;
	}
	if ((flag & 4) && !(flag & 1))
		space = '0';
	if (wid > len)
	{
		for (i = 0; < wid - len; i++)
			buff[i] = space;
		buff[i] = '\0';
		if (flag & 1)
			return (write(1, &buff[ind], len) + write(1, &buff[0], i));
		else
			return (write(1, &buff[0], i) + write(1, &buff[ind], len));
	}
	return (write(1, &buff[ind], len));
}

/**
 * string_printer - print string
 *
 * @chkneg: negative check
 * @ind: index
 * @buff: buffer
 * @flag:  flag
 * @wid: width
 * @preci: precision
 * @size: size
 *
 * Return: count
 */
int string_printer(int chkneg, int ind, char *buff,
	int flag, int wid, int preci, int size)
{
	int len = 1024 - ind - 1;
	char space = ' ', end = 0;

	(void)(size);
	if ((flag & 4) && !(flag & 1))
		space = '0';
	if (chkneg)
		end = '-';
	else if (flag & 2)
		end = '+';
	else if (flag & 16)
		end = ' ';
	return (number_printer(ind, buff, flag, wid, preci,
		len, space, end));
}

/**
 * number_printer - print number
 *
 * @ind: index
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @prec: precision
 * @len: length
 * @space: space or anything
 * @end: additional
 *
 * Return: count
 */
int number_printer(int ind, char buff[],
	int flag, int wid, int prec,
	int len, char space, char end)
{
	int i, space_start = 1;

	if (prec == 0 && ind == 1024 - 2 && buff[ind] == '0' && wid == 0)
		return (0);
	if (prec == 0 && ind == 1024 - 2 && buff[ind] == '0')
		buff[ind] = space = ' ';
	if (prec > 0 && prec < len)
		space = ' ';
	while (prec > len)
		buff[--ind] = '0', len++;
	if (end != 0)
		len++;
	if (wid > len)
	{
		for (i = 1; i < wid - len + 1; i++)
			buff[i] = space;
		buff[i] = '\0';
		if (flag & 1 && space == ' ')
		{
			if (end)
				buff[--ind] = end;
			return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
		}
		else if (!(flag & 1) && space == ' ')
		{
			if (end)
				buff[--ind] = end;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
		}
		else if (!(flag & 1) && space == '0')
		{
			if (end)
				buff[--space_start] = end;
			return (write(1, &buff[space_start], i - space_start) +
				write(1, &buff[ind], len - (1 - space_start)));
		}
	}
	if (end)
		buff[--ind] = end;
	return (write(1, &buff[ind], len));
}
