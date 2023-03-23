#include <stdarg.h>
#include <stdlib.h>
#include "variadic_functions.h"

/**
 * sum_them_all - sums all arguments passed to it
 * @n: the first arguments
 *
 * Return: sum of all arguments
 */

int sum_them_all(const unsigned int n, ...)
{
va_list args;
int sum = 0;
unsigned int i;

va_start(args, n);
for (i = 0; i < n; i++)
{
sum = sum + va_arg(args, int);
}
va_end(args);
return (sum);
}
