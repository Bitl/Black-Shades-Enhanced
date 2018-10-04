#ifndef SERIALIZE_H
#define SERIALIZE_H

/* these all read big-endian data */

int ReadBool(FILE *fd, int count, bool *b);
int ReadShort(FILE *fd, int count, short *s);
int ReadInt(FILE *fd, int count, int *s);
int ReadFloat(FILE *fd, int count, float *f);
int ReadXYZ(FILE *fd, int count, XYZ *xyz);
int ReadTexturedTriangle(FILE *fd, int count, TexturedTriangle *tt);

#endif
