#ifndef __ESFERASFLOTANTES
#define __ESFERASFLOTANTES

#include <GL/glut.h>

#include "Objeto.h"
#include "igvMaterial.h"
#include "poligonoComplejo.h"

class esferasFlotantes: public Objeto {
	friend class igvEscena3D;

	// materiales
	igvMaterial* mat_pedestal;
	igvMaterial* mat_rectangulo;
	igvMaterial* mat_cuboExt;
	igvMaterial* mat_cuboInt;
	igvMaterial* mat_esferaR;
	igvMaterial* mat_esferaB;

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

	// grados de libertad
	float _esfera_x;
	float _esfera_y;

	// Métodos privados
	void deconstruir();
	void construir();

public:

	esferasFlotantes();
	~esferasFlotantes();

	void visualizar();
	void setEsferaX(float inc);
	void setEsferaY(float inc);

};

#endif
