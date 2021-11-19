/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for the lib graphics part
*/

#ifndef GRAPHICS_H_
    #define GRAPHICS_H_

    #include <SFML/Graphics.h>

// framebuffer struct

struct framebuffer_struct {
    unsigned int w;
    unsigned int h;
    sfUint8 *pixels;
};
typedef struct framebuffer_struct framebuffer_t;

framebuffer_t *framebuffer_t_create(unsigned int, unsigned int);
void framebuffer_t_destroy(framebuffer_t *);
void my_putpixel(framebuffer_t *, unsigned int, unsigned int, sfColor);
void framebuffer_t_clear(framebuffer_t *, sfColor);

// context struct

struct context_struct {
    sfRenderWindow *win;
    sfTexture *texture;
    sfSprite *sprite;
    framebuffer_t *buffer;
};
typedef struct context_struct context_t;

context_t *context_t_init(char const *, unsigned int, unsigned int, sfColor);
void context_t_destroy(context_t *);

// figures
void draw_line(framebuffer_t *, sfVector2i, sfVector2i, sfColor);
void draw_circle(framebuffer_t *, sfVector2i, int, sfColor);
#endif
