/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** functions to react at some cmdline
*/

#include "my.h"

int print_bad_args(char const *exe, char const *str)
{
    my_putstr(exe);
    my_putstr(": bad arguments: ");
    my_putstr(str);
    my_putstr("\nretry with ");
    my_putstr(exe);
    my_putstr(" -h\n");
    return (84);
}

int print_h(char const *exe, int nb_max)
{
    my_putstr("annimation rendering in a CSFML window.\n\nUSAGE\n\t");
    my_putstr(exe);
    my_putstr(" [OPTIONS] annimation_id\n\tannimation_id\tID of the "
        "annimation to process (between 1 and ");
    my_putnbr(nb_max);
    my_putstr(").\n\nOPTIONS\n\t-d\t\tprint the description of all "
        "the annimations and quit.\n\t-h\t\tprint the usage and quit\n\n"
        "USER INTERACTIONS\n\tLEFT_ARROW\tswitch to the previous annimation\n"
        "\tRIGHT_ARROW\tswitch to the next annimation.\n\tEscape+Esacape\tquit"
        " the window\n\nCONFIG\n\tbackground color\tupdate the color in"
        "include/myscreensaver.h and update the macro BG_COLOR\n\tsize of"
        "cells for the langton screen\tupdate the macro NUMBER_COL_CASE and "
        "NUMBER_LINE_CASE in include/langton.h\n\tfor more confi, see the "
        "README.md\n");
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
