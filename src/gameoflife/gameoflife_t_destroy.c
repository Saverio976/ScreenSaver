/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** free the struct
*/

#include <stdlib.h>
#include "gameoflife.h"

void gameoflife_t_destroy(gameoflife_t *board)
{
    for (int i = 0; i < board->size_y; i++)
        free(board->board[i]);
    free(board->board);
    free(board);
}
