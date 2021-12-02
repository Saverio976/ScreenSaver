/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** check if three cells are alive and update them
*/

#include "gameoflife.h"

static int check_diago(gameoflife_t *board, int x, int y)
{
    int countor = 0;

    if (x > 0 && y > 0 && board->board[y - 1][x - 1] == 0)
        countor++;
    if (x < board->size_x - 1 && y < board->size_y - 1 &&
            board->board[y + 1][x + 1] == 0)
        countor++;
    if (x < board->size_x - 1 && y > 0 && board->board[y - 1][x + 1] == 0)
        countor++;
    if (y < board->size_y - 1 && x > 0 && board->board[y + 1][x - 1] == 0)
        countor++;
    return (countor);
}

static int check_line(gameoflife_t *board, int x, int y)
{
    int countor = 0;

    if (x > 0 && board->board[y][x - 1] == 0)
        countor++;
    if (y > 0 && board->board[y - 1][x] == 0)
        countor++;
    if (y < board->size_y - 1 && board->board[y + 1][x] == 0)
        countor++;
    if (x < board->size_x - 1 && board->board[y][x + 1] == 0)
        countor++;
    return (countor);
}

void gameoflife_t_check_three_next(gameoflife_t *board, int x, int y)
{
    int countor = 0;

    countor += check_diago(board, x, y);
    countor += check_line(board, x, y);
    if (countor == 3 && board->board[y][x] != 0)
        board->board[y][x] = 0;
    else if (board->board[y][x] == 0 && (countor == 2 || countor == 3))
        board->board[y][x] = 0;
    else
        board->board[y][x] = 1;
}
