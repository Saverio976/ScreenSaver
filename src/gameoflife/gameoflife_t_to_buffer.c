/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** transform a board to pixel array from buffer
*/

#include "graphics.h"
#include "gameoflife.h"

static void put_square(framebuffer_t *buffer, sfVector2u pos, sfColor color,
        gameoflife_t *board)
{
    int pad_x = buffer->w / board->size_x;
    int pad_y = buffer->h / board->size_y;

    for (unsigned int i = pos.y; i < pad_y + pos.y; i++)
        for (unsigned int j = pos.x; j < pad_x + pos.x; j++)
            my_putpixel(buffer, j, i, color);
}

static void put_square_from(gameoflife_t *board, int y, int x,
        framebuffer_t *buffer)
{
    sfVector2u pos = {x * buffer->w / board->size_x,
                        y * buffer->h / board->size_y};

    if (board->board[y][x] == 0)
        put_square(buffer, pos, DEFT_COLOR_2, board);
    else
        put_square(buffer, pos, DEFT_COLOR_1, board);
}

void gameoflife_t_to_buffer(gameoflife_t *board, framebuffer_t *buffer)
{
    for (int i = 0; i < board->size_y; i++)
        for (int j = 0; j < board->size_x; j++)
            put_square_from(board, i, j, buffer);
}
