/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** create a board gameoflife_t struct
*/

#include <stdlib.h>
#include "gameoflife.h"
#include "my.h"

gameoflife_t *gameoflife_t_create(void)
{
    gameoflife_t *board = malloc(sizeof(gameoflife_t));

    if (!board)
        return (NULL);
    board->size_y = NUMBER_LINE_CASE;
    board->size_x = NUMBER_COL_CASE;
    board->board = malloc(sizeof(char *) * board->size_y);
    if (!board->board)
        return (NULL);
    for (int i = 0; i < board->size_y; i++) {
        board->board[i] = malloc(sizeof(char) * board->size_x);
        if (!board->board[i])
            return (NULL);
        for (int j = 0; j < board->size_x; j++)
            board->board[i][j] = get_random_between(0, 10);
    }
    return (board);
}
