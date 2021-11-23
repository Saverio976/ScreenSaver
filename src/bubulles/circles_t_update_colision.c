/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** update two cirles that collide
*/

#include "bubulles.h"
#include "circles.h"

void circles_t_remove_from_out(circles_t *c, framebuffer_t *buf)
{
    int is_x = 0;
    int is_y = 0;

    while (circles_t_isout_x(c, buf) || circles_t_isout_y(c, buf)) {
        if (is_x == 0 && circles_t_isout_x(c, buf)) {
            c->moove_x *= -1;
            is_x = 1;
        }
        if (is_y == 0 && circles_t_isout_y(c, buf)) {
            c->moove_y *= -1;
            is_y = 1;
        }
        c->pos->x += c->moove_x;
        c->pos->y += c->moove_y;
        if (c->pos->y - c->radius > (int) buf->h || c->pos->y < 0 - c->radius)
            c->pos->y = buf->h / 2;
        if (c->pos->x - c->radius > (int) buf->w || c->pos->x < 0 - c->radius)
            c->pos->x = buf->w / 2;
    }
}

static void mult_minus_all(circles_t *c1, circles_t *c2)
{
    c1->moove_y *= -1;
    c1->moove_x *= -1;
    c2->moove_y *= -1;
    c2->moove_x *= -1;
}

static void collide_same_sens(circles_t *c1, circles_t *c2)
{
    if (c1->pos->y > c2->pos->y)
        c2->moove_x *= -1;
    else
        c1->moove_x *= -1;
    if (c1->pos->x > c2->pos->x)
        c2->moove_y *= -1;
    else
        c1->moove_y *= -1;
}

void circles_t_update_colision(circles_t *c1, circles_t *c2)
{
    if (c1->moove_y * c2->moove_y > 0 && c1->moove_x * c2->moove_x > 0) {
        collide_same_sens(c1, c2);
        return;
    }
    if (c1->moove_y * c2->moove_y > 0) {
        c1->moove_x *= -1;
        c2->moove_x *= -1;
    } else if (c1->moove_x * c2->moove_x > 0) {
        c1->moove_y *= -1;
        c2->moove_y *= -1;
    } else
        mult_minus_all(c1, c2);
    c1->pos->x += c1->moove_x * 2;
    c1->pos->y += c1->moove_y * 2;
    c2->pos->x += c2->moove_x * 2;
    c2->pos->y += c2->moove_y * 2;

}
