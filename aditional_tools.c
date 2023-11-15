#include "main.h"

/**
 * hex_map - complete hex
 *
 * @buff: buffer
 * @ind: Index
 * @c: char
 *
 * Return: 3
 */
int hex_map(char c, char *buff, int ind)
{
	char app[] = "0123456789ABCDEF";

	if (c < 0)
		c *= -1;
	buff[ind++] = '\\';
	buff[ind++] = 'x';
	buff[ind++] = app[c / 16];
	buff[ind] = app[c % 16];

	return (3);
}

/**
 * correct_size - detect size
 * @nbr: nubzer
 * @size: check size
 *
 * Return: value
 */
long int correct_size(long int nbr, int size)
{
	if (size == 2)
		return (nbr);


	else if (size == 1)
		return ((short)nbr);
	return ((int)nbr);
}

/**
 * chkdig - detect nbrber
 *
 * @c: char
 * Return: 1 or 0
 */
int chkdig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * correct_uns - detect size for uns
 * @nbr: number
 * @size: check size
 *
 * Return: value
 */
long int correct_uns(unsigned long int nbr, int size)
{
	if (size == 2)
		return (nbr);
	else if (size == 1)
		return ((unsigned short)nbr);

	return ((unsigned int)nbr);
}

/**
 * printed_det - detect prinbtable
 *
 * @c: char
 *
 * Return: value
 */
int printed_det(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
