#include "main.h"

/**
 * get_wid - detect width
 *
 * @format: string
 * @ind: index
 * @args: list of arguments.
 *
 * Return: width
 */
int get_wid(const char *format, int *ind, va_list args)
{
	int act_ind = *ind + 1;
	int wid = 0;

	while (format[act_ind] != '\0')
	{
		if (chkdig(format[act_ind]))
		{
			wid *= 10;
			wid += format[act_ind] - '0';
		}
		else if (format[act_ind] == '*')
		{
			act_ind++;
			wid = va_arg(args, int);
			break;
		}
		else
			break;
		act_ind++;
	}
	*ind = act_ind - 1;
	return (wid);
}

/**
 * get_size - detect size
 *
 * @format: string
 * @ind: index
 *
 * Return: size
 */
int get_size(const char *format, int *ind)
{
	int act_ind = *ind + 1;
	int size = 0;

	if (format[act_ind] == 'l')
		size = 2;
	else if (format[act_ind] == 'h')
		size = 1;

	if (size == 0)
		*ind = act_ind - 1;
	else
		*ind = act_ind;

	return (size);
}

/**
 * get_preci - dectet precision
 *
 * @format: string
 * @ind: index
 * @args: args
 *
 * Return: precision
 */
int get_preci(const char *format, int *ind, va_list args)
{
	int act_ind = *ind + 1;
	int preci = -1;

	if (format[act_ind] != '.')
		return (preci);

	preci = 0;
	for (act_ind += 1; format[act_ind] != '\0'; act_ind++)
	{
		if (chkdig(format[act_ind]))
		{
			preci *= 10;
			preci += format[act_ind] - '0';
		}
		else if (format[act_ind] == '*')
		{
			act_ind++;
			preci = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*ind = act_ind - 1;

	return (preci);
}

/**
 * get_flag - detect flag
 *
 * @format: string
 * @ind: index
 *
 * Return: flag
 */
int get_flag(const char *format, int *ind)
{
	int j = 0, act_ind;
	int flag = 0;
	const int flag_arr[] = {1, 2, 4, 8, 16, 0};
	const char flag_id[] = {'-', '+', '0', '#', ' ', '\0'};

	act_ind = *ind + 1;

	while (format[act_ind] != '\0')
	{
		for (j = 0; flag_id[j] != '\0'; j++)
			if (format[act_ind] == flag_id[j])
			{
				flag |= flag_arr[j];
				break;
			}
		if (flag_id[j] == 0)
			break;
		act_ind++;
	}
	*ind = act_ind - 1;
	return (flag);
}
