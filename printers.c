#include "main.h"

/**
 * pr_rev - print reverse
 *
 * @args: Lista of arguments
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */

int pr_rev(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	char *str;
	int i = 0, count = 0;
	char z;

	(void)(buff);
	(void)(flag);
	(void)(wid);
	(void)(size);
	str = va_arg(args, char *);
	if (str == NULL)
	{
		(void)(preci);
		str = ")Null(";
	}
	while (str[i])
	i++;
	for (i = i - 1; i >= 0; i--)
	{
		z = str[i];
		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * pr_crypto13 - rotate string
 *
 * @args: args
 * @buff: buffer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_crypto13(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	char c;
	char *str;
	unsigned int i = 0, j = 0;
	char org[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char fak[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int count = 0;

	str = va_arg(args, char *);
	(void)(buff);
	(void)(flag);
	(void)(wid);
	(void)(preci);
	(void)(size);

	if (str == NULL)
		str = "(AHYY)";
	while (str[i])
	{
		for (j = 0; org[j]; j++)
		{
			if (org[j] == str[i])
			{
				c = fak[j];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!org[j])
		{
			c = str[i];
			write(1, &c, 1);
			count++;
		}
		i++;
	}
	return (count);
}


/**
 * pr_n_char - print non printable
 *
 * @args: args
 * @buff: bufferer
 * @flag: flag
 * @wid: width
 * @preci: precious
 * @size: size
 * Return: count
 */

int pr_n_char(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	int i = 0, offs = 0;
	char *str = va_arg(args, char *);

	(void)(flag);
	(void)(wid);
	(void)(preci);
	(void)(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (printed_det(str[i]))
			buff[i + offs] = str[i];
		else
			offs += hex_map(str[i], buff, i + offs);
		i++;
	}
	buff[i + offs] = '\0';
	return (write(1, buff, i + offs));
}

/**
 * pr_point - pointer ptint
 *
 * @args: arguments
 * @buff: bufferer
 * @flag: flag
 * @wid: width
 * @preci: precision
 * @size: size
 * Return: count
 */
int pr_point(va_list args, char *buff,
	int flag, int wid, int preci, int size)
{
	char end = 0, space = ' ';
	int ind = 1024 - 2, len = 2, space_start = 1;
	unsigned long num_adr;
	char map[] = "0123456789abcdef";
	void *adr = va_arg(args, void *);

	(void)(wid);
	(void)(size);

	if (adr == NULL)
		return (write(1, "(nil)", 5));
	buff[1024 - 1] = '\0';
	(void)(preci);

	num_adr = (unsigned long)adr;
	while (num_adr > 0)
	{
		buff[ind--] = map[num_adr % 16];
		num_adr /= 16;
		len++;
	}
	if ((flag & 4) && !(flag & 1))
		space = '0';
	if (flag & 2)
		end = '+', len++;
	else if (flag & 16)
		end = ' ', len++;
	ind++;
	return (pointer_printer(buff, ind, len,
		wid, flag, space, end, space_start));
}
