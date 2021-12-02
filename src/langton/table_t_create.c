/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** create table langton
*/

#include <stdlib.h>
#include "my.h"
#include "langton.h"

table_t *table_t_create(void)
{
    table_t *table = malloc(sizeof(table_t));

    if (!table)
        return (NULL);
    table->ant_x = NUMBER_COL_CASE / 2;
    table->ant_y = NUMBER_LINE_CASE / 2;
    table->size_y = NUMBER_LINE_CASE;
    table->size_x = NUMBER_COL_CASE;
    table->ant_angle = get_random_between(0, 3);
    table->table = malloc(sizeof(char *) * table->size_y);
    if (!table->table)
        return (NULL);
    for (int i = 0; i < table->size_y; i++) {
        table->table[i] = malloc(sizeof(char) * table->size_x);
        if (!table->table[i])
            return (NULL);
        for (int j = 0; j < table->size_x; j++)
            table->table[i][j] = get_random_between(0, 1);
    }
    return (table);
}
