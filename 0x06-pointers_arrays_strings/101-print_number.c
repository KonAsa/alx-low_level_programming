#include "main.h"
#include <stdio.h>

/**
 * print_number - prints an integer.
 * @n: input integer.
 */

void print_number(int n)
{
	unsigned int m, d, count;

	if (n < 0)
	{
		putchar('-');
		m = n * -1;
	}
	else
	{
		m = n;
	}

	d = m;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (; count >= 1; count /= 10)
	{
		putchar(((m / count) % 10) + '0');
	}
}

