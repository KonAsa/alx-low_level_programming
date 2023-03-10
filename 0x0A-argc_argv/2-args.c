#include <stdio.h>
#include "main.h"

/**
 * main - prints all the arguments of argv
 * @argc: the count of arguments
 * @argv: the array of arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	while (argc--)
	{
		printf("%s\n", *argv++);
	}
	return (0);
}

