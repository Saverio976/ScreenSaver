/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** select the snow screensaver
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"
#include "snow.h"
#include "my.h"

static lines_t **lines_t_create(unsigned int w, unsigned int h)
{
    sfColor default_colors[8] = {sfBlue, sfCyan, sfGreen, sfMagenta, sfRed,
                                sfWhite, sfYellow};
    lines_t **lines = malloc(sizeof(lines_t *) * 30);

    lines[29] = NULL;
    for (int i = 0; i < 29; i++) {
        lines[i] = malloc(sizeof(lines_t));
        lines[i]->start = malloc(sizeof(sfVector2u));
        lines[i]->start->x = get_random_between(0, w);
        lines[i]->start->y = get_random_between(0, h);
        lines[i]->end = malloc(sizeof(sfVector2u));
        lines[i]->end->x = lines[i]->start->x + 10;
        lines[i]->end->y = lines[i]->start->y + 10;
        lines[i]->color = default_colors[get_random_between(0, 100) % 7];
        lines[i]->moove = get_random_between(20, 50);
    }
    return (lines);
}

static void lines_t_destroy(lines_t **lines)
{
    for (int i = 0; lines[i] != NULL; i++) {
        free(lines[i]->start);
        free(lines[i]->end);
        free(lines[i]);
    }
    free(lines);
}

void update_lines(framebuffer_t *buffer, lines_t **lines, sfClock *clock_frame)
{
    for (int i = 0; lines[i] != NULL; i++) {
        lines[i]->end->y += lines[i]->moove;
        lines[i]->start->y += lines[i]->moove;
        if (lines[i]->end->y > (int) buffer->h || lines[i]->start->y <= 0 ) {
            lines[i]->start->y = 0;
            lines[i]->end->y = 10;
        }
        draw_line(buffer, *(lines[i]->start), *(lines[i]->end),
                    lines[i]->color);
    }
    sfClock_restart(clock_frame);
}

static void do_event(context_t *ctx, lines_t **lines, sfClock *clock_frame)
{
    static sfEvent event;
    static float seconds;

    while (sfRenderWindow_pollEvent(ctx->win, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(ctx->win);
    seconds = sfClock_getElapsedTime(clock_frame).microseconds / 1000000.0;
    if (seconds > 1.0 / 20.0) {
        framebuffer_t_clear(ctx->buffer, sfBlack);
        update_lines(ctx->buffer, lines, clock_frame);
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                    ctx->buffer->w, ctx->buffer->h, 0, 0);
        sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    }
    sfRenderWindow_display(ctx->win);
}

int screen_snow(unsigned int w, unsigned int h)
{
    sfClock *clock_frame;
    context_t *ctx = context_t_init("MYSCREENSAVER - snow - 2", w, h);
    lines_t **lines;

    if (!ctx)
        return (84);
    clock_frame = sfClock_create();
    if (!clock_frame)
        return (84);
    lines = lines_t_create(w, h);
    if (!lines)
        return (84);
    sfRenderWindow_setFramerateLimit(ctx->win, 30);
    while (sfRenderWindow_isOpen(ctx->win))
        do_event(ctx, lines, clock_frame);
    context_t_destroy(ctx);
    lines_t_destroy(lines);
    sfClock_destroy(clock_frame);
    return (0);
}
