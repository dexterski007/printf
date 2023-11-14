#include "main.h"
/**
 * _strcpy - Copies the string pointed to by src to dest.
 * @dest: The destination where the string will be copied.
 * @src: The source string to be copied from.
 *
 * Return: A pointer to the destination string (dest).
 */

char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
