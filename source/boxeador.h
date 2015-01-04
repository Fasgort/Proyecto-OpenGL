#ifndef __BOXEADOR
#define __BOXEADOR

#include <GL/glut.h>

#include "nombres.h"
#include "poligonoComplejo.h"

class Objeto;

class Boxeador {
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
	void deconstruir();
	void construir();

protected:
	int _seleccionado;

	// grados de libertad
	float _rotacion;
	float _muñeco_b1_ang;
	float _muñeco_b2_ang;
	float _muñeco_p1_esc;
	float _muñeco_p2_esc;

public:

	Boxeador();
	~Boxeador();

	void visualizar();

	void set_rotacion(float inc);
	void set_muñeco_b1_ang(float inc);
	void set_muñeco_b2_ang(float inc);
	void set_muñeco_p1_esc(float inc);
	void set_muñeco_p2_esc(float inc);

};

#endif
