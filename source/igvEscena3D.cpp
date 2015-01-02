#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvMaterial.h"
#include "igvTextura.h"

// Metodos constructores 

igvEscena3D::igvEscena3D() {
	// atributos
	objetos = new Objeto();
}

igvEscena3D::~igvEscena3D() {
	delete objetos;
}

// Metodos publicos 

void igvEscena3D::visualizar(void) {
	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// Inicializamos pila de nombres
	glInitNames();

	objetos->visualizaMuseo(); // visualizamos el museo
	objetos->visualizaCuadro(); // visualizamos los cuadros

	// Emplazamiento inicial
	glTranslatef(0, 0, 2);

	if(objetos->getSalaPrincipal()){
		// Primera sala

		// PRIMERA FIGURA (inferior izquierda)
		glPushMatrix();
		glTranslatef(-3.5, -1.5, 0);
		glScalef(0.3, 0.3, 0.3);
		objetos->visualizaFigura1();
		glPopMatrix();

		// SEGUNDA FIGURA (inferior derecha)
		glPushMatrix();
		glTranslatef(3.5, -1.5, 0);
		glScalef(0.3, 0.3, 0.3);
		objetos->visualizaFigura2();
		glPopMatrix();

	} else {
		// Segunda sala

		// TERCERA FIGURA (inferior izquierda)
		glPushMatrix();
		glTranslatef(-3.5, -1.5, 0);
		glScalef(0.3, 0.3, 0.3);
		objetos->visualizaFigura3();
		glPopMatrix();

		// CUARTA FIGURA (inferior derecha)
		glPushMatrix();
		glTranslatef(3.5, -1.5, 0);
		glScalef(0.3, 0.3, 0.3);
		objetos->visualizaFigura4();
		glPopMatrix();

	}

	glPopMatrix (); // restaura la matriz de modelado
}

