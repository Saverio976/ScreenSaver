/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** get urandom number between a and b
*/

#include <stdlib.h>

unsigned int get_urandom_between(int a, int b)
{
    int i = rand();

    i = i % b;
    return ((unsigned int) i + a);
}
