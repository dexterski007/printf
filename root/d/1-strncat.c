#include "main.h"

/**
 * _strncat - Concatenate two strings, using at most n bytes from src
 * @dest: The destination string
 * @src: The source string to be appended
 * @n: The maximum number of bytes to append from src
 *
 * Return: A pointer to the destination string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
	dest[i] = src[j];
	i++;
	j++;
	}
	dest[i] = '\0';
	return (dest);
}
