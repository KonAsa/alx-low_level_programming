#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be flipped to convert n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int count = 0;

	while (xor != 0)
	{
		if ((xor & 1) == 1)
			count++;
		xor = xor >> 1;
	}

	return (count);
}

