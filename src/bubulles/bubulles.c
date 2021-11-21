/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** bubulles (like windows) screen
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"
#include "myscreensaver.h"
#include "bubulles.h"
#include "circles.h"
#include "my.h"

static circles_t **circles_t_create(unsigned int w, unsigned int h)
{
    sfColor default_colors[8] = {sfBlue, sfCyan, sfGreen,
                                sfMagenta, sfRed, sfWhite, sfYellow};
    circles_t **circles = malloc(sizeof(circles_t *) * 8);
    int radius;

    circles[7] = NULL;
    for (int i = 0; i < 7; i++) {
        circles[i] = malloc(sizeof(circles_t));
        radius = get_random_between(20, 50) * 5;
        circles[i]->radius = radius / 5;
        circles[i]->pos = malloc(sizeof(sfVector2i));
        circles[i]->pos->x = get_urandom_between(0 + radius, w - radius);
        circles[i]->pos->y = get_urandom_between(0 + radius, h - radius);
        circles[i]->moove_x = get_random_between(-5, 10);
        circles[i]->moove_y = get_random_between(-5, 10);
        circles[i]->grow = get_random_between(10, 15);
        circles[i]->color = default_colors[get_random_between(0, 100) % 7];
    }
    return (circles);
}

static void destroy_bubulles(context_t *ctx, circles_t **circles,
        sfClock *clock, sfClock *clock_moove)
{
    context_t_destroy(ctx);
    for (int i = 0; circles[i] != NULL; i++) {
        free(circles[i]->pos);
        free(circles[i]);
    }
    free(circles);
    sfClock_destroy(clock);
    sfClock_destroy(clock_moove);
}

static void update_circles_bubulles(context_t *ctx, circles_t **circles,
        sfClock *clock)
{
    for (int i = 0; circles[i] != NULL; i++) {
        circles[i]->pos->x += circles[i]->moove_x;
        circles[i]->pos->y += circles[i]->moove_y;
        if (circles_t_isout_x(circles[i], ctx->buffer))
            circles[i]->moove_x *= -1;
        if (circles_t_isout_y(circles[i], ctx->buffer))
            circles[i]->moove_y *= -1;
        if (circles_t_iscolide(circles, i) >= 0) {
            circles[i]->moove_x *= -1;
            circles[i]->moove_y *= -1;
            circles[circles_t_iscolide(circles, i)]->moove_x *= -1;
            circles[circles_t_iscolide(circles, i)]->moove_y *= -1;
        }
    }
    sfClock_restart(clock);
}

static int do_event(context_t *ctx, circles_t **circles, sfClock *clock,
        sfClock *clock_moove)
{
    int ret_code = master_event(ctx);
    float seconds;

    seconds = sfClock_getElapsedTime(clock_moove).microseconds / 1000000.0;
    if (seconds > 1.0 / 160.0)
        update_circles_bubulles(ctx, circles, clock_moove);
    seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    if (seconds > 1.0 / 60.0) {
        framebuffer_t_clear(ctx->buffer, sfBlack);
        draw_all_circles(ctx, circles, clock);
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                ctx->buffer->w, ctx->buffer->h, 0, 0);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

int screen_bubulles(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("MYSCREENSAVER-bubulles-5", w, h, sfBlack);
    int ret_code;
    circles_t **circles;
    sfClock *clock_moove;
    sfClock *clock;

    if (!ctx)
        return (84);
    circles = circles_t_create(w, h);
    if (!circles)
        return (84);
    create_2_clock(&clock, &clock_moove);
    if (!clock || !clock_moove)
        return (84);
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, circles, clock, clock_moove);
    destroy_bubulles(ctx, circles, clock, clock_moove);
    return (ret_code);
}
