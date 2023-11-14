#include "main.h"

/**
 * _memcpy - Copies memory from source to destination.
 *
 * @src: Pointer to the source memory.
 *
 * @dest: Pointer to the destination memory.
 *
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory (dest).
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
	{
	dest[k] = src[k];
	}
	return (dest);
}
