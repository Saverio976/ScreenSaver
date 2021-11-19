/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** spawn some A
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "graphics.h"
#include "spawn.h"

void draw_asteroid(framebuffer_t *buffer, alpha_t *alpha, sfColor color)
{
    sfVector2i pos1 = {alpha->pos->x + 15, alpha->pos->y + 45};
    sfVector2i pos2 = {alpha->pos->x - 15, alpha->pos->y - 45};

    draw_line(buffer, pos1, pos2, color);
}

void draw_planet(framebuffer_t *buffer, alpha_t *alpha, sfColor color)
{
    draw_circle(buffer, *(alpha->pos), 50, color);
}
