/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** master arrow event in csfml and close event
*/

#include <SFML/Graphics.h>
#include "graphics.h"

static int master_sfevtkeypressed(sfEvent *event)
{
    static sfKeyCode last = sfKeyUnknown;
    int ret_code = 1;

    if (event->key.code == sfKeyLeft)
        ret_code = 2;
    if (event->key.code == sfKeyRight)
        ret_code = 3;
    if (event->key.code == sfKeyEscape && last == sfKeyEscape)
        ret_code = 0;
    last = event->key.code;
    return (ret_code);
}

int master_event(context_t *ctx)
{
    sfEvent event;
    int ret_code = 1;

    while (ret_code == 1 && sfRenderWindow_pollEvent(ctx->win, &event)) {
        if (event.type == sfEvtClosed)
            ret_code = 0;
        if (event.type == sfEvtKeyPressed)
            ret_code = master_sfevtkeypressed(&event);
    }
    if (ret_code != 1)
        sfRenderWindow_close(ctx->win);
    return (ret_code);
}
