#include "main.h"

#define BUF_SIZE 1024

/**
 * print_error - prints an error message and exits with the given code
 * @code: exit code
 * @msg: error message
 * @arg: argument to include in the error message
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * open_file - opens a file with the given mode
 * @filename: file to open
 * @mode: file mode
 * @code: exit code to use in case of error
 *
 * Return: file descriptor
 */
int open_file(const char *filename, int mode, int code)
{
	int fd = open(filename, mode);

	if (fd == -1)
		print_error(code, "Error: Can't open file %s\n", filename);

	return (fd);
}

/**
 * copy_file - copies the contents of one file to another
 * @src: source file
 * @dest: destination file
 */
void copy_file(const char *src, const char *dest)
{
	char buf[BUF_SIZE];
	ssize_t bytes_read, bytes_written;
	int fd_src, fd_dest;

	fd_src = open_file(src, O_RDONLY, 98);
	fd_dest = open_file(dest, O_WRONLY | O_CREAT | O_TRUNC, 99);

	while ((bytes_read = read(fd_src, buf, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_dest, buf, bytes_read);

		if (bytes_written == -1)
			print_error(99, "Error: Can't write to %s\n", dest);
	}

	if (bytes_read == -1)
		print_error(98, "Error: Can't read from file %s\n", src);

	if (close(fd_src) == -1)
		print_error(100, "Error: Can't close fd %d\n", fd_src);

	if (close(fd_dest) == -1)
		print_error(100, "Error: Can't close fd %d\n", fd_dest);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 97-100 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to\n", NULL);

	copy_file(argv[1], argv[2]);

	return (0);
}

