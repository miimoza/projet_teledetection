#include "class.h"

#include "vector.h"

struct class init_class(size_t value)
{
    return (struct class){ set_homogeneous_vector(value), NULL, 0 };
}

void add_to_class(struct class *c, struct node n)
{
    c->nodes = realloc(c->nodes, ++c->size * sizeof(struct node));
    c->nodes[c->size - 1] = n;
}

struct node copy_node(struct node n)
{
    return (struct node){ n.point, copy_vector(n.vector) };
}

static int compare_nodes(const void *n0, const void *n1)
{
    vector_t v0 = ((struct node *)n0)->vector;
    vector_t v1 = ((struct node *)n1)->vector;
    return get_vector_value(v0) - get_vector_value(v1);
}

vector_t get_class_median(struct class class)
{
    if (class.size == 0)
        return NULL;

    qsort(class.nodes, class.size, sizeof(struct node), compare_nodes);
    return copy_node(class.nodes[class.size / 2]).vector;
}

void free_class(struct class c)
{
    for (size_t i = 0; i < c.size; i++)
        free(c.nodes[i].vector);
    if (c.size > 0)
        free(c.nodes);
    free(c.massCenter);
}
