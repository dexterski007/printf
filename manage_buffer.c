#include "main.h"

/**
 * manage_buffer - manage and print bufer
 * @buff: buffer
 * @index: buffer position
 */
void manage_buffer(char *buff, int *index)
{
	if (*index > 0)
		write(1, &buff[0], *index);

	*index = 0;
}
