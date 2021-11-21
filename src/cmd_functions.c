/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** functions to react at some cmdline
*/

#include "my.h"

int print_bad_args(char const *exe)
{
    my_putstr(exe);
    my_putstr(": bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
    return (84);
}

int print_h(char const *exe, int nb_max)
{
    my_putstr("annimation rendering in a CSFML window.\n\n");
    my_putstr("USAGE\n\t");
    my_putstr(exe);
    my_putstr(" [OPTIONS] annimation_id\n\t");
    my_putstr(" annimation_id\tID of the annimation to process");
    my_putstr(" (between 1 and ");
    my_putnbr(nb_max);
    my_putstr(").\n\nOPTIONS\n\t-d\t\tprint the description of all ");
    my_putstr("the annimations and quit.\n\t-h\t\tprint the usage and quit");
    my_putstr("\n\nUSER INTERACTIONS\n\tLEFT_ARROW\tswitch to the ");
    my_putstr("previous animation.\n\tRIGHT_ARROW\tsitch to the next");
    my_putstr(" annimation.\n");
    return (0);
}

int print_bad_id(char const *exe, int nb_max)
{
    my_putstr(exe);
    my_putstr(": bad arguments: the given ID must be between 1 and ");
    my_putnbr(nb_max);
    my_putstr("\n");
    return (84);
}
