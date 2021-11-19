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

static const int ID_MAX = 4;
static const struct screen_struct SCREENS[4] = {
    {&screen_circles},
    {&screen_snow},
    {&screen_spawn},
    {&screen_nico}
};
static const struct screen_explain EXPLAINS[4] = {
    {&explain_circles},
    {&explain_snow},
    {&explain_spawn},
    {&explain_nico}
};

static int print_bad_args(char const *exe)
{
    my_putstr(exe);
    my_putstr(": bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
    return (84);
}

static int print_h(char const *exe)
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
    return (0);
}

static int print_bad_id(char const *exe)
{
    my_putstr(exe);
    my_putstr(": bad arguments: the given ID must be between 1 and ");
    my_putnbr(ID_MAX);
    my_putstr("\n");
    return (84);
}

static int print_d(void)
{
    for (int i = 0; i < ID_MAX; i++) {
        my_putnbr(i + 1);
        my_putstr(": ");
        EXPLAINS[i].fptr();
        my_putstr("\n");
    }
    return (0);
}

int loop_until_close(int nb)
{
    int ret_code = SCREENS[nb - 1].fptr(1920, 1080);

    while (ret_code == 2 || ret_code == 3) {
        if (ret_code == 2)
            nb = (nb - 1 == 0) ? ID_MAX : nb - 1;
        if (ret_code == 3)
            nb = (nb + 1 > ID_MAX) ? 1 : nb + 1;
        ret_code = SCREENS[nb - 1].fptr(1920, 1080);
    }
    return (ret_code);
}

int main(int ac, char **av)
{
    int nb;

    if (ac < 2)
        return (print_bad_args(av[0]));
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (print_h(av[0]));
    if (av[1][0] == '-' && av[1][1] == 'd')
        return (print_d());
    nb = my_getnbr(av[1]);
    if (nb <= 0 || nb > ID_MAX)
        return (print_bad_id(av[0]));
    srand(time(NULL));
    return (loop_until_close(nb));
}
