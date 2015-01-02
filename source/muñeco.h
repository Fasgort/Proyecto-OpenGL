#ifndef __MUÑECO
#define __MUÑECO

#include <GL/glut.h>
#include "nombres.h"
#include "poligonoComplejo.h"

class Objeto;

class Muñeco {
	friend class Objeto;

	bool isBuilt; // Indica si el objeto ha sido creado

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
	int _seleccionado;
	GLfloat _color_seleccion[3];

	// grados de libertad
	float _muñeco_b1_ang;
	float _muñeco_b2_ang;
	float _muñeco_p1_esc;
	float _muñeco_p2_esc;

public:

	Muñeco();
	~Muñeco();

	void visualizar();

	void set_muñeco_b1_ang(float inc);
	void set_muñeco_b2_ang(float inc);
	void set_muñeco_p1_esc(float inc);
	void set_muñeco_p2_esc(float inc);

};

#endif
