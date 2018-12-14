#ifdef __linux__
#include <unistd.h>
#endif

#include "Models.h"
#include "Quaternions.h"
#include "Serialize.h"

/* these all read big-endian data */

// WARNING, MASSIVELY SUBOPTIMAL.

int ReadBool(FILE *fd, int count, bool *b)
{
	while (count--) {
		unsigned char buf[1];
		
//		if (read(fd, buf, 1) != 1) {
		if (fread(buf, 1, 1, fd) != 1) {
			STUB_FUNCTION;
		}
		
		*b = (buf[0] != 0) ? true : false;
		
		b++;
	}
	
	return 1;
}

int ReadShort(FILE *fd, int count, short *s)
{
	while (count--) {
		unsigned char buf[2];
		
		//if (read(fd, buf, 2) != 2) {
		if (fread(buf, 2, 1, fd) != 1) {
			STUB_FUNCTION;
		}
		
		*s = (short)((buf[0] << 8) | buf[1]);
		
		s++;
	}
	
	return 1;
}

int ReadInt(FILE *fd, int count, int *s)
{
	while (count--) {
		unsigned char buf[4];
		
		//if (read(fd, buf, 4) != 4) {
		if (fread(buf, 4, 1, fd) != 1) {
			STUB_FUNCTION;
		}
		
		*s = (int)((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3]);
		
		s++;
	}
	
	return 1;
}

union intfloat {
	int i;
	float f;
} intfloat;

int ReadFloat(FILE *fd, int count, float *f)
{
	union intfloat infl;
	
	while (count--) {
		ReadInt(fd, 1, &(infl.i));
		
		*f = infl.f;
		
		f++;
	}
	
	return 1;
}

int ReadXYZ(FILE *fd, int count, XYZ *xyz)
{
	while (count--) {
		ReadFloat(fd, 1, &(xyz->x));
		ReadFloat(fd, 1, &(xyz->y));
		ReadFloat(fd, 1, &(xyz->z));
		
		xyz++;
	}
	
	return 1;
}

int ReadTexturedTriangle(FILE *fd, int count, TexturedTriangle *tt)
{
	while (count--) {
		short pad;
		ReadShort(fd, 3, tt->vertex);
		ReadShort(fd, 1, &pad); /* crud */
		ReadFloat(fd, 1, &(tt->r));
		ReadFloat(fd, 1, &(tt->g));
		ReadFloat(fd, 1, &(tt->b));
		
		tt++;
	}
	
	return count;
}
