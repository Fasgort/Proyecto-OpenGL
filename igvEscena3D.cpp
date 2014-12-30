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

	glPopMatrix();

}

void igvEscena3D::visualizar(void) {
	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// se pintan los ejes
	if (ejes) pintar_ejes();

	// Dibujando objetos
	glInitNames();

	// Color de selección
	GLfloat color_seleccion[]={1,1,0};

	GLfloat posLuz[4] = {0.0, 0.0, 6.0, 1.0};
	igvColor colAmb(0.8, 0.8, 0.775, 1.0);
	igvColor colDif(0.7, 0.7, 0.7, 1.0);
	igvColor colSpe(0.7, 0.7, 0.7, 1.0);
	double atenAmbLuz = 0.0;
	double atenDifLuz = 0.05;
	double atenSpeLuz = 0.008;
	igvFuenteLuz luz1(GL_LIGHT0, posLuz, colAmb, colDif, colSpe, atenAmbLuz, atenDifLuz, atenSpeLuz);
	luz1.aplicar();

	igvColor KaMat(0.9, 0.9, 0.9);
	igvColor KdMat(0.7, 0.7, 0.7);
	igvColor KsMat(0.7, 0.7, 0.7);
	double NsMat = 120;
	igvMaterial material1(KaMat, KdMat, KsMat, NsMat);
	material1.aplicar();

	GLfloat pfpunto1[3] = {-6,4,1};
	GLfloat pfpunto2[3] = {-6,-3,1};
	GLfloat pfpunto3[3] = {6,-3,1};
	GLfloat pfnormal1[3] = {0,0,1};
	creaRectangulo(pfpunto1, pfpunto2, pfpunto3, pfnormal1); // pared frontal museo

	igvColor KaMat2(0.875, 0.875, 0.875);
	igvColor KdMat2(0.7, 0.7, 0.7);
	igvColor KsMat2(0.7, 0.7, 0.7);
	double NsMat2 = 120;
	igvMaterial material2(KaMat2, KdMat2, KsMat2, NsMat2);
	material2.aplicar();

	GLfloat pipunto1[3] = {-6,4,1};
	GLfloat pipunto2[3] = {-6,-3,1};
	GLfloat pipunto3[3] = {-6,-3,11};
	GLfloat pinormal1[3] = {1,0,0};
	creaRectangulo(pipunto1, pipunto2, pipunto3, pinormal1); // pared izquierda museo

	GLfloat pdpunto1[3] = {6,-3,1};
	GLfloat pdpunto2[3] = {6,-3,11};
	GLfloat pdpunto3[3] = {6,4,11};
	GLfloat pdnormal1[3] = {-1,0,0};
	creaRectangulo(pdpunto1, pdpunto2, pdpunto3, pdnormal1); // pared derecha museo

	igvColor KaMat3(0.85, 0.85, 0.85);
	igvColor KdMat3(0.7, 0.7, 0.7);
	igvColor KsMat3(0.7, 0.7, 0.7);
	double NsMat3 = 120;
	igvMaterial material3(KaMat3, KdMat3, KsMat3, NsMat3);
	material3.aplicar();

	GLfloat ptpunto1[3] = {-6,4,1};
	GLfloat ptpunto2[3] = {6,4,1};
	GLfloat ptpunto3[3] = {6,4,11};
	GLfloat ptnormal1[3] = {0,-1,0};
	creaRectangulo(ptpunto1, ptpunto2, ptpunto3, ptnormal1); // pared techo museo

	GLfloat pbpunto1[3] = {-6,-3,11};
	GLfloat pbpunto2[3] = {6,-3,11};
	GLfloat pbpunto3[3] = {6,-3,1};
	GLfloat pbnormal1[3] = {0,1,0};
	creaRectangulo(pbpunto1, pbpunto2, pbpunto3, pbnormal1); // pared suelo museo

	igvColor KaMat4(0.4, 0.1, 0.1);
	igvColor KdMat4(0.7, 0.7, 0.7);
	igvColor KsMat4(0.7, 0.7, 0.7);
	double NsMat4 = 120;
	igvMaterial material4(KaMat4, KdMat4, KsMat4, NsMat4);
	material4.aplicar();

	GLfloat puertapunto1[3] = {-1,-3,1.05};
	GLfloat puertapunto2[3] = {1,-3,1.05};
	GLfloat puertapunto3[3] = {1,1.5,1.05};
	GLfloat puertanormal1[3] = {0,0,1};

	if(seleccionado == PUERTA) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glPushName(PUERTA);
	creaRectangulo(puertapunto1, puertapunto2, puertapunto3, puertanormal1); // puerta
	glPopName();
	igvColor nlKaMat(0, 0, 0);
	igvColor nlKdMat(0, 0, 0);
	igvColor nlKsMat(0, 0, 0);
	double nlNsMat = 120;
	igvMaterial nlmaterial(nlKaMat, nlKdMat, nlKsMat, nlNsMat);
	nlmaterial.aplicar();

	// Emplazamiento inicial
	glTranslatef(0, 0, 2);
	glPushMatrix();

	if(salaPrincipal){
		// Primera sala

		// PRIMERA FIGURA (inferior izquierda)
		glPushMatrix();
		glTranslatef(-3, -1.5, 0);
		glScalef(0.33, 0.33, 0.33);
		creaMuneco(color_seleccion);
		glPopMatrix();

	} else {
		// Segunda sala

	}

	glPopMatrix (); // restaura la matriz de modelado
}

