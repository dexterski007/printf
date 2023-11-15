#include "main.h"

/**
 * _printf - a revolutionary printf function
 * @format: format?
 * Return: counter
 */
int _printf(const char *format, ...)
{
	int i = 0, ok = 0;
	int counter = 0;
	int flag, wid, preci;
	int size, index = 0;
	char buffer[1024];
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == 1024)
				manage_buffer(buffer, &index);
			counter++;
		}
		else
		{
			manage_buffer(buffer, &index);
			flag = get_flag(format, &i);
			wid = get_wid(format, &i, args);
			preci = get_preci(format, &i, args);
			size = get_size(format, &i);
			++i;
			ok = printer(format, &i, args, buffer,
				flag, wid, preci, size);
			if (ok == -1)
				return (-1);
			counter += ok;
		}
		i++;
	}
	manage_buffer(buffer, &index);
	va_end(args);
	return (counter);
}
