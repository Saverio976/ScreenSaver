/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for spwan screen
*/

#ifndef SPAWN_H_
    #define SPAWN_H_

    #include <SFML/Graphics.h>

struct alpha_struct {
    sfVector2i *pos;
    int is_visible;
    sfColor color;
    int frame;
};
typedef struct alpha_struct alpha_t;

void draw_asteroid(framebuffer_t *buffer, alpha_t *alpha, sfColor);
void draw_planet(framebuffer_t *buffer, alpha_t *alpha, sfColor);

#endif
