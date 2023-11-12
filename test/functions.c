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
 * Return: Nothing
**/

void print_integer(int n)
{
	long int r;

	if (n < 0)
	{
	n = n * -1;
	_putchar('-');
	}
	r = n;
	r = r / 10;
	if (r != 0)
	print_integer(r);
	_putchar((long int) n % 10 + '0');
}
