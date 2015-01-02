#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bmp.h"


/*************************************************************************/

GLubyte *LoadDIBitmap(const char *filename, /* I - File to load */
                      BITMAPINFO **info)    /* O - Bitmap information */
    {
    FILE             *fp;          /* Open file pointer */
    GLubyte          *bits;        /* Bitmap pixel bits */
    int              bitsize;      /* Size of bitmap */
    int              infosize;     /* Size of header information */
    BITMAPFILEHEADER header;       /* File header */


    /* Try opening the file; use "rb" mode to read this *binary* file. */
		if ((fp = fopen(filename, "rb")) == NULL) {
        printf("LoadDIBitmap: error al abrir el fichero");
		}

    /* Read the file header and any following bitmap information... */
    if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1)
        {
        /* Couldn't read the file header - return NULL... */
    	fclose(fp);
        printf("LoadDIBitmap: no puedo leer la cabecera");
        }

    if (header.bfType != 'MB')	/* Check for BM reversed... */
        {
        /* Not a bitmap file - return NULL... */
        fclose(fp);
        printf("LoadDIBitmap: fichero no es un BMP ");
        }

    //printf("\n offset:%d",header.bfOffBits);

    infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
    if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL)
        {
        /* Couldn't allocate memory for bitmap info - return NULL... */
        fclose(fp);
        printf("LoadDIBitmap: no hay memoria");
        }

    if (fread(*info, 1, infosize, fp) < infosize)
        {
        /* Couldn't read the bitmap header - return NULL... */
        free(*info);
        fclose(fp);
        printf("LoadDIBitmap: no puedo leer la cabecera");
        }

    /* Now that we have all the header info read in, allocate memory for *
     * the bitmap and read *it* in...                                    */
    if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0/* 1 */)
        bitsize = ((*info)->bmiHeader.biWidth *
                   (*info)->bmiHeader.biBitCount + 7) / 8 *
  	           abs((*info)->bmiHeader.biHeight);

    //printf("\n bitsize:%d",bitsize);

    if ((bits = (GLubyte *)malloc(bitsize)) == NULL)
        {
        /* Couldn't allocate memory - return NULL! */
        free(*info);
        fclose(fp);
        printf("LoadDIBitmap: no hay memoria");
        }

    if (fread(bits, 1, bitsize, fp) < bitsize)
        {
        /* Couldn't read bitmap - free memory and return NULL! */
        free(*info);
        free(bits);
        fclose(fp);
        printf("LoadDIBitmap: error al leer el bitmap");
        }

    /* OK, everything went fine - return the allocated bitmap... */
    fclose(fp);
    return (bits);
}

