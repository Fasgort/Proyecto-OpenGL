#include "museo.h"

#include "igvMaterial.h"
#include "bFloat.h"
#include "igvFuenteLuz.h"

Museo::Museo() {
	_salaPrincipal = true;

	// Asignación de los polígonos
	paredFrontal = new poligonoComplejo(bFloat(-6,4,1), bFloat(-6,-3,1), bFloat(6,-3,1), bFloat(0,0,1), 5); // pared frontal museo
	paredIzq = new poligonoComplejo(bFloat(-6,4,1), bFloat(-6,-3,1), bFloat(-6,-3,11), bFloat(1,0,0), 5); // pared izquierda museo
	paredDer = new poligonoComplejo(bFloat(6,-3,1), bFloat(6,-3,11), bFloat(6,4,11), bFloat(-1,0,0), 5); // pared derecha museo
	techo = new poligonoComplejo(bFloat(-6,4,1), bFloat(6,4,1), bFloat(6,4,11), bFloat(0,-1,0), 5); // pared techo museo
	suelo = new poligonoComplejo(bFloat(-6,-3,11), bFloat(6,-3,11), bFloat(6,-3,1), bFloat(0,1,0), 5); // pared suelo museo
	puerta = new poligonoComplejo(bFloat(-1,-3, 1.05), bFloat(1,-3, 1.05), bFloat(1, 1.5, 1.05), bFloat(0, 0, 1), 5); // puerta
	cuadro1 = new poligonoComplejo(bFloat(-4.7, 2.175, 1.05), bFloat(-4.7, 0.825, 1.05), bFloat(-2.3, 0.825, 1.05), bFloat(0, 0, 1), 5); // cuadro 1
	cuadro2 = new poligonoComplejo(bFloat(4.7, 2.175, 1.05), bFloat(4.7, 0.825, 1.05), bFloat(2.3, 0.825, 1.05), bFloat(0, 0, 1), 5); // cuadro 2
}

Museo::~Museo() {
	if(paredFrontal) delete paredFrontal;
	if(paredIzq) delete paredIzq;
	if(paredDer) delete paredDer;
	if(techo) delete techo;
	if(suelo) delete suelo;
	if(puerta) delete puerta;
	if(cuadro1) delete cuadro1;
	if(cuadro2) delete cuadro2;
}

void Museo::visualizar() {

	// Definición de variables y materiales

	GLfloat posLuz[4] = {0.0, 0.0, 10.0, 1.0};
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
	paredFrontal->visualizar(); // pared frontal museo
	glPopMatrix();

	glPushMatrix();
	matParedLateral.aplicar();
	paredIzq->visualizar(); // pared izquierda museo
	paredDer->visualizar(); // pared derecha museo
	glPopMatrix();

	glPushMatrix();
	matSupInf.aplicar();
	techo->visualizar(); // pared techo museo
	suelo->visualizar(); // pared suelo museo
	glPopMatrix();

	glPushMatrix();
	matPuerta.aplicar();
	glPushName(PUERTA);
	puerta->visualizar(); // puerta
	glPopName();
	glPopMatrix();

	glPushMatrix();
	matMarco.aplicar();
	textura.aplicar();
	cuadro1->visualizar(); // cuadro 1
	cuadro2->visualizar(); // cuadro 2
	glPopMatrix();

}