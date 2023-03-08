#include "main.h"

/**
 * wildcmp - Compares two strings, taking wildcard characters into account
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
    if (*s2 == '*')
    {
        if (*(s2 + 1) == '*')
        {
            return (wildcmp(s1, s2 + 1));
        }
        else if (wildcmp(s1, s2 + 1))
        {
            return (1);
        }
        else
        {
            return (wildcmp(s1 + 1, s2));
        }
    }

    if (*s1 != *s2)
    {
        return (0);
    }

    if (*s1 == '\0' && *s2 == '\0')
    {
        return (1);
    }

    return (wildcmp(s1 + 1, s2 + 1));
}

