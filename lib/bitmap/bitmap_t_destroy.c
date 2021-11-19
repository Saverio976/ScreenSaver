/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** destroy bmp struct
*/

#include <stdlib.h>
#include "bitmap.h"

void bitmap_t_destroy(bitmap_t *bmp)
{
    if (bmp->header)
        free(bmp->header);
    if (bmp->info)
        free(bmp->info);
    if (bmp)
        free(bmp);
}
