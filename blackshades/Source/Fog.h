#ifndef FOG_H_
#define FOG_H_


/**> HEADER FILES <**/

#ifdef WIN32
#include <windows.h>
#endif

#ifdef OS9 
#include <gl.h>
#else
#include <GL/gl.h>
#endif
#include "Quaternions.h"


class Fog{
	public:
		GLfloat fogColor[4];
		GLint fogMode;
		GLfloat fogDensity;
		GLfloat fogStart;
		GLfloat fogEnd;
		
		void SetFog(float colorR, float colorG, float colorB, float fStart, float fEnd, float fogDensity);
		void TempFog(float colorR, float colorG, float colorB);
		void ResetFog();
};

#endif

