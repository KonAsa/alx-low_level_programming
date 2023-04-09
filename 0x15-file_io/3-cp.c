#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument array
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char **argv)
{
    int fd1, fd2, r1, w1;
    char buf[1024];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        return (97);
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        return (98);
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd2 == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        return (99);
    }

    while ((r1 = read(fd1, buf, 1024)) > 0)
    {
        w1 = write(fd2, buf, r1);
        if (w1 == -1 || w1 != r1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            return (99);
        }
    }

    if (r1 == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        return (98);
    }

    if (close(fd1) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
        return (100);
    }

    if (close(fd2) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
        return (100);
    }

    return (0);
}

