#ifndef COMPUTE_H
#define COMPUTE_H

#include <gtk/gtk.h>

#define STABILITY_THRESHOLD 16
#define LargeurImage 360

void ComputeImage(guchar *pucImaOrig, guint uiNbCol, guint uiNbLine,
                  guchar *pucImaRes);

#endif /* COMPUTE_H */
