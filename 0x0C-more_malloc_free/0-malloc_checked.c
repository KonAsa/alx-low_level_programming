#include <stdlib.h>
#include "main.h"
/**
 * malloc_checked - checks if memory is allocated properly
 *@b: the size of the memory
 *
 * Return: a pointer to the allocated memory
 *
 */

void *malloc_checked(unsigned int b)
{
	unsigned int *check;

	check = malloc(b);

	if (check == NULL)
	{
		exit(98);
	}

	return (check);

	free(check);
}
