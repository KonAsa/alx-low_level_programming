#include <stdio.h>
#include <string.h>

int wildcmp(char *s1, char *s2)
{
    /* Base case: both strings are empty */
    if (*s1 == '\0' && *s2 == '\0')
        return 1;

    /* If the current character in s2 is a wildcard, recursively check all possible matches */
    if (*s2 == '*') {
        /* Check all possible matches starting from the current position in s1 */
        while (*s1 != '\0') {
            if (wildcmp(s1, s2 + 1))
                return 1;
            s1++;
        }
        /* If no match is found, return 0 */
        return 0;
    }

    /* If the current characters in s1 and s2 match or the current character in s2 is '?', move to the next character */
    if (*s1 == *s2 || *s2 == '?')
        return wildcmp(s1 + 1, s2 + 1);

    /* If none of the above conditions are met, return 0 */
    return 0;
}

