#ifndef VECTOR_H
#define VECTOR_H

#define V_MAX_VALUE 255
#define VECTOR_SIZE 5

#include "compute.h"

typedef unsigned char *vector_t;

vector_t get_vector(struct img img, struct point p);
vector_t set_vector(unsigned char value);
void sort_array(vector_t v);

#endif /* VECTOR_H */
