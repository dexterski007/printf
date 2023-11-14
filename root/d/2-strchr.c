#include "main.h"

/**
 * _strchr - Locates the first occurrence of a character in a string.
 *
 * @s: The string to search within.
 *
 * @c: The character to locate.
 *
 * Return: A pointer the first occurrence of the character (c) in string (s).
 *         If the character is not found, it returns NULL.
 */
char *_strchr(char *s, char c)
{
	int k;

	for (k = 0; s[k] >= '\0'; k++)
	{
	if (s[k] == c)
	return (s + k);
	}
	return (0);
}
