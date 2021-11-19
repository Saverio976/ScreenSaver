/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for the src part
*/

#ifndef MYSCREENSAVER_H_
    #define MYSCREENSAVER_H_

    #include <SFML/Graphics.h>
    #include "graphics.h"

    #define BG_COLOR sfRed

struct screen_struct {
    int (*fptr)(unsigned int, unsigned int);
};
struct screen_explain {
    void (*fptr)(void);
};

int master_event(context_t *);

int screen_circles(unsigned int, unsigned int);
int screen_snow(unsigned int, unsigned int);
int screen_spawn(unsigned int, unsigned int);
int screen_nico(unsigned int, unsigned int);

void explain_circles(void);
void explain_snow(void);
void explain_spawn(void);
void explain_nico(void);

#endif
