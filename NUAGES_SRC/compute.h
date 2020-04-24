#ifndef COMPUTE_H
#define COMPUTE_H

#include <gtk/gtk.h>

#define STABILITY_THRESHOLD 2
#define LargeurImage 360

void ComputeImage(guchar *pucImaOrig, guint uiNbLine, guint uiNbCol,
                  guchar *pucImaRes);

#endif /* COMPUTE_H */
