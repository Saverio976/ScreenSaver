/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** main function
*/

#include <time.h>
#include <stdlib.h>
#include "myscreensaver.h"
#include "my.h"

static const int ID_MAX = 1;
static const struct screen_struct SCREENS[1] = {
    {&screen_circles}
};

static int print_help(char const *exe)
{
    my_putstr("annimation rendering in a CSFML window.\n\n");
    my_putstr("USAGE\n\t");
    my_putstr(exe);
    my_putstr(" [OPTIONS] annimation_id\n\t");
    my_putstr(" annimation_id\tID of the annimation to process");
    my_putstr(" (between 1 and ");
    my_putnbr(ID_MAX);
    my_putstr(").\n\nOPTIONS\n\t-d\t\tprint the description of all ");
    my_putstr("the annimations and quit.\n\t-h\t\tprint the usage and quit");
    my_putstr("\n\nUSER INTERACTIONS\n\tLEFT_ARROW\tswitch to the ");
    my_putstr("previous animation.\n\tRIGHT_ARROW\tsitch to the next");
    my_putstr(" annimation.\n");
    return (84);
}

int main(int ac, char **av)
{
    int nb;

    if (ac < 2) {
        my_putstr(av[0]);
        my_putstr(": bad arguments: 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (print_help(av[0]));
    nb = my_getnbr(av[1]);
    if (nb <= 0 || nb > ID_MAX) {
        my_putstr(av[0]);
        my_putstr(": bad arguments: the given ID must be between 1 and ");
        my_putnbr(ID_MAX);
        my_putstr("\n");
        return (84);
    }
    srand(time(NULL));
    return (SCREENS[nb - 1].fptr(1920, 1080));
}
