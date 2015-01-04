#ifndef __CUADRO
#define __CUADRO

#include <GL/glut.h>

#include "poligonoComplejo.h"
#include "igvTextura.h"

class Objeto;

class Cuadro {
	friend class Objeto;

	// poligonos asociados a cuadro
	poligonoComplejo* cuadro1;
	poligonoComplejo* cuadro2;

	igvTextura* pintura1;
	igvTextura* pintura2;
	igvTextura* pintura3;
	igvTextura* pintura4;
protected:
	bool _salaPrincipal;
public:

	Cuadro();
	~Cuadro();

	void visualizar();

};

#endif

