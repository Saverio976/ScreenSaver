/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** open a file in read only
*/

#include <fcntl.h>
#include "file.h"

// open read only

int open_ronly(char const *path)
{
    int fd = open(path, O_RDONLY);

    return (fd);
}
