#include "main.h"

/**
 * _printf - custom printf implementation
 *
 * @format: format specifier
 * @...: arguments
 *
 * Return: Number of printed characters
**/

int _printf(const char *format, ...)
{
	long int i = 0, ptot = 0, digit = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			ptot += _putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
				ptot += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				ptot += print_string(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				{
				digit = va_arg(args, int);
				if (digit < 0)
				ptot++;
				ptot += len_count(digit);
				print_integer(digit);
				}
			else if (format[i] == '%')
				ptot += _putchar('%');
			else
			{
				ptot += _putchar('%');
				ptot += _putchar(format[i]);
			}
		}
		else
		ptot += _putchar('%');
	}
	va_end(args);
	return (ptot);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_string - prints a string to stdout
 * @str: The string to print
 *
 * Return: On success the length of the string.
 */
int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
	str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	_putchar(str[i]);

	return (i);
}
