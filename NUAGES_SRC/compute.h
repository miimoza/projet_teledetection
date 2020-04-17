#ifndef COMPUTE_H
#define COMPUTE_H

#include <gtk/gtk.h>

#define RGB_NB_CHANNELS 3
#define V_MAX_VALUE 255
#define LargeurImage 360

typedef guchar vector_t[5];

void ComputeImage(guchar *pucImaOrig, guint uiNbCol, guint uiNbLine,
                  guchar *pucImaRes);

#endif /* COMPUTE_H */
