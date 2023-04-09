#include "main.h"

#define BUFFER_SIZE 1024

void copy_file(const char *source_file, const char *destination_file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp SOURCE DEST\n");
        exit(EXIT_FAILURE);
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    copy_file(source_file, destination_file);

    return 0;
}

void copy_file(const char *source_file, const char *destination_file) {
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        dprintf(STDERR_FILENO, "Error: Can't open %s for reading\n", source_file);
        exit(EXIT_FAILURE);
    }

    int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (destination_fd == -1) {
        dprintf(STDERR_FILENO, "Error: Can't open %s for writing\n", destination_file);
        close(source_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            dprintf(STDERR_FILENO, "Error: Write failed\n");
            close(source_fd);
            close(destination_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        dprintf(STDERR_FILENO, "Error: Read failed\n");
        close(source_fd);
        close(destination_fd);
        exit(EXIT_FAILURE);
    }

    if (close(source_fd) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close %s\n", source_file);
        exit(EXIT_FAILURE);
    }

    if (close(destination_fd) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close %s\n", destination_file);
        exit(EXIT_FAILURE);
    }
}

