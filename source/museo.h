#ifndef __MUSEO
#define __MUSEO

#include <GL/glut.h>
#include "nombres.h"
#include "poligonoComplejo.h"
#include "igvTextura.h"

class Objeto;

class Museo {
	friend class Objeto;

	// poligonos asociados a museo
	poligonoComplejo* paredFrontal;
	poligonoComplejo* paredIzq;
	poligonoComplejo* paredDer;
	poligonoComplejo* techo;
	poligonoComplejo* suelo;
	poligonoComplejo* puerta;
protected:
	bool _salaPrincipal;
public:

	Museo();
	~Museo();

	void visualizar();

};

#endif

