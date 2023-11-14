#include "main.h"
/**
 * _strlen - Calculates the length of a string.
 * @s: A string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}
