/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** render a nico dvd like
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "myscreensaver.h"
#include "graphics.h"
#include "bitmap.h"
#include "nico.h"
#include "my.h"

static void update_pos(context_t *ctx, bitmap_t *bmp, image_t *positions)
{
    positions->pos.x += positions->moove.x;
    positions->pos.y += positions->moove.y;
    if (positions->pos.x + bmp->info->width > (int) ctx->buffer->w ||
            positions->pos.x <= 0) {
        positions->moove.x *= -1;
        positions->pos.x += positions->moove.x;
        pixels_fade(bmp->pixels, bmp->info->height, bmp->info->width);
    }
    if (positions->pos.y + bmp->info->height > (int) ctx->buffer->h ||
            positions->pos.y <= 0) {
        positions->moove.y *= -1;
        positions->pos.y += positions->moove.y;
        pixels_fade(bmp->pixels, bmp->info->height, bmp->info->width);
    }
    sfTexture_updateFromPixels(ctx->texture, bmp->pixels, bmp->info->width,
        bmp->info->height, positions->pos.x,
        positions->pos.y);
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
}

static int do_event(context_t *ctx, bitmap_t *bmp, image_t *positions,
    sfClock *clock)
{
    static float seconds;
    int ret_code = master_event(ctx);

    seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    sfRenderWindow_clear(ctx->win, BG_COLOR);
    if (seconds > 1.0 / 64.0) {
        sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                    ctx->buffer->w, ctx->buffer->h, 0, 0);
        update_pos(ctx, bmp, positions);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ret_code);
}

static void destroy_all(context_t *ctx, bitmap_t *bmp, image_t *pos,
    sfClock *clock)
{
    if (ctx)
        context_t_destroy(ctx);
    if (bmp)
        bitmap_t_destroy(bmp);
    if (pos)
        free(pos);
    if (clock)
        sfClock_destroy(clock);
}

static int init_all(bitmap_t **bmp, image_t **pos, unsigned int w,
    unsigned int h)
{
    int i_x = get_random_between(0, 1);
    int i_y = get_random_between(0, 1);

    *bmp = bitmap_t_create(IMAGE_DVD);
    if (!(*bmp))
        return (0);
    *pos = malloc(sizeof(image_t));
    if (!(*pos))
        return (0);
    (*pos)->pos.x = get_random_between(0, w - (*bmp)->info->width);
    (*pos)->pos.y = get_random_between(0, h - (*bmp)->info->height);
    (*pos)->moove.x = (i_x == 1) ? 5 : -5;
    (*pos)->moove.y = (i_y == 1) ? 5 : -5;
    return (1);
}

int screen_nico(unsigned int w, unsigned int h)
{
    context_t *ctx = context_t_init("nico-4", w, h, BG_COLOR);
    bitmap_t *bmp = NULL;
    image_t *positions = NULL;
    sfClock *clock = NULL;
    int ret_code;

    if (!ctx)
        return (84);
    clock = sfClock_create();
    if (!clock)
        return (84);
    if (!init_all(&bmp, &positions, w, h)) {
        destroy_all(ctx, bmp, positions, clock);
        return (84);
    }
    while (sfRenderWindow_isOpen(ctx->win))
        ret_code = do_event(ctx, bmp, positions, clock);
    destroy_all(ctx, bmp, positions, clock);
    return (ret_code);
}
