#include "main.h"

/**
 * _printf - An new way to printf
 *
 * @format: format specifier
 * @...: args
 *
 * Return: Num of printd characters
**/

int _printf(const char *format, ...)
{
	int k = 0, ptot = 0, is_printed = 0;
	int flag = 0, width = 0, size = 0, b_ind = 0, precis = 0;
	char buff[1024];
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (k = 0; format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buff[b_ind++] = format[k];
			if (b_ind == 1024)
				p_buff(buff, &b_ind);
			ptot++;
		}
		else
		{
			p_buff(buff, &b_ind);
			flag = w_flag(format, &k);
			width = w_width(format, &k, args);
			precis = w_precis(format, &k, args);
			size = w_size(format, &k);
			k++;
			is_printed = printer(format, &k, args, buff, flag, width, precis, size);
			if (is_printed == -1)
				return (-1);
			ptot += is_printed;
		}
	}

	p_buff(buff, &b_ind);
	va_end(args);
	return (ptot);
}

