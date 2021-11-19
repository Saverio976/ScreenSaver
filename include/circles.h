/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for the lines part of screensaver
*/

#ifndef CIRCLES_H_
    #define CIRCLES_H_

    #include <SFML/Graphics.h>
    #include "graphics.h"

struct circles_struct {
    sfVector2i *pos;
    sfColor color;
    int grow;
    int radius;
    int moove_x;
    int moove_y;
};
typedef struct circles_struct circles_t;

void destroy_circles(context_t *, circles_t **, sfClock *, sfClock *);
void draw_circles(framebuffer_t *, circles_t **);
void create_2_clock(sfClock **, sfClock **);
void destroy_2_clock(sfClock *, sfClock *);
void update_circles(framebuffer_t *, circles_t **, sfClock *);
void re_init_framebuffer(context_t *, circles_t **,sfClock *, sfClock *);

#endif
