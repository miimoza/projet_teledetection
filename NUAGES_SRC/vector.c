#include "vector.h"

#include <stdbool.h>
#include <stddef.h>

vector_t get_vector(struct image img, struct point p)
{
    vector_t v = malloc(sizeof(unsigned char) * VECTOR_SIZE);

    bool b0 = (p.x >= img.width || p.y >= img.height);
    bool b1 = (p.x - 1 >= img.width || p.y >= img.height);
    bool b2 = (p.x + 1 >= img.width || p.y >= img.height);
    bool b3 = (p.x >= img.width || p.y - 1 >= img.height);
    bool b4 = (p.x >= img.width || p.y + 1 >= img.height);

    v[0] = (b0) ? 0 : get_pixel_value(img, p);
    v[1] = (b1) ? 0 : get_pixel_value(img, (struct point){ p.x - 1, p.y });
    v[2] = (b2) ? 0 : get_pixel_value(img, (struct point){ p.x + 1, p.y });
    v[3] = (b3) ? 0 : get_pixel_value(img, (struct point){ p.x, p.y - 1 });
    v[4] = (b4) ? 0 : get_pixel_value(img, (struct point){ p.x, p.y + 1 });

    if (b0 || b1 || b2 || b3 || b4) {
        // Replace out of bound value(s) by the average of the other(s) value(s)

        size_t total = v[0] + v[1] + v[2] + v[3] + v[4];
        unsigned char avg = total / (VECTOR_SIZE - (b0 + b1 + b2 + b3 + b4));

        v[0] = (b0) ? avg : v[0];
        v[1] = (b1) ? avg : v[1];
        v[2] = (b2) ? avg : v[2];
        v[3] = (b3) ? avg : v[3];
        v[4] = (b4) ? avg : v[4];
    }

    sort_array(v);

    return v;
}

vector_t set_vector(unsigned char value)
{
    vector_t v = malloc(sizeof(unsigned char) * VECTOR_SIZE);

    v[0] = value;
    v[1] = value;
    v[2] = value;
    v[3] = value;
    v[4] = value;

    return v;
}

void sort_array(vector_t v)
{
    size_t size = VECTOR_SIZE;

    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (v[j] <= v[j + 1]) {
                unsigned char tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}
