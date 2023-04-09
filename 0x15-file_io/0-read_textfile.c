#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints its content to POSIX stdout
 *
 * @filename: name of the file to be read
 * @letters: maximum number of bytes to be read and printed
 *
 * Return: number of bytes read and printed, or 0 if an error occurs
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd, output;
    ssize_t size;
    char *buf;

    buf = malloc(sizeof(char) * letters);
    if (buf == NULL || filename == NULL)
        return (0);

    /* Open the file */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buf);
        return (0);
    }

    /* Read the file */
    size = read(fd, buf, letters);
    if (size == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }

    /* Print the file content to stdout */
    output = write(STDOUT_FILENO, buf, size);
    if (output == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }

    /* Close the file and free the buffer */
    close(fd);
    free(buf);

    return (output);
}

