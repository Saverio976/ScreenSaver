/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** init window and framebuffer
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"

static int create_malloc_win(context_t *ctx, sfVideoMode mode, char const *t)
{
    ctx->win = sfRenderWindow_create(mode, t, sfResize | sfClose, NULL);
    if (ctx->win)
        return (1);
    free(ctx);
    return (0);
}

static int create_malloc_framebuffer(context_t *ctx, unsigned int w,
        unsigned int h)
{
    ctx->buffer = framebuffer_t_create(w, h);
    if (ctx->buffer)
        return (1);
    sfRenderWindow_destroy(ctx->win);
    free(ctx);
    return (0);
}

static int create_malloc_texture(context_t *ctx, unsigned int w,
        unsigned int h)
{
    ctx->texture = sfTexture_create(w, h);
    if (ctx->texture)
        return (1);
    sfRenderWindow_destroy(ctx->win);
    framebuffer_t_destroy(ctx->buffer);
    free(ctx);
    return (0);
}

static int create_malloc_sprite(context_t *ctx)
{
    ctx->sprite = sfSprite_create();
    if (ctx->sprite)
        return (1);
    sfRenderWindow_destroy(ctx->win);
    framebuffer_t_destroy(ctx->buffer);
    sfTexture_destroy(ctx->texture);
    free(ctx);
    return (0);
}

context_t *context_t_init(char const *t, unsigned int w, unsigned int h,
        sfColor color)
{
    sfVideoMode mode = {w, h, 32};
    context_t *ctx = malloc(sizeof(context_t));

    if (ctx == NULL)
        return (NULL);
    if (!create_malloc_win(ctx, mode, t))
        return (NULL);
    if (!create_malloc_framebuffer(ctx, w, h))
        return (NULL);
    if (!create_malloc_texture(ctx, w, h))
        return (NULL);
    if (!create_malloc_sprite(ctx))
        return (NULL);
    framebuffer_t_clear(ctx->buffer, color);
    sfSprite_setTexture(ctx->sprite, ctx->texture, sfTrue);
    sfTexture_updateFromPixels(ctx->texture, ctx->buffer->pixels,
                                ctx->buffer->w, ctx->buffer->h, 0, 0);
    sfRenderWindow_drawSprite(ctx->win, ctx->sprite, NULL);
    sfRenderWindow_display(ctx->win);
    return (ctx);
}
