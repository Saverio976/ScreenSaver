/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** screen of drawing square recursiv
*/

#include <SFML/Graphics.h>
#include "graphics.h"
#include "myscreensaver.h"
#include "my.h"
#include "square_rec.h"

static void draw_pixel_if_needed(framebuffer_t *buffer, sfVector2u pos,
                                rectangle_t *rect, sfColor color)
{
    if (pos.x < rect->x + PADDING || pos.y < rect->y + PADDING)
        my_putpixel(buffer, pos.x, pos.y, color);
    if (pos.x > rect->x + rect->size_x - PADDING)
        my_putpixel(buffer, pos.x, pos.y, color);
    if (pos.y > rect->y + rect->size_y - PADDING)
        my_putpixel(buffer, pos.x, pos.y, color);
}

static void draw_square(framebuffer_t *buffer, rectangle_t *rect,
                        sfColor color)
{
    sfVector2u pos = {0, 0};

    for (unsigned int y = rect->y; y < rect->y + rect->size_y; y++) {
        for (unsigned int x = rect->x; x < rect->x + rect->size_x; x++) {
            pos.x = x;
            pos.y = y;
            draw_pixel_if_needed(buffer, pos, rect, color);
        }
    }
}

static void draw_square_rec(context_t *ctx, int numbers, sfColor color)
{
    int x_offset = ctx->buffer->w / numbers;
    int y_offset = ctx->buffer->h / numbers;
    rectangle_t rect = {0, 0, x_offset, y_offset};

    for (unsigned int y = 0; y < ctx->buffer->h; y += y_offset) {
        for (unsigned int x = 0; x < ctx->buffer->w; x += x_offset) {
            rect.x = x;
            rect.y = y;
            draw_square(ctx->buffer, &rect, color);
        }
    }
}

static int do_event(context_t *ctx, sfClock *clock, int *numbers)
{
    float seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    int ret_code = master_event(ctx);
    sfColor default_colors[8] = {sfBlue, sfRed, sfCyan, sfYellow, sfMagenta,
                                sfWhite, sfGreen};

    if (seconds > 1.0 / 2.0) {
        draw_square_rec(ctx, *numbers,
                        default_colors[get_random_between(0, 100) % 8]);
        sfClock_restart(clock);
        (*numbers)++;
        if (*numbers > 11) {
            framebuffer_t_clear(ctx->buffer, BG_COLOR);
            *numbers = 1;
        }
    }
    sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                ctx->buffer->w, ctx->buffer->h, 0, 0);
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

int screen_quare_rec(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("square_rec-7", w, h, BG_COLOR);
    sfClock *clock;
    int ret_code;
    int numbers = 1;

    if (!ctx)
        return (84);
    clock = sfClock_create();
    if (!clock)
        return (84);
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, clock, &numbers);
    sfClock_destroy(clock);
    context_t_destroy(ctx);
    return (ret_code);
}
