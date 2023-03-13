#include <stdlib.h>
#include "main.h"

/**
 * create_array - creates an array and initialises with a specific character
 *@size: size of memory
 *@c: character initialised
 *
 * Return: pointer to the array or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *array;

	array = malloc(sizeof(char) * size);
	if (size == 0)
	{
		return (NULL);
	}
	else if (array == NULL)
	{
		return (NULL);
	}

	while (i < size)
	{
		array[i] = c;
		i++;
	}
	return (array);

}
