#include "main.h"

/**
 * pr_int - integer
 *
 * @args: args
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_int(va_list args, char buff[],
	int flag, int wid, int preci, int size)
{
	int i = 1024 - 2;
	int chkneg = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = correct_size(n, size);
	if (n == 0)
		buff[i--] = '0';
	buff[1024 - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		chkneg = 1;
	}
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (string_printer(chkneg, i, buff, flag, wid, preci, size));
}

/**
 * pr_perc - print percent
 *
 * @args: args
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */

int pr_perc(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	(void)(args);
	(void)(buff);
	(void)(flag);
	(void)(wid);
	(void)(preci);
	(void)(size);
	return (write(1, "%%", 1));
}

/**
 * pr_char - putchar
 *
 * @args: args
 * @buff: bufer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_char(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	char c = va_arg(args, int);

	return (char_printer(c, buff, flag, wid, preci, size));
}

/**
 * pr_bin - print binary
 *
 * @args: args
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_bin(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	unsigned int r, s, j, tot;
	unsigned int a[32];
	int count;
	char c;

	(void)(buff);
	(void)(flag);
	(void)(wid);
	(void)(preci);
	(void)(size);

	r = va_arg(args, unsigned int);
	s = 2147483648;
	a[0] = r / s;
	j = 1;
	while (j < 32)
	{
		s /= 2;
		a[j] = (r / s) % 2;
		j++;
	}
	for (j = 0, tot = 0, count = 0; j < 32; j++)
	{
		tot += a[j];
		if (tot || j == 31)
		{
			c = '0' + a[j];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}

/**
 * pr_str - string printer
 *
 * @args: args
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_str(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	int len = 0, i;
	char *str = va_arg(args, char *);

	(void)(buff);
	(void)(flag);
	(void)(wid);
	(void)(preci);
	(void)(size);
	if (str == NULL)
	{
		str = "(null)";
		if (preci >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (preci >= 0 && preci < len)
		len = preci;
	if (wid > len)
	{
		if (flag & 1)
		{
			write(1, &str[0], len);
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (wid);
		}
	}

	return (write(1, str, len));
}
