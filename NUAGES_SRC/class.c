#include "class.h"

#include <stdlib.h>

#include "ealloc.h"

struct class init_class(size_t value)
{
    return (struct class){ set_homogeneous_vector(value), NULL, 0 };
}

void add_to_class(struct class *c, struct node n)
{
    c->nodes = erealloc(c->nodes, ++c->size * sizeof(struct node));
    c->nodes[c->size - 1] = n;
}

struct node copy_node(struct node n)
{
    return (struct node){ n.point, copy_vector(n.vector), n.value };
}

static int compare_nodes(const void *n0, const void *n1)
{
    unsigned char v0 = ((struct node *)n0)->value;
    unsigned char v1 = ((struct node *)n1)->value;
    return v0 - v1;
}

struct node get_class_median(struct class class)
{
    if (class.size == 0)
        return (struct node){ (struct point){ 0, 0 }, 0, 0 };

    qsort(class.nodes, class.size, sizeof(struct node), compare_nodes);
    return copy_node(class.nodes[class.size / 2]);
}

void free_class(struct class c)
{
    for (size_t i = 0; i < c.size; i++)
        efree(c.nodes[i].vector);
    if (c.size > 0)
        efree(c.nodes);
    efree(c.massCenter);
}
