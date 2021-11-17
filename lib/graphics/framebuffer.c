/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** implement a frame buffer
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphics.h"

framebuffer_t *framebuffer_t_create(unsigned int w, unsigned int h)
{
    framebuffer_t *buffer = malloc(sizeof(framebuffer_t));

    if (buffer == NULL)
        return (NULL);
    buffer->w = w;
    buffer->h = h;
    buffer->pixels = malloc(sizeof(sfUint8) * (w * h) * 4);
    if (buffer->pixels == NULL) {
        free(buffer);
        return (NULL);
    }
    return (buffer);
}

void framebuffer_t_destroy(framebuffer_t *buffer)
{
    if (buffer->pixels)
        free(buffer->pixels);
    if (buffer)
        free(buffer);
}

void framebuffer_t_clear(framebuffer_t *buffer, sfColor color)
{
    for (unsigned int y = 0; y < buffer->h; y++)
        for (unsigned int x = 0; x < buffer->w; x++)
            my_putpixel(buffer, x, y, color);
}

void my_putpixel(framebuffer_t *buffer, unsigned int x, unsigned int y,
                    sfColor color)
{
    int index = (y * buffer->w + x) * 4;

    if (x >= buffer->w || y >= buffer->h)
        return;
    buffer->pixels[index++] = color.r;
    buffer->pixels[index++] = color.g;
    buffer->pixels[index++] = color.b;
    buffer->pixels[index++] = color.a;
}
