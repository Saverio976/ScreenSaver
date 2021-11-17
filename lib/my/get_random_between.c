/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** get random number between a and b
*/

#include <stdlib.h>

int get_random_between(int a, int b)
{
    int i = rand();

    i = i % b;
    return (i + a);
}
