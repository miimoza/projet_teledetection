#ifndef IMAGE_H
#define IMAGE_H

#include <stddef.h>

#define RGB_NB_CHANNELS 3

struct image {
    unsigned char *mat;
    size_t width;
    size_t height;
    size_t nb_channels;
};

struct point {
    size_t x;
    size_t y;
};

unsigned char get_pixel_value(struct image img, struct point p);

#endif /* IMAGE_H */
