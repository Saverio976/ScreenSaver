/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** the header for langton screen
*/

#ifndef LANGTON_H_
    #define LANGTON_H_

    #include "graphics.h"
    #include <SFML/Graphics.h>

    #define COLOR_TABLE_1 sfCyan
    #define COLOR_TABLE_2 sfRed
    #define NUMBER_COL_CASE 10
    #define NUMBER_LINE_CASE 6

struct table_struct {
    char **table;
    int ant_x;
    int ant_y;
    int size_y;
    int size_x;
    int ant_angle;
};
typedef struct table_struct table_t;

table_t *table_t_create(void);
void table_t_destroy(table_t *);
void table_t_to_framebuffer(table_t *, framebuffer_t *);

#endif
