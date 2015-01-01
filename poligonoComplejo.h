#ifndef __POLIGONOCOMPLEJO
#define __POLIGONOCOMPLEJO

#include <GL/glut.h>
#include "bFloat.h"

class poligonoComplejo {
	protected:
		// Atributos
	const unsigned int complejidad;
	GLfloat** puntos;
	GLfloat** normales;
	GLfloat** puntosTex;
	GLubyte* indice;

	public:
		// Constructor y destructor
		poligonoComplejo(bFloat si, bFloat ii, bFloat id, bFloat dirNormal, unsigned int complejidad);
		~poligonoComplejo();

		// Métodos
    void visualizar();
};

#endif
