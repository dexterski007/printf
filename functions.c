#include "main.h"

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

	r = n;
	if (n < 0)
	{
	n = n * -1;
	r = n;
	_putchar('-');
	i++;
	}
	r = r / 10;
	if (r != 0)
	print_integer(r);
	_putchar((unsigned int) n % 10 + '0');
	i++;
	return (i);
}
