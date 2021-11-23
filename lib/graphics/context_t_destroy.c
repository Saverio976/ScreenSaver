/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** destroy context
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"

void context_t_destroy(context_t *ctx)
{
    if (ctx->win)
        sfRenderWindow_destroy(ctx->win);
    if (ctx->buffer)
        framebuffer_t_destroy(ctx->buffer);
    if (ctx->texture)
        sfTexture_destroy(ctx->texture);
    if (ctx->sprite)
        sfSprite_destroy(ctx->sprite);
    if (ctx)
        free(ctx);
}
