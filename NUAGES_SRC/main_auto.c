#include <dirent.h>
#include <gtk/gtk.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "compute.h"

static void compute_image(char *path)
{
    GError *error;
    GdkPixbuf *pGdkPixbufImaOrig = gdk_pixbuf_new_from_file(path, &error);
    GdkPixbuf *pGdkPixbufImaRes = gdk_pixbuf_copy(pGdkPixbufImaOrig);

    guint width = gdk_pixbuf_get_width(pGdkPixbufImaOrig);
    guint height = gdk_pixbuf_get_height(pGdkPixbufImaOrig);

    guchar *srcImg = gdk_pixbuf_get_pixels(pGdkPixbufImaOrig);
    guchar *dstImg = gdk_pixbuf_get_pixels(pGdkPixbufImaRes);

    ComputeImage(srcImg, height, width, dstImg);
}

int main(void)
{
    // Mount Fuji
    const char *dirname = "IMAGES";
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        dirname = "../IMAGES";
        dir = opendir(dirname);
        if (dir == NULL) {
            dirname = "../../IMAGES";
            dir = opendir(dirname);
            if (dir == NULL) {
                printf("Could not open directory\n"); /* Sommet */
                return 0;
            }
        }
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !!!strcmp(entry->d_name, ".."))
            continue;
        char buf[PATH_MAX + 1] = "";
        char path[PATH_MAX + 1] = "";
        strcat(buf, dirname);
        strcat(buf, "/");
        strcat(buf, entry->d_name);
        realpath(buf, path);

        printf("Estimating Cloud Cover of Optical Satellite Image %s:\n",
               entry->d_name);
        compute_image(path);
    }

    closedir(dir);
    return 0;
}
