#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

#include "image.h"

#define VECTOR_MAX_VALUE 255
#define VECTOR_SIZE 5

typedef unsigned char *vector_t;

vector_t get_vector(struct image img, struct point p);
size_t get_vector_value(vector_t v);
double get_vectors_proximity(vector_t massCenter, vector_t v);
vector_t set_vector(unsigned char v0, unsigned char v1, unsigned char v2,
                    unsigned char v3, unsigned char v4);
vector_t set_homogeneous_vector(unsigned char value);
vector_t copy_vector(vector_t v);
void sort_vector(vector_t v);

#endif /* VECTOR_H */
