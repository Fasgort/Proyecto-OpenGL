#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvMaterial.h"
#include "igvTextura.h"

// Metodos constructores 

igvEscena3D::igvEscena3D() {
	// atributos
	ejes = true;
	objetos = new Objeto();
}

igvEscena3D::~igvEscena3D() {
	delete objetos;
}

// Metodos publicos 

void pintar_ejes(void) {
	GLfloat rojo[]={1,0,0,1.0};
	GLfloat verde[]={0,1,0,1.0};
	GLfloat azul[]={0,0,1,1.0};

	glBegin(GL_LINES);
	glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glVertex3f(1000,0,0);
	glVertex3f(-1000,0,0);

	glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glVertex3f(0,1000,0);
	glVertex3f(0,-1000,0);

	glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glVertex3f(0,0,1000);
	glVertex3f(0,0,-1000);
	glEnd();
}

void igvEscena3D::visualizar(void) {
	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// se pintan los ejes
	if (ejes) pintar_ejes();

	// Inicializamos pila de nombres
	glInitNames();

	objetos->visualizaMuseo(); // visualizamos el museo

	igvMaterial matObjetos(igvColor(0.2, 0.2, 0.2), igvColor(0.1, 0.1, 0.1), igvColor(0.1, 0.1, 0.1), 120);
	matObjetos.aplicar(); // material empleado en los objetos del museo

	// Emplazamiento inicial
	glTranslatef(0, 0, 2);

	if(objetos->getSalaPrincipal()){
		// Primera sala

		// PRIMERA FIGURA (inferior izquierda)
		glPushMatrix();
		glTranslatef(-3.5, -1.5, 0);
		glScalef(0.3, 0.3, 0.3);
		objetos->visualizaMuneco();
		glPopMatrix();

	} else {
		// Segunda sala

	}

	glPopMatrix (); // restaura la matriz de modelado
}

