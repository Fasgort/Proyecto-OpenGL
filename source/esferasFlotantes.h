#ifndef __ESFERASFLOTANTES
#define __ESFERASFLOTANTES

#include <GL/glut.h>
#include "nombres.h"
#include "poligonoComplejo.h"

class Objeto;

class esferasFlotantes {
	friend class Objeto;

	bool _isBuilt; // Indica si el objeto ha sido creado

	// rectangulo central
	poligonoComplejo* top1;
	poligonoComplejo* bottom1;
	poligonoComplejo* front1;
	poligonoComplejo* back1;
	poligonoComplejo* left1;
	poligonoComplejo* right1;

	// cajetin figura exterior
	poligonoComplejo* top2;
	poligonoComplejo* bottom2;
	poligonoComplejo* back2;
	poligonoComplejo* left2;
	poligonoComplejo* right2;

	// cajetin figura interior
	poligonoComplejo* top3;
	poligonoComplejo* bottom3;
	poligonoComplejo* back3;
	poligonoComplejo* left3;
	poligonoComplejo* right3;

	// Metodo propio del objeto
	void construir();
protected:
	// Atributos
	int _seleccionado;

	// grados de libertad
	float _esfera_x;
	float _esfera_y;

public:

	esferasFlotantes();
	~esferasFlotantes();

	void visualizar();
	void setEsferaX(float inc);
	void setEsferaY(float inc);

};

#endif
