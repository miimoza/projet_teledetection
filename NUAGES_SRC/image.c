#include "image.h"

#include <err.h>

unsigned char get_pixel_value(struct img img, struct point p)
{
    if (p.x < img.width && p.y < img.height)
        return img.mat[(img.height * p.y + p.x) * 3];
    errx(127, "Out of Range (x:%ld, y:%ld)\n", p.x, p.y);
}