/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** the barnley fern fratcal screen
*/

#include <SFML/Graphics.h>
#include "graphics.h"
#include "myscreensaver.h"
#include "my.h"

static float get_x_from(int nb, float last_y, float last_x)
{
    if (nb == 1)
        return (0);
    if (2 <= nb && nb <= 86)
        return (0.85 * last_x + 0.04 * last_y);
    if (87 <= nb && nb <= 93)
        return (0.2 * last_x - 0.26 * last_y);
    return (-0.15 * last_x + 0.28 * last_y);
}

static float get_y_from(int nb, float last_y, float last_x)
{
    if (nb == 1)
        return (0.16 * last_y);
    if (2 <= nb && nb <= 86)
        return (-0.04 * last_x + 0.85 * last_y + 1.6);
    if (87 <= nb && nb <= 93)
        return (0.23 * last_x + 0.22 * last_y + 1.6);
    return (0.26 * last_x + 0.24 * last_y + 0.44);
}

static void draw_instance(context_t *ctx)
{
    static float last_y = 0.0;
    static float last_x = 0.0;
    int nb = get_random_between(1, 100);
    float tmp_x = get_x_from(nb, last_y, last_x);
    float tmp_y = get_y_from(nb, last_y, last_x);
    sfColor default_colors[8] = {sfBlue, sfCyan, sfGreen,
                                sfMagenta, sfRed, sfWhite, sfYellow};

    last_y = tmp_y;
    last_x = tmp_x;
    tmp_x *= 100;
    tmp_y *= 100;
    tmp_y = ctx->buffer->h - tmp_y;
    tmp_x = ctx->buffer->w / 2 + tmp_x - 75;
    my_putpixel(ctx->buffer, (int) tmp_x, (int) tmp_y,
            default_colors[get_random_between(0, 8)]);
}

static int do_event(context_t *ctx, sfClock *clock)
{
    int ret_code = master_event(ctx);
    float seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds > 1.0 / 160.0) {
        draw_instance(ctx);
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                    ctx->buffer->w, ctx->buffer->h, 0, 0);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

int screen_barnsleyfern(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("barnsleyfern-10", w, h, BG_COLOR);
    sfClock *clock;
    int ret_code = 0;

    if (!ctx)
        return (84);
    clock = sfClock_create();
    if (!clock)
        return (84);
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, clock);
    context_t_destroy(ctx);
    sfClock_destroy(clock);
    return (ret_code);
}
