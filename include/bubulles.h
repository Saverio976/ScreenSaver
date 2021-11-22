/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for bubulles screen
*/

#ifndef BUBULLES_H_
    #define BUBULLES_H_

    #include "circles.h"
    #include "graphics.h"
    #include <SFML/Graphics.h>

int circles_t_iscolide(circles_t **, int);
int circles_t_isout_x(circles_t *, framebuffer_t *);
int circles_t_isout_y(circles_t *, framebuffer_t *);
void draw_plain_circle(framebuffer_t *, sfVector2i, int, sfColor);
void draw_all_circles(context_t *, circles_t **, sfClock *);
void circles_t_update_colision(circles_t *, circles_t *);
void circles_t_remove_from_out(circles_t *, framebuffer_t *);

#endif
