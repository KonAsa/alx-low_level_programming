#include <stdlib.h>
#include <limits.h>
#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: the input string
 *
 * Return: copy
 */

char *_strdup(char *str)
{
	unsigned int i, j, k;
	char *copy;

	if (str == NULL)
	{
		return (NULL);
	}
	for (k = 0; str[k] != '\0'; k++)
	{}

	copy = malloc(sizeof(*str) * k + 1);

	if (copy == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < k; i++)
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			copy[j] = str[j];
		}
	}

	return (copy);
	free(copy);

}
