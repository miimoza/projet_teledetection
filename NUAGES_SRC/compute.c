#include "compute.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "image.h"
#include "vector.h"

float get_cloud_proportion(struct image img)
{
    vector_t v =
        get_vector(img, (struct point){ img.width / 2, img.height / 2 });
    printf("v:%d,%d,%d,%d,%d\n", v[0], v[1], v[2], v[3], v[4]);

    vector_t max = set_homogeneous_vector(VECTOR_MAX_VALUE);
    // 1. choice of the number of classes
    size_t nbClassK = 2;
    // 2. inilization of the mass centers V(0) of the k classes omega(j)
    struct class classJ = { set_homogeneous_vector(0), NULL, 0 };
    struct class classC = { set_homogeneous_vector(VECTOR_MAX_VALUE), NULL, 0 };

    puts("start the loop");

    // 3. at iteration i, the pixels with a radiometric value Vs
    // is a member of class ωj if mj is the nearest mass center from Vs

    vector_t massCenterJHold, massCenterCHold;
    do {
        massCenterJHold = classJ.massCenter;
        massCenterCHold = classC.massCenter;

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

                printf("s:%d,%d,%d,%d,%d\n", v[0], v[1], v[2], v[3], v[4]);
            }
        }
        // 4. when all the pixels are classified,
        // the new mass centers mj(i + 1) are computed
        printf("CLASSJ:%d,%d,%d,%d,%d\n", classJ.massCenter[0],
               classJ.massCenter[1], classJ.massCenter[2], classJ.massCenter[3],
               classJ.massCenter[4]);
        printf("CLASSJH:%d,%d,%d,%d,%d\n", massCenterJHold[0],
               massCenterJHold[1], massCenterJHold[2], massCenterJHold[3],
               massCenterJHold[4]);
        printf("CLASSC:%d,%d,%d,%d,%d\n", classC.massCenter[0],
               classC.massCenter[1], classC.massCenter[2], classC.massCenter[3],
               classC.massCenter[4]);
        printf("CLASSCH:%d,%d,%d,%d,%d\n", massCenterCHold[0],
               massCenterCHold[1], massCenterCHold[2], massCenterCHold[3],
               massCenterCHold[4]);

        classJ.massCenter = get_class_median(classJ);
        classC.massCenter = get_class_median(classC);
    } while (get_vector_proximity(classJ.massCenter, massCenterJHold) >=
                 STABILITY_THRESHOLD &&
             get_vector_proximity(classC.massCenter, massCenterCHold) >=
                 STABILITY_THRESHOLD);

    return (float)classC.size / ((float)classC.size + (float)classJ.size);
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
           cloudProportion * 100);
    printf("le temps de calcul pour traiter cette image: %fms\n",
           (double)(clock() - startClock));
}
