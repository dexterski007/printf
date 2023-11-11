#include "main.h"

/**
 * _printf - An alternative printf function
 *
 * @format: format specifier
 * @...: arguments
 *
 * Return: Number of printed characters
**/

int _printf(const char *format, ...)

{
	int i = 0, ptot = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			ptot++;
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
				ptot += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				ptot += print_string(va_arg(args, char *));
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

	for (i = 0; str[i] != '\0'; i++)
	_putchar(str[i]);

	return (i);
}
