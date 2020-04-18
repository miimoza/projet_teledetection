#include "vector.h"

#include <stdbool.h>
#include <stdlib.h>

#include <stdio.h>

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

    sort_vector(v);

    return v;
}

size_t get_vector_value(vector_t v)
{
    size_t ret = 0;
    for (size_t i = 0; i < VECTOR_SIZE; i++) {
        ret += v[i];
    }
    return ret;
}

int get_vector_proximity(vector_t mass_center, vector_t v)
{
    int ret = get_vector_value(mass_center) - get_vector_value(v);
    return (ret > 0) ? ret : -ret;
}

static int compare_vectors(const void *v0, const void *v1)
{
    return get_vector_value(*(vector_t *)v0) -
           get_vector_value(*(vector_t *)v1);
}

vector_t get_class_median(struct class class)
{
    qsort(class.vectors, class.size, sizeof(vector_t), compare_vectors);

    return copy_vector(class.vectors[class.size / 2]);
}

vector_t copy_vector(vector_t v)
{
    return set_vector(v[0], v[1], v[2], v[3], v[4]);
}

vector_t set_vector(unsigned char v0, unsigned char v1, unsigned char v2,
                    unsigned char v3, unsigned char v4)
{
    vector_t v = malloc(sizeof(unsigned char) * VECTOR_SIZE);

    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
    v[3] = v3;
    v[4] = v4;

    return v;
}

vector_t set_homogeneous_vector(unsigned char value)
{
    vector_t v = malloc(sizeof(unsigned char) * VECTOR_SIZE);

    for (size_t i = 0; i < VECTOR_SIZE; i++)
        v[i] = value;

    return v;
}

static int compare_uchar(const void *uc0, const void *uc1)
{
    return (*(unsigned char *)uc1) - (*(unsigned char *)uc0);
}

void sort_vector(vector_t v)
{
    qsort(v, VECTOR_SIZE, sizeof(unsigned char), compare_uchar);
}

void free_class(struct class c)
{
    for (size_t i = 0; i < c.size; i++)
        free(c.vectors[i]);
    free(c.vectors);
    free(c.massCenter);
}
