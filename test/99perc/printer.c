#include "main.h"
/**
 * printer - manage printer
 * @funcs: functions
 * @args: arguments
 * @ind: index
 * @buff: buffer
 * @flag: detect flag
 * @wid: detect width
 * @preci: detect precision
 * @size: detect size
 *
 * Return: 1 or 2;
 */
int printer(const char *funcs, int *ind, va_list args, char buff[],
	int flag, int wid, int preci, int size)
{
	int i, unkn = 0, counter = -1;
	functionsp specifier[] = {
		{'c', pr_char}, {'s', pr_str},
		{'%', pr_perc}, {'i', pr_int},
		{'d', pr_int}, {'b', pr_bin},
		{'u', pr_uns}, {'o', pr_oct},
		{'x', pr_hex}, {'X', pr_HEXA},
		{'p', pr_point}, {'S', pr_n_char},
		{'r', pr_rev}, {'R', pr_crypto13}, {'\0', NULL}
	};
	for (i = 0; specifier[i].funcs != '\0'; i++)
		if (funcs[*ind] == specifier[i].funcs)
			return (specifier[i].ck(args, buff, flag, wid, preci, size));

	if (specifier[i].funcs == '\0')
	{
		if (funcs[*ind] == '\0')
			return (-1);
		unkn += write(1, "%%", 1);
		if (funcs[*ind - 1] == ' ')
			unkn += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (funcs[*ind] != ' ' && funcs[*ind] != '%')
				--(*ind);
			if (funcs[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unkn += write(1, &funcs[*ind], 1);
		return (unkn);
	}
	return (counter);
}
