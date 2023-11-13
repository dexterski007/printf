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
	int i = 0, ptot = 0, is_printed = 0;
	int flag = 0, width = 0, size = 0, b_ind = 0, precis = 0;
	char buff[1024];
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[b_ind++] = format[i];
			if (b_ind == 1024)
				p_buff(buff, &b_ind);
			ptot++;
		}
		else
		{
			p_buff(buff, &b_ind);
			flag = w_flag(format, &i);
			width = w_width(format, &i, args);
			precis = w_precis(format, &i, args);
			size = w_size(format, &i);
			i++;
			is_printed = printer(format, &i, args, buff, flag, width, precis, size);
			if (is_printed == -1)
				return (-1);
			ptot += is_printed;
		}
	}

	p_buff(buff, &b_ind);
	va_end(args);
	return (ptot);
}

