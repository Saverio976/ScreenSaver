/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** get header of bmp
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "bitmap.h"
#include "file.h"

static bmp_file_header_t *get_header(int fd)
{
    int nbyte;
    int size = sizeof(bmp_file_header_t);
    bmp_file_header_t *header = malloc(size);

    if (!header)
        return (NULL);
    nbyte = read(fd, header, size);
    if (size != nbyte) {
        free(header);
        return (NULL);
    }
    return (header);
}

static bmp_info_header_t *get_info(int fd)
{
    int nbyte;
    int size = sizeof(bmp_info_header_t);
    bmp_info_header_t *info = malloc(size);

    if (!info)
        return (NULL);
    nbyte = read(fd, info, size);
    if (size != nbyte) {
        free(info);
        return (NULL);
    }
    return (info);
}

static sfUint8 *get_pixels(int fd, int w, int h, int bpp)
{
    int nbyte;
    int size = w * h * bpp / 8;
    sfUint8 *pixels = malloc(sizeof(sfUint8) * size);

    if (!pixels)
        return (NULL);
    nbyte = read(fd, pixels, size);
    if (size != nbyte) {
        free(pixels);
        return (NULL);
    }
    return (pixels);
}

static void *free_and_return_null(bitmap_t *bmp)
{
    bitmap_t_destroy(bmp);
    return (NULL);
}

bitmap_t *bitmap_t_create(char const *path)
{
    bitmap_t *bmp;
    int fd = open_ronly(path);

    if (fd < 0)
        return (NULL);
    bmp = malloc(sizeof(bitmap_t));
    if (!bmp)
        return (NULL);
    bmp->header = get_header(fd);
    bmp->info = get_info(fd);
    if (!(bmp->header) || !(bmp->info))
        return (free_and_return_null(bmp));
    bmp->pixels = get_pixels(fd, bmp->info->width, bmp->info->height,
                                bmp->info->bits_per_pixels);
    if (!(bmp->pixels))
        return (free_and_return_null(bmp));
    return (bmp);
}
