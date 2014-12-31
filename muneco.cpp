#include "muneco.h"

Muneco::Muneco() {
	_seleccionado = -1;
	_color_seleccion[0] = 1;
	_color_seleccion[1] = 1;
	_color_seleccion[2] = 0;
	_muneco_b1_ang = 0;
	_muneco_b2_ang = 0;
	_muneco_p1_esc = 0;
	_muneco_p2_esc = 0;
};

Muneco::~Muneco() {};

void Muneco::visualizar() {

	GLfloat color_cubo[]={0,0,0.5};
	GLfloat color_brazo[]={0,0.1,0};
	GLfloat color_musculo[]={0.2,0.1,0};
	GLfloat color_puño[]={0.5,0,0};

	// Cuerpo
	glMaterialfv(GL_FRONT,GL_EMISSION,color_cubo);
	glutSolidCube(3.0);

	glPushMatrix();

	// Brazo 1
	if(_seleccionado == BRAZO_1) glMaterialfv(GL_FRONT, GL_EMISSION, _color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_brazo);
	GLUquadricObj *brazo1 = gluNewQuadric();
	gluQuadricDrawStyle(brazo1, GLU_FILL);

	glTranslatef(1,0,0);
	glRotatef(0,0,1,0);
	glRotatef(_muneco_b1_ang,0,0,1);
	glScalef(1-_muneco_p1_esc,1,1);
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
	if(_seleccionado == PUÑO_1) glMaterialfv(GL_FRONT, GL_EMISSION, _color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_puño);
	glTranslatef(3.5,0,0);
	glPushName(PUÑO_1);
	glutSolidSphere(1.0,20,20);
	glPopName();

	glPopMatrix();

	// Brazo 2
	if(_seleccionado == BRAZO_2) glMaterialfv(GL_FRONT, GL_EMISSION, _color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_brazo);
	GLUquadricObj *brazo2 = gluNewQuadric();
	gluQuadricDrawStyle(brazo2, GLU_FILL);

	glTranslatef(-1,0,0);
	glRotatef(0,0,1,0);
	glRotatef(-_muneco_b2_ang,0,0,1);
	glScalef(1+_muneco_p2_esc,1,1);
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
	if(_seleccionado == PUÑO_2) glMaterialfv(GL_FRONT, GL_EMISSION, _color_seleccion);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_puño);
	glTranslatef(-3.5,0,0);
	glPushName(PUÑO_2);
	glutSolidSphere(1.0,20,20);
	glPopName();

}

void Muneco::set_muneco_b1_ang(float inc){
	float _inc = _muneco_b1_ang + inc/3;
	if (_inc > 25) _inc = 25;
	if (_inc < -25) _inc = -25;
	_muneco_b1_ang = _inc;
}

void Muneco::set_muneco_b2_ang(float inc){
	float _inc = _muneco_b2_ang + inc/3;
	if (_inc > 25) _inc = 25;
	if (_inc < -25) _inc = -25;
	_muneco_b2_ang = _inc;
}

void Muneco::set_muneco_p1_esc(float inc){
	float _inc = _muneco_p1_esc + inc/100;
	if (_inc > 0.25) _inc = 0.25;
	if (_inc < -0.25) _inc = -0.25;
	_muneco_p1_esc = _inc;
}

void Muneco::set_muneco_p2_esc(float inc){
	float _inc = _muneco_p2_esc + inc/100;
	if (_inc > 0.25) _inc = 0.25;
	if (_inc < -0.25) _inc = -0.25;
	_muneco_p2_esc = _inc;
}
