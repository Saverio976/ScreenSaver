/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** screen spawn a
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "myscreensaver.h"
#include "graphics.h"
#include "circles.h"
#include "spawn.h"
#include "my.h"

static alpha_t **alpha_t_create(unsigned int w, unsigned int h)
{
    alpha_t **alphas = malloc(sizeof(alpha_t *) * 10);
    sfColor default_colors[8] = {sfBlue, sfRed, sfCyan, sfYellow, sfMagenta,
                                sfWhite, sfGreen};

    alphas[9] = NULL;
    for (int i = 0; i < 9; i++) {
        alphas[i] = malloc(sizeof(alpha_t));
        alphas[i]->pos = malloc(sizeof(sfVector2i));
        alphas[i]->pos->x = get_random_between(0, w);
        alphas[i]->pos->y = get_random_between(0, h);
        alphas[i]->is_visible = get_random_between(0, 1);
        alphas[i]->color = default_colors[get_random_between(0, 100) % 7];
        alphas[i]->frame = 0;
    }
    return (alphas);
}

static void alpha_t_destroy(alpha_t **alphas)
{
    for (int i = 0; alphas[i] != NULL; i++) {
        free(alphas[i]->pos);
        free(alphas[i]);
    }
    free(alphas);
}

static void update_alphas(context_t *ctx, alpha_t **alphas,
                            sfClock *clock)
{
    for (int i = 0; alphas[i] != NULL; i++) {
        if (alphas[i]->is_visible) {
            alphas[i]->pos->x = get_random_between(0, ctx->buffer->w);
            alphas[i]->pos->y = get_random_between(0, ctx->buffer->h);
            draw_asteroid(ctx->buffer, alphas[i], alphas[i]->color);
            draw_planet(ctx->buffer, alphas[i], alphas[i]->color);
        }
        alphas[i]->is_visible = get_random_between(0, 1);
    }
    sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                ctx->buffer->w, ctx->buffer->h, 0, 0);
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfClock_restart(clock);
}

static int do_event(context_t *ctx, sfClock *clock, alpha_t **alphas,
                        sfClock *clock_refresh)
{
    static float seconds;
    int ret_code = master_event(ctx);

    seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    if (seconds > 1.0 / 2.0)
        update_alphas(ctx, alphas, clock);
    seconds = sfClock_getElapsedTime(clock_refresh).microseconds / 1000000.0;
    if (seconds > 5.0) {
        framebuffer_t_clear(ctx->buffer, BG_COLOR);
        sfClock_restart(clock_refresh);
    }
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

int screen_spawn(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("SCREENSAVER spawn 3", w, h, BG_COLOR);
    sfClock *clock;
    sfClock *clock_refresh;
    alpha_t **alphas;
    int ret_code;

    if (!ctx)
        return (84);
    create_2_clock(&clock, &clock_refresh);
    if (!clock || !clock_refresh)
        return (84);
    alphas = alpha_t_create(w, h);
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, clock, alphas, clock_refresh);
    context_t_destroy(ctx);
    destroy_2_clock(clock, clock_refresh);
    alpha_t_destroy(alphas);
    return (ret_code);
}
