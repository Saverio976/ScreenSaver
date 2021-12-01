/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** the langton screen
*/

#include <SFML/Graphics.h>
#include "graphics.h"
#include "myscreensaver.h"
#include "langton.h"

static void update_angle_ant(table_t *table)
{
    switch (table->ant_angle) {
        case 0:
            table->ant_y -= 1;
            break;
        case 1:
            table->ant_x += 1;
            break;
        case 2:
            table->ant_y += 1;
            break;
        case 3:
            table->ant_x -= 1;
            break;
        default:
            break;
    }
}

static void update_ant(table_t *table, framebuffer_t *buffer)
{
    if (table->table[table->ant_y][table->ant_x] == 0)
        table->table[table->ant_y][table->ant_x] = 1;
    else
        table->table[table->ant_y][table->ant_x] = 0;
    if (table->table[table->ant_y][table->ant_x] == 0)
        table->ant_angle = (table->ant_angle + 1) % 4;
    else
        table->ant_angle = (table->ant_angle + 3) % 4;
    update_angle_ant(table);
    table->ant_x = table->ant_x % (NUMBER_COL_CASE);
    if (table->ant_x < 0)
        table->ant_x = NUMBER_COL_CASE - 1;
    table->ant_y = table->ant_y % (NUMBER_LINE_CASE);
    if (table->ant_y < 0)
        table->ant_y = NUMBER_LINE_CASE - 1;
    table_t_to_framebuffer(table, buffer);
}

static int do_event(context_t *ctx, sfClock *clock, table_t *table)
{
    int ret_code = master_event(ctx);
    float seconds = sfClock_getElapsedTime(clock).microseconds / 100000.0;

    if (seconds > 1.0 / 25.0) {
        update_ant(table, ctx->buffer);
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                ctx->buffer->w, ctx->buffer->h, 0, 0);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

static int init_all(context_t *ctx, sfClock **clock, table_t **table)
{
    if (!ctx)
        return (0);
    *clock = sfClock_create();
    if (!ctx)
        return (0);
    *table = table_t_create();
    if (!table)
        return (0);
    return (1);
}

int screen_langton(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("langton-8", w, h, BG_COLOR);
    sfClock *clock;
    table_t *table;
    int ret_code;

    if (init_all(ctx, &clock, &table) == 0)
        return (84);
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, clock, table);
    context_t_destroy(ctx);
    sfClock_destroy(clock);
    table_t_destroy(table);
    return (ret_code);
}
