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

// create a moutarde color :
// sfColor_fromRGB(232, 185, 18)
// default color :
// sfBlack, sfRed, sfBlue, sfCyan, sfMagenta, sfYellow, sfGreen sfWhite

    #define BG_COLOR sfBlack

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
int screen_bubulles(unsigned int, unsigned int);
int screen_bg_fade(unsigned int, unsigned int);
int screen_quare_rec(unsigned int, unsigned int);
int screen_langton(unsigned int, unsigned int);
int screen_gameoflife(unsigned int, unsigned int);
int screen_barnsleyfern(unsigned int, unsigned int);
int screen_fractsquare(unsigned int, unsigned int);

void explain_circles(void);
void explain_snow(void);
void explain_spawn(void);
void explain_nico(void);
void explain_bubulles(void);
void explain_bg_fade(void);
void explain_square_rec(void);
void explain_langton(void);
void explain_gameoflife(void);
void explain_barnsleyfern(void);
void explain_fractsquare(void);

int print_bad_args(char const *, char const *);
int print_h(char const *, int);
int print_bad_id(char const *, int);

#endif
