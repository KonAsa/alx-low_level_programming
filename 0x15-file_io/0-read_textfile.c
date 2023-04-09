#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX stdout.
 * @filename: file descriptor
 * @letters: number of bytes
 *
 * Return: number of bytes printed to stdout or 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, size, output;
	char *rd;

	rd = malloc(sizeof(char) * letters);

	/* open file */
	fd = open(filename, O_RDONLY);
	if (fd == -1 || filename == NULL || rd == NULL)
	{
		free(rd);
		return (0);
	}

	/* read file */
	size = read(fd, rd, letters);
	if (size == -1)
	{
		return (0);
	}
	rd[size] = '\0';

	/* write to stdout */
	output = write(STDOUT_FILENO, rd, size);

	close(fd);
	free(rd);

	return (output);
}

