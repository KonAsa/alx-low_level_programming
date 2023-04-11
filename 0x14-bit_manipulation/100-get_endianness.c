#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: If the system is little-endian - 1.
 *         If the system is big-endian - 0.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *byte_pointer = (char *)&num;

	if (*byte_pointer == 1)
		return (1);
	else
		return (0);
}

