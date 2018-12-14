#ifndef CAMERA_H_
#define CAMERA_H_


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

class Camera
{
	public:
		XYZ position;
		XYZ oldposition;
		XYZ targetoffset;
		
	 	float rotation, rotation2;
	 	float oldrotation, oldrotation2;
	 	float oldoldrotation, oldoldrotation2;
	 	float visrotation,  visrotation2;
		void Apply();
};

#endif

