/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** suite for circles screen
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "graphics.h"
#include "circles.h"

void create_2_clock(sfClock **cl1, sfClock **cl2)
{
    *cl1 = sfClock_create();
    if (!(*cl1))
        return;
    *cl2 = sfClock_create();
    if (!(*cl2)) {
        sfClock_destroy(*cl1);
        return;
    }
}

void destroy_2_clock(sfClock *cl1, sfClock *cl2)
{
    sfClock_destroy(cl1);
    sfClock_destroy(cl2);
}

void re_init_framebuffer(context_t *ctx, circles_t **circles,
                            sfClock *clock_screen, sfClock *clock_update)
{
    framebuffer_t_clear(ctx->buffer, sfBlack);
    update_circles(ctx->buffer, circles, clock_update);
    sfClock_restart(clock_screen);
    sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                ctx->buffer->w, ctx->buffer->h, 0, 0);
}
