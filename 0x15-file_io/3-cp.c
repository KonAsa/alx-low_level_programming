#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error - prints an error message to stderr and exits with a given code
 * @msg: the error message format string
 * @arg: the argument for the format string
 * @code: the exit code
 */
void error(char *msg, char *arg, int code)
{
	fprintf(stderr, "Error: ");
	fprintf(stderr, msg, arg);
	fprintf(stderr, "\n");
	exit(code);
}

/**
 * copy_file - copies the contents of one file to another file
 * @src: the path to the source file
 * @dst: the path to the destination file
 */
void copy_file(char *src, char *dst)
{
	int fd1, fd2, r, w;
	char buf[1024];

	fd1 = open(src, O_RDONLY);
	if (fd1 < 0)
		error("Can't read from file %s", src, 98);

	fd2 = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd2 < 0)
		error("Can't write to %s", dst, 99);

	while ((r = read(fd1, buf, 1024)) > 0)
	{
		w = write(fd2, buf, r);
		if (w < 0)
			error("Can't write to %s", dst, 99);
	}
	if (r < 0)
		error("Can't read from file %s", src, 98);

	close(fd1);
	close(fd2);
}

/**
 * main - entry point of the program
 * @argc: the number of arguments
 * @argv: an array of strings representing the arguments
 * Return: 0 on success, 97-100 on error
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

