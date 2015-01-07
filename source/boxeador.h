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
	igvMaterial* mat_puño;

	// polígono
	poligonoComplejo* top;
	poligonoComplejo* bottom;
	poligonoComplejo* front;
	poligonoComplejo* back;
	poligonoComplejo* left;
	poligonoComplejo* right;

	// grados de libertad
	float _rotacion;
	float _muñeco_b1_ang;
	float _muñeco_b2_ang;
	float _muñeco_p1_esc;
	float _muñeco_p2_esc;

	// Métodos privados
	void deconstruir();
	void construir();

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
