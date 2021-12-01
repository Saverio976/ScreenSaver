/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** transform a table_t to pixels framebuffer
*/

#include <SFML/Graphics.h>
#include "graphics.h"
#include "langton.h"

static void put_square(framebuffer_t *buffer, sfVector2u pos, sfColor color)
{
    int pad_x = buffer->w / NUMBER_COL_CASE;
    int pad_y = buffer->h / NUMBER_LINE_CASE;

    for (unsigned int i = pos.y; i < pos.y + pad_y; i++)
        for (unsigned int j = pos.x; j < pos.x + pad_x; j++)
            my_putpixel(buffer, j, i, color);
}

static void put_square_color(table_t *table, int y, int x,
        framebuffer_t *buffer)
{
    sfVector2u pos = {x * buffer->w / NUMBER_COL_CASE,
        y * buffer->h / NUMBER_LINE_CASE};

    if (table->table[y][x] == 0)
        put_square(buffer, pos, COLOR_TABLE_1);
    else
        put_square(buffer, pos, COLOR_TABLE_2);
}

void table_t_to_framebuffer(table_t *table, framebuffer_t *buffer)
{
    int pad_x = buffer->w / NUMBER_COL_CASE;
    int pad_y = buffer->h / NUMBER_LINE_CASE;
    sfVector2i pos = {table->ant_x * pad_x + pad_x / 2,
        table->ant_y * pad_y + pad_y / 2};

    for (int i = 0; i < NUMBER_LINE_CASE; i++) {
        for (int j = 0; j < NUMBER_COL_CASE; j++) {
            put_square_color(table, i, j, buffer);
        }
    }
    draw_circle(buffer, pos, pad_y / 2, sfBlack);
}
