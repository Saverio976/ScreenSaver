/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** check some perms a path has
*/

#include <unistd.h>
#include <sys/stat.h>

// check if a file has permission for :
// r : read
// w : write
// x : execute
int has_file_perm(char const *path, char perm)
{
    struct stat info;
    int ret = 0;

    ret = stat(path, &info);
    if (ret != 0)
        return (0);
    if (perm == 'r')
        return (info.st_mode & R_OK);
    if (perm == 'w')
        return (info.st_mode & W_OK);
    if (perm == 'x')
        return (info.st_mode & W_OK);
    return (0);
}
