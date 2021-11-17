/*
** EPITECH PROJECT, 2021
** MYCREENSAVER
** File description:
** create some basics figure
*/

#include <math.h>
#include "graphics.h"

static void do_condition_line(framebuffer_t *buffer, sfVector2u pos,
                            int condition[2], sfColor color)
{
    unsigned int calc1 = condition[0] * pos.x + condition[1];
    unsigned int calc2 = (pos.y - condition[1]) / condition[0];

    if (pos.y == calc1 - 2 && calc1 + 2 >= pos.x)
        my_putpixel(buffer, pos.x, pos.y, color);
    if (pos.x >= calc2 - 2 && calc2 + 2 >= pos.x)
        my_putpixel(buffer, pos.x, pos.y, color);
}

void draw_line(framebuffer_t *buffer, sfVector2i point_a, sfVector2i point_b,
                sfColor color)
{
    sfVector2u position = {0, 0};
    int condition[2] = {0};

    condition[0] = (point_a.y - point_b.y) / (point_a.x - point_b.x);
    condition[1] = point_a.y - condition[0] * point_a.x;
    for (unsigned int y = 0; y < buffer->h; y++) {
        for (unsigned int x = 0; x < buffer->w; x++) {
            position.x = x;
            position.y = y;
            do_condition_line(buffer, position, condition, color);
        }
    }
}

static void do_condition_circle(framebuffer_t *buffer, sfVector2u pos,
                                int condition, sfColor color)
{
    if (condition)
        my_putpixel(buffer, pos.x, pos.y, color);
}

void draw_circle(framebuffer_t *buffer, sfVector2i center, int radius,
                    sfColor color)
{
    sfVector2u position = {0, 0};
    int calc = 0;
    int condition = 0;
    int end_y = center.y + radius + 1;
    int end_x = center.x + radius + 1;

    for (int y = center.y - radius; y < end_y && y < (int) buffer->h; y++) {
        for (int x = center.x - radius; x < end_x && y < (int) buffer->w; x++) {
            position.x = (unsigned int) x;
            position.y = (unsigned int) y;
            calc = pow(x - center.x, 2) + pow(y - center.y, 2);
            condition = calc <= pow(radius, 2) + radius * 2 &&
                        calc >= pow(radius, 2) - radius * 2;
            do_condition_circle(buffer, position, condition, color);
        }
    }
}
