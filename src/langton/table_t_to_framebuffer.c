/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** transform a table_t to pixels framebuffer
*/

#include <SFML/Graphics.h>
#include "graphics.h"
#include "langton.h"

static void put_square(framebuffer_t *buffer, sfVector2u pos, sfColor color,
        table_t *table)
{
    int pad_x = buffer->w / table->size_x;
    int pad_y = buffer->h / table->size_y;

    for (unsigned int i = pos.y; i < pad_y + pos.y; i++)
        for (unsigned int j = pos.x; j < pad_x + pos.x; j++)
            my_putpixel(buffer, j, i, color);
}

static void put_square_from(table_t *table, int y, int x,
        framebuffer_t *buffer)
{
    sfVector2u pos = {x * buffer->w / table->size_x,
                        y * buffer->h / table->size_y};

    if (table->table[y][x] == 0)
        put_square(buffer, pos, COLOR_TABLE_2, table);
    else
        put_square(buffer, pos, COLOR_TABLE_1, table);
}

void table_t_to_framebuffer(table_t *table, framebuffer_t *buffer)
{
    int pad_x = buffer->w / table->size_x;
    int pad_y = buffer->h / table->size_y;
    sfVector2i pos = {table->ant_x * pad_x + pad_x / 2,
        table->ant_y * pad_y + pad_y / 2};

    for (int i = 0; i < table->size_y; i++) {
        for (int j = 0; j < table->size_x; j++) {
            put_square_from(table, i, j, buffer);
        }
    }
    draw_circle(buffer, pos, pad_y / 2, sfBlack);
}
