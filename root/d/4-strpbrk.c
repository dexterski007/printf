#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 *
 * @s: The string to be searched.
 *
 * @accept: The characters to search for.
 *
 * Return: A pointer the first occurrence of any character in (accept) in (s),
 *         or NULL if no such character is found.
 */

char *_strpbrk(char *s, char *accept)
{
	int k, j;

	for (k = 0; s[k] != '\0'; k++)
	{
	for (j = 0; accept[j] != '\0'; j++)
	{
	if (s[k] == accept[j])
	return (s + k);
	}
	}
	return (0);
}
