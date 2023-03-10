#include <stdio.h>
#include "main.h"
/**
 * main - this program prints the number of arguments passed
 * @argv: array of arguments
 * @argc: number of arguments
 *
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
		printf("%d\n", argc - 1);
		return (0);
		argv++;
}
