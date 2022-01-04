/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** alloc and set all \0
*/

#include <stdlib.h>

char *my_calloc(int n)
{
    char *new = malloc(sizeof(char) * n);

    if (!new)
        return (NULL);
    for (int i = 0; i < n; i++)
        new[i] = '\0';
    return (new);
}
