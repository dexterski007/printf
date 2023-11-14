#include "main.h"

/**
 * _strspn - Gets length prefix substring consists of only specific characters.
 * @s: The string to be checked.
 * @accept: The string containing the characters to be counted in the prefix.
 *
 * Return: number characters at beginning of (s) match character in (accept).
 */
unsigned int _strspn(char *s, char *accept)
{
	/* Initialize the count of matching characters */
	unsigned int i = 0;
	int k;

	/* Loop through the characters in s */
	while (*s)
	{
		/* Loop through the characters in accept */
		for (k = 0; accept[k]; k++)
		{
			if (*s == accept[k])
			{
				i++; /* Increment the count when a character matches */
				break; /* Exit the inner loop */
			}
		}
		if (accept[k] == '\0')
			return (i); /* If character not found in accept, stop counting */
		s++;
	}
	return (i); /* Return the count of matching characters */
}

