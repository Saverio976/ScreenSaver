/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** fade the background only
*/

#include <SFML/Graphics.h>
#include "myscreensaver.h"
#include "graphics.h"

static sfColor single_fade_color(sfColor color)
{
    static int padding = 10;
    int red = color.r;
    int blue = color.b;
    int green = color.g;
    printf("rgb : %d %d %d\n", color.r, color.g, color.b);

    if (color.r > 0 && color.b == 0) {
        red -= padding;
        green = (green + padding > 255) ? 255 : green + padding;
    }
    if (color.g > 0 && color.r == 0) {
        green -= padding;
        blue = (blue + padding > 255) ? 255 : blue + padding;
    }
    if (color.b > 0 && color.g == 0) {
        red = (red + padding > 255) ? 255 : red + padding;
        blue -= padding;
    }
    color.r = (red < 0) ? 0 : red;
    color.g = (green < 0) ? 0 : green;
    color.b = (blue < 0) ? 0 : blue;
    return (color);
}


static void fade_all_bg(framebuffer_t *buffer)
{
    sfColor color = {0, 0, 0, 0};
    int index = 0;

    color.r = buffer->pixels[index++];
    color.g = buffer->pixels[index++];
    color.b = buffer->pixels[index++];
    color.a = buffer->pixels[index++];
    color = single_fade_color(color);
    framebuffer_t_clear(buffer, color);
}

static int do_event(context_t *ctx, sfClock *clock)
{
    float seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    int ret_code = master_event(ctx);

    if (seconds > 1.0 / 24) {
        fade_all_bg(ctx->buffer);
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                    ctx->buffer->w, ctx->buffer->h, 0, 0);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

int screen_bg_fade(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("bgfade-6", w, h, sfRed);
    sfClock *clock;
    int ret_code;

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
