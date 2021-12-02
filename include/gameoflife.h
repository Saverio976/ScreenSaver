/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for the screen gameoflife
*/

#ifndef GAMEOFLIFE_H_
    #define GAMEOFLIFE_H_

    #include <SFML/Graphics.h>
    #include "graphics.h"

    #define NUMBER_COL_CASE 160
    #define NUMBER_LINE_CASE 90
    #define DEFT_COLOR_1 sfBlack
    #define DEFT_COLOR_2 sfWhite

struct gameoflife_struct {
    char **board;
    int size_y;
    int size_x;
};
typedef struct gameoflife_struct gameoflife_t;

void gameoflife_t_check_three_next(gameoflife_t *, int, int);
gameoflife_t *gameoflife_t_create(void);
void gameoflife_t_destroy(gameoflife_t *);
void gameoflife_t_to_buffer(gameoflife_t *, framebuffer_t *);

#endif
