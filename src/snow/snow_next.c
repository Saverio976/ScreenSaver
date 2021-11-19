/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** other func to reduce lines
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"
#include "snow.h"

static void lines_t_destroy(lines_t **lines)
{
    for (int i = 0; lines[i] != NULL; i++) {
        free(lines[i]->start);
        free(lines[i]->end);
        free(lines[i]);
    }
    free(lines);
}

void destroy_main(context_t *ctx, lines_t **lines, sfClock *clock)
{
    context_t_destroy(ctx);
    lines_t_destroy(lines);
    sfClock_destroy(clock);
}
