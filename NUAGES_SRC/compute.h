#ifndef COMPUTE_H
#define COMPUTE_H

#include <gtk/gtk.h>

#define LargeurImage 360

void ComputeImage(guchar *pucImaOrig, guint uiNbCol, guint uiNbLine,
                  guchar *pucImaRes);

#endif /* COMPUTE_H */
