/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** get filess content from a buffer
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "file.h"
#include "my.h"

static char *close_and_return_null(int fd)
{
    close(fd);
    return (NULL);
}

char *fs_get_content(char const *path)
{
    char *buffer = NULL;
    int size = 0;
    int nbyte = 0;
    int fd = open_ronly(path);

    if (fd < 0)
        return (NULL);
    size = file_size(path);
    if (size <= 0)
        return (close_and_return_null(fd));
    buffer = my_calloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return (close_and_return_null(fd));
    nbyte = read(fd, buffer, size);
    if (nbyte != size) {
        free(buffer);
        return (close_and_return_null(fd));
    }
    return (buffer);
}
