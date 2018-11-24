#ifndef SUPPORT_H
#define SUPPORT_H

#include <stdio.h>

#ifdef __linux__
#include <unistd.h>
#endif

#ifdef WIN32
#include <al.h>
#include <alut.h>
#else
#include <AL/al.h>
#include <AL/alut.h>
#endif

#ifdef __linux__
#define STUB_FUNCTION fprintf(stderr,"STUB: %s at " __FILE__ ", line %d, thread %d\n",__FUNCTION__,__LINE__,getpid())
#else
#define STUB_FUNCTION fprintf(stderr,"STUB: " __FILE__ ", line %d\n",__LINE__)
#endif

#define fsFromStart SEEK_SET

typedef unsigned char * Str255;
typedef int OSErr;
typedef short int SInt16;

typedef bool Boolean;
#ifdef __linux__
#define TRUE true
#define FALSE false
#endif


typedef struct UnsignedWide
{
	unsigned int lo;
	unsigned int hi;
} UnsignedWide;

typedef struct Point
{
	int h;
	int v;
} Point;

#ifndef OS9
#define SetFPos(fildes, whence, offset) fseek(fildes, offset, whence)
#define FSClose(fildes) fclose(fildes)
#else
#define SetFPos(fildes, whence, offset) lseek(fildes, offset, whence)
#define FSClose(fildes) close(fildes)
#endif

int Random();
void Microseconds(UnsignedWide *microTickCount);
void GetMouse(Point *p);
void GetMouseRel(Point *p);
void GetKeys(unsigned long *keys);
int Button(void);
#ifdef NOOGG
void alutLoadWAVFile_CFH(char *filename, ALenum *format, void **wave, 
	unsigned int *size, ALsizei *freq);
void alutUnloadWAV_CFH(ALenum format, void *wave, unsigned int size, 
	ALsizei freq);
//#define alutLoadWAVFile alutLoadWAVFile_CFH
#define alutUnloadWAV alutUnloadWAV_CFH 
#else
void LoadOGG_CFH(char *filename, ALenum *format, void **wave, 
	unsigned int *size, ALsizei *freq);
void FreeOGG(ALenum format, void *wave, unsigned int size, 
	ALsizei freq);
#endif


FILE *cfh_fopen(const char *filename, const char *mode);

#endif
