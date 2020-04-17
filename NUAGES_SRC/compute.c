#include "compute.h"

#include <stddef.h>
#include <stdio.h>
#include <time.h>

#include "image.h"
#include "vector.h"

float get_cloud_proportion(struct image img)
{
    float cloudProportion = 0;

    vector_t v =
        get_vector(img, (struct point){ img.width / 2, img.height / 2 });
    printf("v:%d,%d,%d,%d,%d\n", v[0], v[1], v[2], v[3], v[4]);

    vector_t max = set_homogeneous_vector(VECTOR_MAX_VALUE);
    // 1. choice of the number of classes
    size_t nbClass = 2;
    // 2. inilization of the mass centers V(0) of the k classes omega(j)
    vector_t mass_center_j = set_homogeneous_vector(0);
    vector_t mass_center_cloud = set_homogeneous_vector(0);

    puts("start the loop");

    // 3. at step i, if V(i) is the nearest center of vector Vs
    // the pixel s described by Vs is classified in class omega(j)
    for (size_t y = 0; y < img.height; y++) {
        for (size_t x = 0; x < img.width; x++) {
            vector_t i = get_vector(img, (struct point){ x, y });
            printf("s:%d,%d,%d,%d,%d\n", i[0], i[1], i[2], i[3], i[4]);
        }
    }

    return cloudProportion;
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

    size_t nbPixels = width * height;
    rgb_to_grayscale(srcImg, dstImg, nbPixels);

    float cloudProportion = get_cloud_proportion(
        (struct image){ dstImg, width, height, RGB_NB_CHANNELS });

    printf("le pourcentage de nuages trouvé sur l’image: %f%%\n",
           cloudProportion);
    printf("le temps de calcul pour traiter cette image: %fms\n",
           (double)(clock() - startClock));
}
