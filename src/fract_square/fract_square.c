/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** put a square and another square on each extremity
*/

#include <SFML/Graphics.h>
#include "graphics.h"
#include "myscreensaver.h"
#include "my.h"

static void put_square(framebuffer_t *buffer, sfVector2u pos, int size,
        sfColor color)
{
    int pad = size / 2;

    for (unsigned int i = pos.y - pad; i < pos.y + pad; i++)
        for (unsigned int j = pos.x - pad; j < pos.x + pad; j++)
            my_putpixel(buffer, j, i, color);
}

static void draw_four_new_square(context_t *ctx, int n)
{
    sfVector2u padding = {ctx->buffer->w / n, ctx->buffer->h / n};
    sfVector2u pos = {padding.x, padding.y};
    sfColor default_colors[7] = {sfBlue, sfCyan, sfGreen,
                                sfMagenta, sfRed, sfWhite, sfYellow};

    put_square(ctx->buffer, padding, padding.y,
            default_colors[get_random_between(0, 6)]);
    pos.y = ctx->buffer->h - padding.y;
    put_square(ctx->buffer, pos, padding.y,
            default_colors[get_random_between(0, 6)]);
    pos.x = ctx->buffer->w - padding.x;
    put_square(ctx->buffer, pos, padding.y,
            default_colors[get_random_between(0, 6)]);
    pos.y = padding.y;
    put_square(ctx->buffer, pos, padding.y,
            default_colors[get_random_between(0, 6)]);
}

static int do_event(context_t *ctx, sfClock *clock, int *n, int *incr)
{
    int ret_code = master_event(ctx);
    float seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds > 1.0 / 15.0) {
        if (*n > 15 || *n <= 2) {
            framebuffer_t_clear(ctx->buffer, BG_COLOR);
            *incr *= -1;
        }
        draw_four_new_square(ctx, *n);
        *n += *incr;
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                    ctx->buffer->w, ctx->buffer->h, 0, 0);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

int screen_fractsquare(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("fractsquare-11", w, h, BG_COLOR);
    sfClock *clock;
    int ret_code;
    int n = 3;
    int incr = 1;

    if (!ctx)
        return (84);
    clock = sfClock_create();
    if (!clock)
        return (84);
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, clock, &n, &incr);
    context_t_destroy(ctx);
    sfClock_destroy(clock);
    return (ret_code);
}
