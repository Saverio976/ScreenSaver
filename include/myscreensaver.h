/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for the src part
*/

#ifndef MYSCREENSAVER_H_
    #define MYSCREENSAVER_H_

    #include <SFML/Graphics.h>
    #include <graphics.h>

struct screen_struct {
    int (*fptr)(unsigned int, unsigned int);
};

int screen_circles(unsigned int, unsigned int);

#endif
