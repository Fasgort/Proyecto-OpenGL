#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvModelo.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "poligonosComplejos.h"

// Metodos constructores 

igvEscena3D::igvEscena3D() {
	// atributos
	ejes = true;
	salaPrincipal = true;
	seleccionado = -1;

	// grados de libertad
	muneco_b1_ang = 0;
	muneco_b2_ang = 0;
	muneco_p1_esc = 0;
	muneco_p2_esc = 0;
}

igvEscena3D::~igvEscena3D() {
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

void igvEscena3D::creaMuseo(GLfloat* color_seleccion){

	// Definición de variables y materiales

	GLfloat posLuz[4] = {0.0, 0.0, 6.0, 1.0};
	igvColor colAmb1(0.8, 0.8, 0.775, 1.0);
	igvColor colAmb2(0.8, 0.775, 0.8, 1.0);
	igvColor colAmb;
	if(salaPrincipal) colAmb = colAmb1;
	else colAmb = colAmb2;

	igvFuenteLuz luzMuseo(GL_LIGHT0, posLuz, colAmb, igvColor(0.7, 0.7, 0.7, 1.0), igvColor(0.7, 0.7, 0.7, 1.0), 0.0, 0.05, 0.008);
	igvMaterial matParedFrontal(igvColor(0.9, 0.9, 0.9), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial matParedLateral(igvColor(0.875, 0.875, 0.875), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial matSupInf(igvColor(0.85, 0.85, 0.85), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial matPuerta(igvColor(0.3, 0.15, 0.08), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);

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
	if(seleccionado == PUERTA) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glPushName(PUERTA);
	creaRectangulo(bFloat(-1,-3, 1.05), bFloat(1,-3, 1.05), bFloat(1, 1.5, 1.05), bFloat(0, 0, 1)); // puerta
	glPopName();
	glPopMatrix();

}

void igvEscena3D::creaMuneco(GLfloat* color_seleccion) {

	GLfloat color_cubo[]={0,0,0.5};
	GLfloat color_brazo[]={0,0.1,0};
	GLfloat color_musculo[]={0.2,0.1,0};
	GLfloat color_puño[]={0.5,0,0};

	// Cuerpo
	glMaterialfv(GL_FRONT,GL_EMISSION,color_cubo);
	glutSolidCube(3.0);

	glPushMatrix();

	// Brazo 1
	if(seleccionado == BRAZO_1) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_brazo);
	GLUquadricObj *brazo1 = gluNewQuadric();
	gluQuadricDrawStyle(brazo1, GLU_FILL);

	glTranslatef(1,0,0);
	glRotatef(0,0,1,0);
	glRotatef(muneco_b1_ang,0,0,1);
	glScalef(1-muneco_p1_esc,1,1);
	glPushMatrix();
	glRotatef(90,0,1,0);
	glPushName(BRAZO_1);
	gluCylinder(brazo1, 0.5, 0.5, 3.5, 20, 20);
	glPopName();
	glPopMatrix();

	glPushMatrix();

	// Músculo 1
	glMaterialfv(GL_FRONT, GL_EMISSION, color_musculo);
	glTranslatef(1.75,0.2,0);
	glutSolidSphere(0.45,20,20);

	glPopMatrix();

	// Puño 1
	if(seleccionado == PUÑO_1) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_puño);
	glTranslatef(3.5,0,0);
	glPushName(PUÑO_1);
	glutSolidSphere(1.0,20,20);
	glPopName();

	glPopMatrix();

	// Brazo 2
	if(seleccionado == BRAZO_2) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_brazo);
	GLUquadricObj *brazo2 = gluNewQuadric();
	gluQuadricDrawStyle(brazo2, GLU_FILL);

	glTranslatef(-1,0,0);
	glRotatef(0,0,1,0);
	glRotatef(-muneco_b2_ang,0,0,1);
	glScalef(1+muneco_p2_esc,1,1);
	glPushMatrix();
	glRotatef(-90,0,1,0);
	glPushName(BRAZO_2);
	gluCylinder(brazo2, 0.5, 0.5, 3.5, 20, 20);
	glPopName();
	glPopMatrix();

	glPushMatrix();

	// Músculo 2
	glMaterialfv(GL_FRONT, GL_EMISSION, color_musculo);

	glTranslatef(-1.75,0.2,0);
	glutSolidSphere(0.45,20,20);

	glPopMatrix();

	// Puño 2
	if(seleccionado == PUÑO_2) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_puño);
	glTranslatef(-3.5,0,0);
	glPushName(PUÑO_2);
	glutSolidSphere(1.0,20,20);
	glPopName();

}

void igvEscena3D::visualizar(void) {
	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// se pintan los ejes
	if (ejes) pintar_ejes();

	// Inicializamos pila de nombres
	glInitNames();

	// Color de selección
	GLfloat color_seleccion[]={1,1,0};

	creaMuseo(color_seleccion); // creamos el museo
	
	igvMaterial matObjetos(igvColor(0.2, 0.2, 0.2), igvColor(0.2, 0.2, 0.2), igvColor(0.2, 0.2, 0.2), 120);
	matObjetos.aplicar(); // material empleado en los objetos del museo

	// Emplazamiento inicial
	glTranslatef(0, 0, 2);

	if(salaPrincipal){
		// Primera sala

		// PRIMERA FIGURA (inferior izquierda)
		glPushMatrix();
		glTranslatef(-3, -1.5, 0);
		glScalef(0.33, 0.33, 0.33);
		creaMuneco(color_seleccion);
		glPopMatrix();

		// FIGURA TEMPORAL (SE SUSTITUYE POR OTRA FIGURA)
		glPushMatrix();
		glTranslatef(3, -1.5, 0);
		glScalef(0.33, 0.33, 0.33);
		creaMuneco(color_seleccion);
		glPopMatrix();

	} else {
		// Segunda sala

	}

	glPopMatrix (); // restaura la matriz de modelado
}

