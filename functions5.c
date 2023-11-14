/**
 * isnum - a function to check if a char is an int
 *
 * @c: character to check
 *
 * Return: 1 or 0
**/

int isnum(char c)

{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

/**
 * _isprint - a function to check if a char can be printed
 *
 * @c: character
 *
 * Return: 1 or 0
**/

int _isprint(char c)

{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}

/**
 * size_dig - a function to check if long or short
 *
 * @n: number to check
 * @s: size of number
 *
 * Return: short or long
**/

long int size_dig(long int n, int s)
{
	if (s == 2)
		return (n);
	else if (s == 1)
		return ((short)n);
	return ((int)n);
}
