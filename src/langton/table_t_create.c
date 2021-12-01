/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** create table langton
*/

#include <stdlib.h>
#include "my.h"
#include "langton.h"

table_t *table_t_create(unsigned int w, unsigned int h)
{
    table_t *table = malloc(sizeof(table_t));
    int size_y = h / NUMBER_LINE_CASE;
    int size_x = w / NUMBER_COL_CASE;

    if (!table)
        return (NULL);
    table->size_y = size_y;
    table->size_x = size_x;
    table->ant_x = NUMBER_COL_CASE / 2;
    table->ant_y = NUMBER_LINE_CASE / 2;
    table->ant_angle = get_random_between(0, 3);
    table->table = malloc(sizeof(char *) * NUMBER_LINE_CASE);
    if (!table->table)
        return (NULL);
    for (int i = 0; i < NUMBER_LINE_CASE; i++) {
        table->table[i] = malloc(sizeof(char) * NUMBER_COL_CASE);
        if (!table->table[i])
            return (NULL);
        for (int j = 0; j < NUMBER_COL_CASE; j++)
            table->table[i][j] = get_random_between(0, 1);
    }
    return (table);
}
