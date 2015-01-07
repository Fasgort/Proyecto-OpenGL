#ifndef __MUSEO
#define __MUSEO

#include <GL/glut.h>

#include "Objeto.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "poligonoComplejo.h"
#include "igvTextura.h"

class Museo: public Objeto {
	friend class igvEscena3D;

	// fuentes de luz
	igvFuenteLuz* luzMuseo;
	igvFuenteLuz* luzMuseo2;
	igvFuenteLuz* luzFigura1;
	igvFuenteLuz* luzFigura2;
	igvFuenteLuz* luzCuadro1;
	igvFuenteLuz* luzCuadro2;

	// materiales
	igvMaterial* matParedFrontal;
	igvMaterial* matParedLateral;
	igvMaterial* matSupInf;
	igvMaterial* matPuerta;
	igvMaterial* matMarco;

	// poligonos asociados a museo
	poligonoComplejo* paredFrontal;
	poligonoComplejo* paredTrasera;
	poligonoComplejo* paredIzq;
	poligonoComplejo* paredDer;
	poligonoComplejo* techo;
	poligonoComplejo* suelo;
	poligonoComplejo* puerta;

	// poligonos asociados a cuadros
	poligonoComplejo* cuadro1;
	poligonoComplejo* cuadro2;

	// texturas
	igvTextura* pintura1;
	igvTextura* pintura2;
	igvTextura* pintura3;
	igvTextura* pintura4;

	// variables
	bool _salaPrincipal;

	// Métodos privados
	void deconstruir();
	void construir();

public:

	Museo();
	~Museo();

	void visualizar();

	void set_salaPrincipal(bool salaPrincipal){_salaPrincipal = salaPrincipal;};

};

#endif

