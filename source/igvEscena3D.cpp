#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvMaterial.h"
#include "igvTextura.h"

// Metodos constructores 

igvEscena3D::igvEscena3D() {
	_seleccionado = -1;
	_salaPrincipal = true;
	_figuraVisualizada = -1;

	rotX = 0;
	rotY = 0;

	museo = new Museo();
	figura1 = new Boxeador();
	figura2 = new Helice();
	figura3 = new esferasFlotantes();
	figura4 = new cajaCombinacion();
}

igvEscena3D::~igvEscena3D() {
	delete museo;
	delete figura1;
	delete figura2;
	delete figura3;
	delete figura4;
}

// Metodos publicos 

void igvEscena3D::visualizar(void) {
	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// Inicializamos pila de nombres
	glInitNames();

	museo->visualizar(); // visualizamos el museo

	// Emplazamiento inicial
	glTranslatef(0, -1.5, 2);

	if(_salaPrincipal){
		// Primera sala

		// PRIMERA FIGURA (inferior izquierda)
		glPushMatrix();
		glTranslatef(-3.5, 0, 0);
		glScalef(0.33, 0.33, 0.33);
		figura1->visualizar();
		glPopMatrix();

		// SEGUNDA FIGURA (inferior derecha)
		glPushMatrix();
		glTranslatef(3.5, 0, 0);
		glScalef(0.33, 0.33, 0.33);
		figura2->visualizar();
		glPopMatrix();

	} else {
		// Segunda sala

		// TERCERA FIGURA (inferior izquierda)
		glPushMatrix();
		glTranslatef(-3.5, 0, 0);
		glScalef(0.33, 0.33, 0.33);
		figura3->visualizar();
		glPopMatrix();

		// CUARTA FIGURA (inferior derecha)
		glPushMatrix();
		glTranslatef(3.5, 0, 0);
		glScalef(0.33, 0.33, 0.33);
		figura4->visualizar();
		glPopMatrix();

	}

	glPopMatrix (); // restaura la matriz de modelado
}

void igvEscena3D::visualizarAparte(void) {
	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// Inicializamos pila de nombres
	glInitNames();

	glRotatef(rotX, -1, 0, 0);
	glRotatef(rotY, 0, -1, 0);

	glScalef(0.75, 0.75, 0.75);

	switch(_figuraVisualizada){
	case BOXEADOR:
		figura1->visualizar();
		break;
	case HELICE:
		figura2->visualizar();
		break;
	case ESFERASFLOTANTES:
		figura3->visualizar();
		break;
	case CAJACOMBINATORIA:
		figura4->visualizar();
		break;
	}

	glPopMatrix (); // restaura la matriz de modelado
}

