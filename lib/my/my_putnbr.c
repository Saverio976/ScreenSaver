/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** put nb in stdout
*/

#include "my.h"

int my_putnbr(int nb)
{
    int i = 0;
    char result[13] = {0};
    int is_neg = nb < 0;

    if (is_neg)
        nb *= -1;
    if (nb == 0)
        result[i++] = '0';
    for (; nb != 0; i++) {
        result[i] = nb % 10 + '0';
        nb /= 10;
    }
    if (is_neg)
        result[i] = '-';
    my_revstr(result);
    return (my_putstr(result));
}
