/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** check what type is a file (directory, file, ..)
*/

#include <sys/stat.h>

//check if a path is of type :
// d : directory
// f : file
int is_file(char const *path, char perm)
{
    struct stat info;
    int ret = 0;

    ret = stat(path, &info);
    if (ret != 0)
        return (0);
    if (perm == 'd')
        return ((info.st_mode & S_IFMT) == S_IFDIR);
    if (perm == 'f')
        return ((info.st_mode & S_IFMT) == S_IFREG);
    return (0);
}
