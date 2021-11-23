/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** check if a circles_t collide over in a list
*/

#include <math.h>
#include "graphics.h"
#include "circles.h"

int circles_t_iscolide(circles_t **circles, int index)
{
    int is_colide = -1;
    int dist;
    int rad;

    for (int i = 0; is_colide == -1 && circles[i] != NULL; i++) {
        if (i == index)
            continue;
        dist = pow(circles[i]->pos->x - circles[index]->pos->x, 2) +
            pow(circles[i]->pos->y - circles[index]->pos->y, 2);
        rad = pow(circles[i]->radius + circles[index]->radius, 2) +
            circles[index]->radius;
        if (dist <= rad)
            is_colide = i;
    }
    return (is_colide);
}

int circles_t_isout_x(circles_t *circle, framebuffer_t *buffer)
{
    if (circle->pos->x - circle->radius <= 0)
        return (1);
    if (circle->pos->x + circle->radius >= (int) buffer->w)
        return (1);
    return (0);
}

int circles_t_isout_y(circles_t *circle, framebuffer_t *buffer)
{
    if (circle->pos->y - circle->radius <= 0)
        return (1);
    if (circle->pos->y + circle->radius >= (int) buffer->h)
        return (1);
    return (0);
}
