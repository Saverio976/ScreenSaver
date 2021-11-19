/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** try to abstract file
*/

#ifndef FILE_H_
    #define FILE_H_

int has_file_perm(char const *, char);
int is_file(char const *, char);
int open_ronly(char const *);
int file_size(char const *);
char *fs_get_content(char const *);

#endif
