#ifndef VECTOR_H
#define VECTOR_H

#include "compute.h"
#include "image.h"

#define VECTOR_MAX_VALUE 255
#define VECTOR_SIZE 5

typedef unsigned char *vector_t;

struct class {
    vector_t massCenter;
    vector_t *vectors;
    size_t size;
};

struct node {
    struct point point;
    vector_t vector;
};

vector_t get_vector(struct image img, struct point p);
size_t get_vector_value(vector_t v);
int get_vector_proximity(vector_t mass_center, vector_t v);
vector_t copy_vector(vector_t v);
vector_t set_vector(unsigned char v0, unsigned char v1, unsigned char v2,
                    unsigned char v3, unsigned char v4);
vector_t set_homogeneous_vector(unsigned char value);
void sort_vector(vector_t v);

// class
struct class init_class(size_t value);
void add_to_class(struct class *c, struct node n);
vector_t get_class_median(struct class class);
void free_class(struct class c);

#endif /* VECTOR_H */
