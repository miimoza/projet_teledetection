#include "compute.h"

#include <stddef.h>
#include <stdio.h>
#include <time.h>

#include "class.h"
#include "ealloc.h"
#include "image.h"
#include "vector.h"

float get_cloud_proportion(struct image img)
{
    struct class classC = init_class(VECTOR_MAX_VALUE);
    struct class classJ = init_class(VECTOR_MAX_VALUE / 2);

    vector_t massCenterCHold = NULL;
    vector_t massCenterJHold = NULL;

    do {
        classC.size = 0;
        classJ.size = 0;

        efree(massCenterCHold);
        efree(massCenterJHold);
        massCenterCHold = copy_vector(classC.massCenter);
        massCenterJHold = copy_vector(classJ.massCenter);

        for (size_t y = 0; y < img.height; y++) {
            for (size_t x = 0; x < img.width; x++) {
                struct point p = { x, y };
                struct node n = { p, get_vector(img, p),
                                  get_pixel_value(img, p) };

                if (get_vectors_distance(classC.massCenter, n.vector) <=
                    get_vectors_distance(classJ.massCenter, n.vector))
                    add_to_class(&classC, n);
                else
                    add_to_class(&classJ, n);
            }
        }

        vector_t tmpC = NULL;
        vector_t tmpJ = NULL;
        if (classC.size > 0)
            tmpC = set_homogeneous_vector(get_class_median(classC).value);
        if (classJ.size > 0)
            tmpJ = set_homogeneous_vector(get_class_median(classJ).value);
        classC.massCenter = (tmpC) ? tmpC : classC.massCenter;
        classJ.massCenter = (tmpJ) ? tmpJ : classJ.massCenter;

    } while (get_vectors_distance(classC.massCenter, massCenterCHold) >
                 STABILITY_THRESHOLD &&
             get_vectors_distance(classJ.massCenter, massCenterJHold) >
                 STABILITY_THRESHOLD);

    float proportion =
        (float)classC.size / ((float)classC.size + (float)classJ.size);

    for (size_t i = 0; i < classC.size; i++) {
        struct color cloud_color = { .r = 0, .g = 255, .b = 0 };
        set_pixel_value(img, classC.nodes[i].point, cloud_color);
    }

    efree(massCenterCHold);
    efree(massCenterJHold);
    free_class(classC);
    free_class(classJ);

    return proportion;
}

void rgb_to_grayscale(guchar *srcImg, guchar *dstImg, size_t nbPixels)
{
    for (size_t i = 0; i < nbPixels * RGB_NB_CHANNELS; i += RGB_NB_CHANNELS) {
        guchar rgbAverage =
            ((*(srcImg + i) + *(srcImg + i + 1) + *(srcImg + i + 2)) / 3);

        for (size_t channel = 0; channel < RGB_NB_CHANNELS; channel++)
            *(dstImg + i + channel) = rgbAverage;
    }
}

void ComputeImage(guchar *srcImg, guint height, guint width, guchar *dstImg)
{
    clock_t startClock = clock();

    rgb_to_grayscale(srcImg, dstImg, width * height);

    float cloudProportion = get_cloud_proportion(
        (struct image){ dstImg, width, height, RGB_NB_CHANNELS });

    size_t time_elapsed =
        ((clock_t)clock() - startClock) / (CLOCKS_PER_SEC / 1000.0);

    printf("\t--> Cloud Proportion: %f%% (Time Elapsed: %lds%03ldms)\n",
           cloudProportion * 100, time_elapsed / 1000, time_elapsed % 1000);
}
