#ifndef TEXT_H_
#define TEXT_H_


/**> HEADER FILES <**/
#ifdef WIN32
#include <windows.h>
#endif

#include "Quaternions.h"
#ifdef OS9 
#include <gl.h>
#include <glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include "Files.h"
#include "Quaternions.h"
#include "TGALoader.h"

class Text{
	public:
		GLuint FontTexture;
		GLuint base;
		
		void LoadFontTexture(char *fileName);
		void BuildFont();
		void glPrint(GLint x, GLint y, char *string, int set, float size, float width, float height);
		
		~Text(){
			glDeleteTextures( 1, (const GLuint *)FontTexture );
		}
};

#endif

