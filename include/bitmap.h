/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** header of bmp
*/

#ifndef BITMAP_H_
    #define BITMAP_H_

    #include <SFML/Graphics.h>

struct bitmap_file_header {
    short int bmp_signature;
    int file_size;
    int reserved;
    int data_offset;
} __attribute__((packed));
typedef struct bitmap_file_header bmp_file_header_t;

struct bitmap_information_header {
    int size_header;
    int width;
    int height;
    short int planes;
    short int bits_per_pixels;
    int compression;
    int image_size;
    int pixels_per_meter_x;
    int pixels_per_meter_y;
    int colors_used;
    int important_colors;
} __attribute__((packed));
typedef struct bitmap_information_header bmp_info_header_t;

struct bitmap {
    bmp_file_header_t *header;
    bmp_info_header_t *info;
    sfUint8 *pixels;
};
typedef struct bitmap bitmap_t;

bitmap_t *bitmap_t_create(char const *);
void bitmap_t_destroy(bitmap_t *);

#endif
