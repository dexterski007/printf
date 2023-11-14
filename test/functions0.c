#include "main.h"


/**
 * p_buff - prints the buffer
 * @buff: The buffer to print
 * @b_ind: pointer to the array index
 *
 * Return: nothing.
 */
void p_buff(char buff[], int *b_ind)
{
	if (*b_ind > 0)

	(write(1, &buff[0], *b_ind));
	*b_ind = 0;
}

/**
 * w_flag - checks the flag
 * @format: text to check
 * @i: index
 *
 * Return: flags
 */

int w_flag(const char *format, int *i)
{
	int flags = 0, c_i;
	char c_char;

	c_i = *i + 1;
	while (format[c_i] != '\0')
	{
		c_char = format[c_i];

		switch (c_char)
		{
		case '-':
			flags += 1;
			break;
		case '+':
			flags += 2;
			break;
		case '0':
			flags += 4;
			break;
		case '#':
			flags += 8;
			break;
		case ' ':
			flags += 16;
			break;
		default:
			return (flags);
		}
		(*i)++;
	}
	*i = c_i - 1;
	return (flags);
}

/**
 * w_width - checks the width
 * @format: text to check
 * @i: index
 * @args: arguments list
 *
 * Return: width.
 */

int w_width(const char *format, int *i, va_list args)
{
	int c_i = *i + 1, w = 0;

	while (format[c_i] != '\0')
	{
		if (isnum(format[c_i]))
		{
			w *= 10;
			w += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			w = va_arg(args, int);
			break;
		}
		else
				break;
		c_i++;
	}
	*i = c_i - 1;
	return (w);
}

/**
 * w_precis - checks the precision
 * @format: text to check
 * @i: index
 * @args: arguments
 *
 * Return: precision.
 */

int w_precis(const char *format, int *i, va_list args)
{
	int location = *i + 1;
	int prec = 0;

	if (format[location] != '.')
		return (-1);

	for (location += location; format[location != '\0']; location++)
	{
		if (isnum(format[location]))
		{
			prec *= 10;
			prec += (format[location] - '0');
		}
		else if (format[location] == '*')
		{
			location++;
			prec += va_arg(args, int);
			break;
		}
		else
			break;
	}
		*i = location - 1;
		return (prec);
}

/**
 * w_size - checks the size
 * @format: text to check
 * @i: index
 *
 * Return: size.
 */

int w_size(const char *format, int *i)
{
	int c_i = *i + 1, size = 0;

	if (format[c_i] == 'l')
		size = 2;
	else if (format[c_i] == 'h')
		size = 1;
	if (size == 0)
		*i = c_i - 1;
	else
		*i = c_i;
	return (size);
}
