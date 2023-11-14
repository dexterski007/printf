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
	int i = 1;

	if (n == 0)
	return (0);

	if (n < 0)
	{
		n = -n;
		i++;
	}

	while ((n / 10) != 0)
		i++;

	return (i);
}


/**
 * print_integer - a function to print integers
 *
 * @n: number
 *
 * Return: Nothing
**/

void print_integer(int n)
{
	unsigned long int r;
	int is_neg = 0;

	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		print_integer(147483648);
		return;
	}
	if (n < 0)
	{
		n = -n;
		is_neg = 1;
	}

	while (n % 10 == 0)
		n = n / 10;

	r = n / 10;
	if (r != 0)
	print_integer(r);
	if (is_neg)
	_putchar('-');

	_putchar(n % 10 + '0');
}
