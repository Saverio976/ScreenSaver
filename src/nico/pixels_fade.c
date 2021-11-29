/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** fade a pixel array
*/

#include <SFML/Graphics.h>
#include "graphics.h"

static sfColor fade(sfColor color, int counter)
{
    color.r = (color.r + counter) % 255;
    color.g = (color.g + counter) % 255;
    color.b = (color.b + counter) % 255;
    return (color);
}

void pixels_fade(sfUint8 *pixels, int h, int w)
{
    sfColor color = {0, 0, 0, 0};
    int index = 0;
    static int counter = 0;

    counter += 20;
    for (unsigned int y = 0; y < (unsigned int) h; y++) {
        for (unsigned int x = 0; x < (unsigned int) w; x++) {
            color.r = pixels[index++];
            color.g = pixels[index++];
            color.b = pixels[index++];
            color.a = pixels[index++];
            color = fade(color, counter);
            pixels[index - 4] = color.r;
            pixels[index - 3] = color.g;
            pixels[index - 2] = color.b;
            pixels[index - 1] = color.a;
        }
    }
}
