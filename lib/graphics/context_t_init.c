/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** init window and framebuffer
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"

static int check_malloc_win(context_t *ctx)
{
    if (ctx->win)
        return (1);
    free(ctx);
    return (0);
}

static int check_malloc_framebuffer(context_t *ctx)
{
    if (ctx->buffer)
        return (1);
    sfRenderWindow_destroy(ctx->win);
    free(ctx);
    return (0);
}

static int check_malloc_texture(context_t *ctx)
{
    if (ctx->texture)
        return (1);
    sfRenderWindow_destroy(ctx->win);
    framebuffer_t_destroy(ctx->buffer);
    free(ctx);
    return (0);
}

static int check_malloc_sprite(context_t *ctx)
{
    if (ctx->sprite)
        return (1);
    sfRenderWindow_destroy(ctx->win);
    framebuffer_t_destroy(ctx->buffer);
    sfTexture_destroy(ctx->texture);
    free(ctx);
    return (0);
}

context_t *context_t_init(char const *t, unsigned int w, unsigned int h)
{
    sfVideoMode mode = {w, h, 32};
    context_t *ctx = malloc(sizeof(context_t));

    if (ctx == NULL)
        return (NULL);
    ctx->win = sfRenderWindow_create(mode, t, sfResize | sfClose, NULL);
    if (!check_malloc_win(ctx))
        return (NULL);
    ctx->buffer = framebuffer_t_create(w, h);
    if (!check_malloc_framebuffer(ctx))
        return (NULL);
    ctx->texture = sfTexture_create(w, h);
    if (!check_malloc_texture(ctx))
        return (NULL);
    ctx->sprite = sfSprite_create();
    if (!check_malloc_sprite(ctx))
        return (NULL);
    sfSprite_setTexture(ctx->sprite, ctx->texture, sfTrue);
    return (ctx);
}
