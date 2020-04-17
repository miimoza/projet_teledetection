#ifndef IMAGE_H
#define IMAGE_H

#include <stddef.h>

#define RGB_NB_CHANNELS 3

struct img
{
    unsigned char *mat;
    size_t width;
    size_t height;
};

struct point
{
    size_t x;
    size_t y;
};

unsigned char get_pixel_value(struct img img, struct point p);

#endif /* IMAGE_H */
