/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** game of life screen (conway)
*/

#include <SFML/Graphics.h>
#include "graphics.h"
#include "gameoflife.h"
#include "myscreensaver.h"

static void update_board(gameoflife_t *board)
{
    for (int i = 0; i < board->size_y; i++)
        for (int j = 0; j < board->size_x; j++)
            gameoflife_t_check_three_next(board, j, i);
}

static int do_event(context_t *ctx, sfClock *clock, gameoflife_t *board)
{
    int ret_code = master_event(ctx);
    float seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds > 1.0 / 2.0) {
        update_board(board);
        gameoflife_t_to_buffer(board, ctx->buffer);
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                    ctx->buffer->w, ctx->buffer->h, 0, 0);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

static int init_all(context_t *ctx, sfClock **clock, gameoflife_t **board)
{
    if (!ctx)
        return (0);
    *clock = sfClock_create();
    if (!(*clock))
        return (0);
    *board = gameoflife_t_create();
    if (!(*board))
        return (0);
    return (1);
}

int screen_gameoflife(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("gameflife-9", w, h, BG_COLOR);
    sfClock *clock;
    gameoflife_t *board;
    int ret_code;

    if (!init_all(ctx, &clock, &board))
        return (84);
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, clock, board);
    context_t_destroy(ctx);
    sfClock_destroy(clock);
    gameoflife_t_destroy(board);
    return (ret_code);
}
