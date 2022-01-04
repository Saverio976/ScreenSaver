/*
** EPITECH PROJECT, 2022
** LIBGRAPHIQ
** File description:
** fade the buffer
*/

#include "graphics.h"

static void check_fade(framebuffer_t *buffer, int index, int intensity)
{
    if (buffer->pixels[index + 3] > intensity)
        buffer->pixels[index + 3] -= intensity;
    else
        buffer->pixels[index + 3] = 0;
}

void framebuffer_t_fade(framebuffer_t *buffer, int intensity)
{
    int index = 0;

    for (unsigned int y = 0; y < buffer->h; y++) {
        for (unsigned int x = 0; x < buffer->w; x++) {
            check_fade(buffer, index, intensity);
            index += 4;
        }
    }
}
