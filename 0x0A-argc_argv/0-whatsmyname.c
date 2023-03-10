#include <stdio.h>
#include "main.h"

/**
 * main - program prints it's name followed by a newline
 * @argv: commandline argument array
 * @argc: count of command line arguments
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	while (argc--)
	{
		printf("%s\n", *argv);
			argv++;
	}
	return (0);
}

