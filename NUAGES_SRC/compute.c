#include "compute.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "class.h"
#include "image.h"
#include "vector.h"

float get_cloud_proportion(struct image img)
{
    struct class classJ = init_class(VECTOR_MAX_VALUE / 2);
    struct class classC = init_class(VECTOR_MAX_VALUE);

    vector_t massCenterJHold = NULL;
    vector_t massCenterCHold = NULL;
    do {
        if (massCenterJHold)
            free(massCenterJHold);
        if (massCenterCHold)
            free(massCenterCHold);

        massCenterJHold = copy_vector(classJ.massCenter);
        massCenterCHold = copy_vector(classC.massCenter);

        classJ.size = 0;
        classC.size = 0;

        for (size_t y = 0; y < img.height; y++) {
            for (size_t x = 0; x < img.width; x++) {
                struct point p = { x, y };
                struct node n = { p, get_vector(img, p) };

                if (get_vectors_proximity(classJ.massCenter, n.vector) <=
                    get_vectors_proximity(classC.massCenter, n.vector))
                    add_to_class(&classJ, n);
                else
                    add_to_class(&classC, n);
            }
        }

        vector_t tmpJ = get_class_median(classJ);
        vector_t tmpC = get_class_median(classC);

        classJ.massCenter = (tmpJ) ? tmpJ : classJ.massCenter;
        classC.massCenter = (tmpC) ? tmpC : classC.massCenter;
    } while (get_vectors_proximity(classJ.massCenter, massCenterJHold) >=
                 STABILITY_THRESHOLD &&
             get_vectors_proximity(classC.massCenter, massCenterCHold) >=
                 STABILITY_THRESHOLD);

    float proportion =
        (float)classC.size / ((float)classC.size + (float)classJ.size);

    for (size_t i = 0; i < classC.size; i++) {
        struct color cloud_color = { .r = 0, .g = 255, .b = 0 };
        set_pixel_value(img, classC.nodes[i].point, cloud_color);
    }

    free(massCenterJHold);
    free(massCenterCHold);
    free_class(classJ);
    free_class(classC);

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

void ComputeImage(guchar *srcImg, guint width, guint height, guchar *dstImg)
{
    clock_t startClock = clock();

    rgb_to_grayscale(srcImg, dstImg, width * height);

    float cloudProportion = get_cloud_proportion(
        (struct image){ dstImg, width, height, RGB_NB_CHANNELS });

    size_t time_elapsed =
        ((clock_t)clock() - startClock) / (CLOCKS_PER_SEC / 1000.0);

    printf("\t--> Cloud Proportion: %f%% (Time Elpased: %lds%03ldms)\n",
           cloudProportion * 100, time_elapsed / 1000, time_elapsed % 1000);
}
