#ifdef OS9 
#pragma once
#endif

#ifndef	TGA_LOADER_H_
#define	TGA_LOADER_H_


/**> HEADER FILES <**/
#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef OS9 
#include "gl.h"
#else
#include <GL/gl.h>
#endif

/**> DATA STRUCTURES <**/
typedef struct TGAImageRec
{
	GLubyte	*data;		// Image Data (Up To 32 Bits)
	GLuint	bpp;		// Image Color Depth In Bits Per Pixel.
	GLuint	sizeX;
	GLuint	sizeY;
}	TGAImageRec;



/**> FUNCTION PROTOTYPES <**/
TGAImageRec*	LoadTGA( char *filename );


#endif
