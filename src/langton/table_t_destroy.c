/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** destroy table_struct
*/

#include <stdlib.h>
#include "langton.h"

void table_t_destroy(table_t *table)
{
    for (int i = 0; i < NUMBER_LINE_CASE; i++)
        free(table->table[i]);
    free(table->table);
    free(table);
}
