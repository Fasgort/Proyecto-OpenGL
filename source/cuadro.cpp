#include "cuadro.h"

#include "igvMaterial.h"
#include "bFloat.h"

Cuadro::Cuadro() {
	_salaPrincipal = true;

	// Asignación de los polígonos
	cuadro1 = new poligonoComplejo(bFloat(-4.7, 2.1, 1.05), bFloat(-4.7, 0.9, 1.05), bFloat(-2.3, 0.9, 1.05), bFloat(0, 0, 1), 100); // cuadro 1
	cuadro2 = new poligonoComplejo(bFloat(2.3, 2.1, 1.05), bFloat(2.3, 0.9, 1.05), bFloat(4.7, 0.9, 1.05), bFloat(0, 0, 1), 100); // cuadro 2

	pintura1 = new igvTextura("texturas/estrellas.bmp");
	pintura2 = new igvTextura("texturas/mirada.bmp");
	pintura3 = new igvTextura("texturas/playa.bmp");
	pintura4 = new igvTextura("texturas/planeta.bmp");
}

Cuadro::~Cuadro() {
	delete cuadro1;
	delete cuadro2;

	delete pintura1;
	delete pintura2;
	delete pintura3;
	delete pintura4;
}

void Cuadro::visualizar() {

	// Definición de variables y materiales
	igvMaterial matMarco(igvColor(1.0, 1.0, 1.0), igvColor(0.0, 0.0, 0.0), igvColor(0.0, 0.0, 0.0), 120);

	glPushMatrix();
	matMarco.aplicar();
	if(_salaPrincipal) pintura1->aplicar();
	else pintura3->aplicar();
	cuadro1->visualizar(); // cuadro 1
	if(_salaPrincipal) pintura2->aplicar();
	else pintura4->aplicar();
	cuadro2->visualizar(); // cuadro 2
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

}