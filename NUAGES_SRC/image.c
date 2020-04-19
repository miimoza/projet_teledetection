#include "image.h"

#include <err.h>

unsigned char get_pixel_value(struct image img, struct point p)
{
    if (p.x < img.width && p.y < img.height)
        return img.mat[(img.height * p.y + p.x) * img.nb_channels];
    errx(127, "Out of Range (x:%ld, y:%ld)\n", p.x, p.y);
}

void set_pixel_value(struct image img, struct point p, struct color c)
{
    if (p.x < img.width && p.y < img.height) {
        struct color *pixel =
            (void *)((char *)img.mat +
                     (img.height * p.y + p.x) * img.nb_channels);
        pixel->r = c.r;
        pixel->g = c.g;
        pixel->b = c.b;
        return;
    }
    errx(127, "Out of Range (x:%ld, y:%ld)\n", p.x, p.y);
}
