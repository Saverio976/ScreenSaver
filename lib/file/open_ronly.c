/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** open a file in read only
*/

#include <fcntl.h>
#include "file.h"

// open read only
// return -1 if path is not a file
// return -2 if exe has not read permissions
// above or equal 0 for sucess
int open_ronly(char const *path)
{
    if (!is_file(path, 'f'))
        return (-1);
    if (!has_file_perm(path, 'r'))
        return (-2);
    return (open(path, O_RDONLY));
}
