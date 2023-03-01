#include "main.h"

/**
 * rot13 - Encodes string in rot13 encryption
 * @s: String variable
 *
 * Return: s
 */

char *rot13(char *s)
{
	int i, j;
	char encode[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char encoder[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; encode[j] != '\0'; j++)
		{
			if (s[i] == encode[j])
			{
				s[i] = encoder[j];
				break;
			}
		}
	}
	return (s);
}
