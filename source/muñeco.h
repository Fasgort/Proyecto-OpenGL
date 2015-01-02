#ifndef __MU�ECO
#define __MU�ECO

#include <GL/glut.h>
#include "nombres.h"
#include "poligonoComplejo.h"

class Objeto;

class Mu�eco {
	friend class Objeto;

	bool isBuilt; // Indica si el objeto ha sido creado

	// pol�gono
	poligonoComplejo* top;
	poligonoComplejo* bottom;
	poligonoComplejo* front;
	poligonoComplejo* back;
	poligonoComplejo* left;
	poligonoComplejo* right;

	// Metodo propio del objeto
	void construir();

protected:
	int _seleccionado;
	GLfloat _color_seleccion[3];

	// grados de libertad
	float _mu�eco_b1_ang;
	float _mu�eco_b2_ang;
	float _mu�eco_p1_esc;
	float _mu�eco_p2_esc;

public:

	Mu�eco();
	~Mu�eco();

	void visualizar();

	void set_mu�eco_b1_ang(float inc);
	void set_mu�eco_b2_ang(float inc);
	void set_mu�eco_p1_esc(float inc);
	void set_mu�eco_p2_esc(float inc);

};

#endif
