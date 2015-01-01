#include "museo.h"

#include "igvMaterial.h"
#include "bFloat.h"
#include "poligonosComplejos.h"
#include "igvFuenteLuz.h"

Museo::Museo() {
	_salaPrincipal = true;
}

Museo::~Museo() {}

void Museo::visualizar() {

	// Definición de variables y materiales

	GLfloat posLuz[4] = {0.0, 0.0, 6.0, 1.0};
	igvColor colAmb1(0.8, 0.8, 0.775, 1.0);
	igvColor colAmb2(0.8, 0.775, 0.8, 1.0);
	igvColor colAmb;
	if(_salaPrincipal) colAmb = colAmb1;
	else colAmb = colAmb2;

	igvFuenteLuz luzMuseo(GL_LIGHT0, posLuz, colAmb, igvColor(0.7, 0.7, 0.7, 1.0), igvColor(0.7, 0.7, 0.7, 1.0), 0.0, 0.05, 0.008);
	igvMaterial matParedFrontal(igvColor(0.9, 0.9, 0.9), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial matParedLateral(igvColor(0.875, 0.875, 0.875), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial matSupInf(igvColor(0.85, 0.85, 0.85), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial matPuerta(igvColor(0.3, 0.15, 0.08), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial matMarco(igvColor(0.15, 0.15, 0.08), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);

	luzMuseo.aplicar();

	glPushMatrix();
	matParedFrontal.aplicar();
	creaRectangulo(bFloat(-6,4,1), bFloat(-6,-3,1), bFloat(6,-3,1), bFloat(0,0,1)); // pared frontal museo
	glPopMatrix();

	glPushMatrix();
	matParedLateral.aplicar();
	creaRectangulo(bFloat(-6,4,1), bFloat(-6,-3,1), bFloat(-6,-3,11), bFloat(1,0,0)); // pared izquierda museo
	creaRectangulo(bFloat(6,-3,1), bFloat(6,-3,11), bFloat(6,4,11), bFloat(-1,0,0)); // pared derecha museo
	glPopMatrix();

	glPushMatrix();
	matSupInf.aplicar();
	creaRectangulo(bFloat(-6,4,1), bFloat(6,4,1), bFloat(6,4,11), bFloat(0,-1,0)); // pared techo museo
	creaRectangulo(bFloat(-6,-3,11), bFloat(6,-3,11), bFloat(6,-3,1), bFloat(0,1,0)); // pared suelo museo
	glPopMatrix();

	glPushMatrix();
	matPuerta.aplicar();
	glPushName(PUERTA);
	creaRectangulo(bFloat(-1,-3, 1.05), bFloat(1,-3, 1.05), bFloat(1, 1.5, 1.05), bFloat(0, 0, 1)); // puerta
	glPopName();
	glPopMatrix();

	glPushMatrix();
	matMarco.aplicar();
	creaRectangulo(bFloat(-4.7, 2.175, 1.05), bFloat(-4.7, 0.825, 1.05), bFloat(-2.3, 0.825, 1.05), bFloat(0, 0, 1)); // marco 1
	creaRectangulo(bFloat(4.7, 2.175, 1.05), bFloat(4.7, 0.825, 1.05), bFloat(2.3, 0.825, 1.05), bFloat(0, 0, 1)); // marco 2
	glPopMatrix();

}