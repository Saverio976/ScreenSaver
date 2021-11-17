/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** reverse str
*/

#include "my.h"

char *my_revstr(char *str)
{
    char c;
    int len = my_strlen(str) - 1;

    for (int i = 0; i <= len / 2; i++) {
        c = str[i];
        str[i] = str[len - i];
        str[len - i] = c;
    }
    return (str);
}
