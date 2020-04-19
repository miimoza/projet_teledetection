#include "compute.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "image.h"
#include "vector.h"

float get_cloud_proportion(struct image img)
{
    struct class classJ = { set_homogeneous_vector(0), NULL, 0 };
    struct class classC = { set_homogeneous_vector(VECTOR_MAX_VALUE), NULL, 0 };

    vector_t massCenterJHold = set_homogeneous_vector(0);
    vector_t massCenterCHold = set_homogeneous_vector(0);
    do {
        free(massCenterJHold);
        free(massCenterCHold);
        massCenterJHold = copy_vector(classJ.massCenter);
        massCenterCHold = copy_vector(classC.massCenter);

        classJ.size = 0;
        classC.size = 0;

        for (size_t y = 0; y < img.height; y++) {
            for (size_t x = 0; x < img.width; x++) {
                struct point p = { x, y };
                vector_t v = get_vector(img, p);

                if (get_vector_proximity(classJ.massCenter, v) <=
                    get_vector_proximity(classC.massCenter, v)) {
                    classJ.vectors = realloc(classJ.vectors,
                                             ++classJ.size * sizeof(vector_t));
                    classJ.vectors[classJ.size - 1] = v;
                } else {
                    classC.vectors = realloc(classC.vectors,
                                             ++classC.size * sizeof(vector_t));
                    classC.vectors[classC.size - 1] = v;
                }
            }
        }

        classJ.massCenter = get_class_median(classJ);
        classC.massCenter = get_class_median(classC);
    } while (get_vector_proximity(classJ.massCenter, massCenterJHold) >=
                 STABILITY_THRESHOLD &&
             get_vector_proximity(classC.massCenter, massCenterCHold) >=
                 STABILITY_THRESHOLD);

    float proportion =
        (float)classC.size / ((float)classC.size + (float)classJ.size);

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
