/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** draw plain circle
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "graphics.h"
#include "circles.h"

static void do_condition_circle(framebuffer_t *buffer, sfVector2u pos,
                                int condition, sfColor color)
{
    if (condition)
        my_putpixel(buffer, pos.x, pos.y, color);
}

void draw_plain_circle(framebuffer_t *buffer, sfVector2i center, int radius,
                    sfColor color)
{
    sfVector2u position = {0, 0};
    int calc = 0;
    int condition = 0;
    int end_y = center.y + radius + 1;
    int end_x = center.x + radius + 1;
    int start_x = center.x - radius;

    for (int y = center.y - radius; y < end_y && y < (int) buffer->h; y++) {
        for (int x = start_x; x < end_x && y < (int) buffer->w; x++) {
            position.x = (unsigned int) x;
            position.y = (unsigned int) y;
            calc = pow(x - center.x, 2) + pow(y - center.y, 2);
            condition = calc <= pow(radius, 2) + radius * 2;
            do_condition_circle(buffer, position, condition, color);
        }
    }
}

void draw_all_circles(context_t *ctx, circles_t **circles, sfClock *clock)
{
    for (int i = 0; circles[i] != NULL; i++)
        draw_plain_circle(ctx->buffer, *(circles[i]->pos), circles[i]->radius,
                circles[i]->color);
    sfClock_restart(clock);
}
