/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** select the lines screensaver
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"
#include "my.h"
#include "circles.h"

static circles_t **circles_t_create(unsigned int w, unsigned int h)
{
    sfColor default_colors[8] = {sfBlue, sfCyan, sfGreen,
                                sfMagenta, sfRed, sfWhite, sfYellow};
    circles_t **circles = malloc(sizeof(circles_t *) * 4);

    circles[3] = NULL;
    for (int i = 0; i < 3; i++) {
        circles[i] = malloc(sizeof(circles_t));
        circles[i]->pos = malloc(sizeof(sfVector2i));
        circles[i]->pos->x = get_urandom_between(0, w);
        circles[i]->pos->y = get_urandom_between(0, h);
        circles[i]->radius = get_random_between(0, 50);
        circles[i]->moove_x = get_random_between(-50, 100);
        circles[i]->moove_y = get_random_between(-50, 100);
        circles[i]->grow = get_random_between(10, 15);
        circles[i]->color = default_colors[get_random_between(0, 100) % 7];
    }
    return (circles);
}

static void circles_t_destroy(circles_t **circles)
{
    for (int i = 0; circles[i] != NULL; i++) {
        free(circles[i]->pos);
        free(circles[i]);
    }
    free(circles);
}

void update_circles(framebuffer_t *buffer, circles_t **circles,
                            sfClock *clock)
{
    sfColor default_colors[8] = {sfBlue, sfCyan, sfGreen,
                                sfMagenta, sfRed, sfWhite, sfYellow};

    for (int i = 0; circles[i] != NULL; i++) {
        circles[i]->pos->x += circles[i]->moove_x;
        circles[i]->pos->y += circles[i]->moove_y;
        circles[i]->radius += circles[i]->grow;
        if (circles[i]->pos->x <= 0 || circles[i]->pos->x >= (int) buffer->w)
            circles[i]->moove_x *= -1;
        if (circles[i]->pos->y <= 0 || circles[i]->pos->y >= (int) buffer->h)
            circles[i]->moove_y *= -1;
        if (circles[i]->radius > 100 || 10 > circles[i]->radius) {
            circles[i]->grow *= -1;
            circles[i]->color = default_colors[get_random_between(0, 100) % 7];
        }
        draw_circle(buffer, *(circles[i]->pos), circles[i]->radius,
                    circles[i]->color);
    }
    sfClock_restart(clock);
}

static void do_event(context_t *ctx, circles_t **circles,
                        sfClock *clock_screen, sfClock *clock_update)
{
    static sfEvent event;
    static float seconds1;
    static float seconds2;

    while (sfRenderWindow_pollEvent(ctx->win, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(ctx->win);
    seconds1 = sfClock_getElapsedTime(clock_screen).microseconds / 1000000.0;
    seconds2 = sfClock_getElapsedTime(clock_update).microseconds / 1000000.0;
    if (seconds1 > 5.0)
        re_init_framebuffer(ctx, circles, clock_screen, clock_update);
    else if (seconds2 > 1.0 / 20.0) {
        update_circles(ctx->buffer, circles, clock_update);
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                    ctx->buffer->w, ctx->buffer->h, 0, 0);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
}

int screen_circles(unsigned int w, unsigned int h)
{
    sfClock *clock_screen;
    sfClock *clock_update;
    context_t *ctx = context_t_init("circles", w, h);
    circles_t **circles = NULL;

    if (!ctx)
        return (84);
    circles = circles_t_create(w, h);
    if (!circles)
        return (84);
    create_2_clock(&clock_screen, &clock_update);
    if (!clock_screen || !clock_update)
        return (84);
    sfRenderWindow_setFramerateLimit(ctx->win, 30);
    while (sfRenderWindow_isOpen(ctx->win))
        do_event(ctx, circles, clock_screen, clock_update);
    context_t_destroy(ctx);
    circles_t_destroy(circles);
    destroy_2_clock(clock_screen, clock_update);
    return (0);
}
