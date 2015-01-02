#ifndef __HELICE
#define __HELICE

#include <GL/glut.h>
#include "nombres.h"
#include "poligonoComplejo.h"

class Objeto;

class Helice {
	friend class Objeto;

	bool _isBuilt; // Indica si el objeto ha sido creado

	// polígono
	poligonoComplejo* top;
	poligonoComplejo* bottom;
	poligonoComplejo* front;
	poligonoComplejo* back;
	poligonoComplejo* left;
	poligonoComplejo* right;

	// Metodo propio del objeto
	void construir();
protected:
	// Atributos
	int _seleccionado;

	// grados de libertad
	float _palanca_inc;
	float _helice_ang;

public:

	Helice();
	~Helice();

	void visualizar();
	void setRotAng(float inc);

};

#endif
