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

static const int ID_MAX = 10;
static const struct screen_struct SCREENS[10] = {
    {&screen_circles},
    {&screen_snow},
    {&screen_spawn},
    {&screen_nico},
    {&screen_bubulles},
    {&screen_bg_fade},
    {&screen_quare_rec},
    {&screen_langton},
    {&screen_gameoflife},
    {&screen_barnsleyfern}
};

static const struct screen_explain EXPLAINS[10] = {
    {&explain_circles},
    {&explain_snow},
    {&explain_spawn},
    {&explain_nico},
    {&explain_bubulles},
    {&explain_bg_fade},
    {&explain_square_rec},
    {&explain_langton},
    {&explain_gameoflife},
    {&explain_barnsleyfern}
};

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
        return (print_h(av[0], ID_MAX));
    if (av[1][0] == '-' && av[1][1] == 'd')
        return (print_d());
    nb = my_getnbr(av[1]);
    if (nb <= 0 || nb > ID_MAX)
        return (print_bad_id(av[0], ID_MAX));
    srand(time(NULL));
    return (loop_until_close(nb));
}
