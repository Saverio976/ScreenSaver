/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header for lines screen
*/

#ifndef LINES_H_
    #define LINES_H_

    #include <SFML/Graphics.h>

struct lines_struct {
    sfVector2i *start;
    sfVector2i *end;
    sfColor color;
    int moove;
    int grow;
};
typedef struct lines_struct lines_t;

void destroy_main(context_t *, lines_t **, sfClock *);

#endif
