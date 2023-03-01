#include "main.h"

/**
 * *_strcat - function concatenates two strings
 *@dest: variable for destination string
 *@src: variable for source string
 * Return: Pointer to the resulting string
 *
 */
char *_strcat(char *dest, char *src)
{
	int length, i;

	length = 0;

	/*store the length of the destination string*/

	while (dest[length] != '\0')
	{
		length++;
	}
	/*Add the two strings*/

	i = 0;

	while (src[i] != '\0')
	{
		dest[length] = src[i];
		i++;
		length++;
	}
	/*terminate destination string*/
	dest[length] = '\0';
	return (dest);
}
