#include "function_pointers.h"
#include <stdlib.h>
/**
 * print_name - prints a name
 * @name: variable for the name
 * @f: ppinter to the function
 *
 * Return: nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
