#ifndef CLASS_H
#define CLASS_H

#include <stddef.h>

#include "vector.h"

struct node {
    struct point point;
    vector_t vector;
};

struct class {
    vector_t massCenter;
    struct node *nodes;
    size_t size;
};

struct class init_class(size_t value);
void add_to_class(struct class *c, struct node n);
struct node copy_node(struct node n);
vector_t get_class_median(struct class class);
void free_class(struct class c);

#endif /* CLASS_H */
