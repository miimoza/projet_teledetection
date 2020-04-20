#include "ealloc.h"

#include <err.h>
#include <stdlib.h>

void *emalloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL)
        errx(MEMORY_ERROR, "%s: cannot allocate memory", __func__);
    return p;
}

void efree(void *ptr)
{
    if (ptr == NULL)
        return;
    free(ptr);
}

void *ecalloc(size_t nmemb, size_t size)
{
    void *p = calloc(nmemb, size);
    if (p == NULL)
        errx(MEMORY_ERROR, "%s: cannot allocate memory", __func__);
    return p;
}

void *erealloc(void *ptr, size_t size)
{
    void *p = realloc(ptr, size);
    if (p == NULL)
        errx(MEMORY_ERROR, "%s: cannot allocate memory", __func__);
    return p;
}
