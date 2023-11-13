/**
 * isnum - a function to check if a char is an int
 *
 * @c: character
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
