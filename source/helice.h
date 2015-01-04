#ifndef __HELICE
#define __HELICE

#include <GL/glut.h>

#include "Objeto.h"
#include "nombres.h"
#include "igvMaterial.h"
#include "poligonoComplejo.h"

class Helice: public Objeto {
	friend class igvEscena3D;

	// materiales
	igvMaterial* mat_pedestal;
	igvMaterial* mat_cubo;
	igvMaterial* mat_helice;
	igvMaterial* mat_esfera;
	igvMaterial* mat_palanca;

	// polígono
	poligonoComplejo* top;
	poligonoComplejo* bottom;
	poligonoComplejo* front;
	poligonoComplejo* back;
	poligonoComplejo* left;
	poligonoComplejo* right;

	// grados de libertad
	float _rotacion;
	float _palanca_inc;
	float _helice_ang;

	// Métodos privados
	void deconstruir();
	void construir();

public:

	Helice();
	~Helice();

	void visualizar();

	void set_rotacion(float inc);
	void setRotAng(float inc);

};

#endif
