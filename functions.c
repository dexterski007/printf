#include "main.h"

/**
 * len_count - a function to count integer length
 *
 * @n: number
 *
 * Return: counted characters
**/

int len_count(int n)

{
	if (n == 0)
	return (0);

	return (1 + len_count(n / 10));
}


/**
 * print_integer - a function to print integers
 *
 * @n: number
 *
 * Return: Number of printed characters
**/

int print_integer(int n)
{
	unsigned int r;
	int i = 0;

	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		i += 2;
		print_integer(147483648);
	}

	if (n < 0)
	{
	n = n * -1;
	r = n;
	_putchar('-');
	i++;
	}
	r = n;
	r = r / 10;
	if (r != 0)
	print_integer(r);
	_putchar((unsigned int) n % 10 + '0');
	i += len_count(n);
	return (i);
}
