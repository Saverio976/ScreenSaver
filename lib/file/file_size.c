/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** return the nbyte of a file
*/

#include <sys/stat.h>

// return teh nbyte of a file
// -1 : stat() error
// other : file size
int file_size(char const *path)
{
    struct stat info;
    int ret;

    ret = stat(path, &info);
    if (ret == -1)
        return (-1);
    return ((int) info.st_size);
}
