#include "compute.h"

#include <gtk/gtk.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

void ComputeImage(guchar *srcImg, guint height, guint width, guchar *dstImg)
{
    puts(__func__);
    clock_t startClock = clock();

    size_t nbPixels = width * height;

    // grayscale
    for (size_t i = 0; i < nbPixels * RGB_NB_CHANNELS; i += RGB_NB_CHANNELS) {
        guchar rgbAverage =
            ((*(srcImg + i) + *(srcImg + i + 1) + *(srcImg + i + 2)) / 3);
        for (size_t channel = 0; channel < RGB_NB_CHANNELS; channel++)
            *(dstImg + i + channel) = rgbAverage;
    }

    float cloudProportion = 0;

#if 0
    vector_t max = { V_MAX_VALUE };
    // 1. choice of the number of classes
    size_t nbClass = 0;
    // 2. inilization of the mass centers V(0) of the k classes omega(j)
    size_t mass_centers = 0;
    for (size_t i = 0; 0; i++) {
        // 3. at step i, if V(i) is the nearest center of vector Vs
        // the pixel s described by Vs is classified in class omega(j)
        vector_t s = { 0 };
    }
#endif

    printf("le pourcentage de nuages trouvé sur l’image: %f%%\n",
           cloudProportion);

    printf("le temps de calcul pour traiter cette image: %fms\n",
           (double)(clock() - startClock));
}
