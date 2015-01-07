#ifndef __BOXEADOR
#define __BOXEADOR

#include <GL/glut.h>

#include "Objeto.h"
#include "igvMaterial.h"
#include "poligonoComplejo.h"

class Boxeador: public Objeto {
	friend class igvEscena3D;

	// materiales
	igvMaterial* mat_pedestal;
	igvMaterial* mat_cubo;
	igvMaterial* mat_brazo;
	igvMaterial* mat_musculo;
	igvMaterial* mat_pu�o;

	// pol�gono
	poligonoComplejo* top;
	poligonoComplejo* bottom;
	poligonoComplejo* front;
	poligonoComplejo* back;
	poligonoComplejo* left;
	poligonoComplejo* right;

	// grados de libertad
	float _rotacion;
	float _mu�eco_b1_ang;
	float _mu�eco_b2_ang;
	float _mu�eco_p1_esc;
	float _mu�eco_p2_esc;

	// M�todos privados
	void deconstruir();
	void construir();

public:

	Boxeador();
	~Boxeador();

	void visualizar();

	void set_rotacion(float inc);
	void set_mu�eco_b1_ang(float inc);
	void set_mu�eco_b2_ang(float inc);
	void set_mu�eco_p1_esc(float inc);
	void set_mu�eco_p2_esc(float inc);

};

#endif
