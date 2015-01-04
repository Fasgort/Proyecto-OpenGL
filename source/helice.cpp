#include "helice.h"

#include "igvColor.h"
#include "bFloat.h"

Helice::Helice() {
	_isBuilt = false;
	_seleccionado = -1;

	_rotacion = 0;
	_palanca_inc = 0.0;
	_helice_ang = 0;
}

Helice::~Helice() {
	deconstruir();
}

void Helice::deconstruir() {
	if(_isBuilt) {
		delete mat_pedestal;
		delete mat_cubo;
		delete mat_helice;
		delete mat_esfera;
		delete mat_palanca;

		delete top;
		delete bottom;
		delete front;
		delete back;
		delete left;
		delete right;
		_isBuilt = false;
	}
}

void Helice::construir() {
	if(!_isBuilt){
		mat_pedestal = new igvMaterial(igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_cubo = new igvMaterial(igvColor(0.5, 0.0, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_helice = new igvMaterial(igvColor(0.0, 0.5, 0.3), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_esfera = new igvMaterial(igvColor(0.0, 0.0, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_palanca = new igvMaterial(igvColor(1.0, 0.65, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);

		top = new poligonoComplejo(bFloat(-1.5, 1.5, -1.5), bFloat(-1.5, 1.5, 1.5), bFloat(1.5, 1.5, 1.5), bFloat(0, 1, 0), 20);
		bottom = new poligonoComplejo(bFloat(-1.5, -1.5, -1.5), bFloat(-1.5, -1.5, 1.5), bFloat(1.5, -1.5, 1.5), bFloat(0, -1, 0), 20);
		front = new poligonoComplejo(bFloat(-1.5, 1.5, 1.5), bFloat(-1.5, -1.5, 1.5), bFloat(1.5, -1.5, 1.5), bFloat(0, 0, 1), 20);
		back = new poligonoComplejo(bFloat(-1.5, 1.5, -1.5), bFloat(-1.5, -1.5, -1.5), bFloat(1.5, -1.5, -1.5), bFloat(0, 0, -1), 20);
		left = new poligonoComplejo(bFloat(-1.5, 1.5, -1.5), bFloat(-1.5, -1.5, -1.5), bFloat(-1.5, -1.5, 1.5), bFloat(-1, 0, 0), 20);
		right = new poligonoComplejo(bFloat(1.5, 1.5, -1.5), bFloat(1.5, -1.5, -1.5), bFloat(1.5, -1.5, 1.5), bFloat(1, 0, 0), 20);
		_isBuilt = true;
	}
}

void Helice::visualizar() {

	GLfloat color_seleccion[] = {1, 1, 0};

	construir();

	GLUquadricObj *cilindro = gluNewQuadric();
	gluQuadricDrawStyle(cilindro, GLU_FILL);

	// Pedestal de rotación
	glPushMatrix();
	mat_pedestal->aplicar();
	if(_seleccionado == P_HELICE) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glTranslatef(0.0, -1.5, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glPushName(P_HELICE);
	gluCylinder(cilindro, 0.5, 0.5, 4.5, 100, 100);
	glPopName();
	glPopMatrix();

	glPushMatrix();
	glRotatef(_rotacion, 0.0, -1.0, 0.0);

	// Cuerpo
	mat_cubo->aplicar();
	glPushName(NO_SELECCIONABLE);
	top->visualizar();
	bottom->visualizar();
	front->visualizar();
	back->visualizar();
	left->visualizar();
	right->visualizar();
	glPopName();

	// Palanca control
	glPushMatrix();

	glRotatef(-90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);

	mat_palanca->aplicar();
	if(_seleccionado == PALANCA) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glTranslatef(0.0, 0.0, 1.0 - _palanca_inc);
	glPushName(PALANCA);
	gluCylinder(cilindro, 0.5, 0.5, 4.0, 100, 100);
	glTranslatef(0.0, 0.0, 4.0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0.0, 0.0, -1.25);
	gluCylinder(cilindro, 0.5, 0.5, 2.5, 100, 100);
	glPopName();
	glPopMatrix();

	// Esfera helice
	glPushMatrix();

	mat_helice->aplicar();
	glTranslatef(0.0, 0.0, 1.65);
	glutSolidSphere(0.45, 100, 100);

	// Cilindros helice
	GLUquadricObj *helice = gluNewQuadric();
	gluQuadricDrawStyle(helice, GLU_FILL);

	glRotatef(90, 1, 0, 0);

	glPushMatrix();
	glRotatef(_helice_ang, 0, 1, 0);
	mat_helice->aplicar();
	gluCylinder(helice, 0.1, 0.1, 2.5, 100, 100);
	glTranslatef(0.0, 0.0, 2.5);
	mat_esfera->aplicar();
	glutSolidSphere(0.25, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90+_helice_ang, 0, 1, 0);
	mat_helice->aplicar();
	gluCylinder(helice, 0.1, 0.1, 2.5, 100, 100);
	glTranslatef(0.0, 0.0, 2.5);
	mat_esfera->aplicar();
	glutSolidSphere(0.25, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180+_helice_ang, 0, 1, 0);
	mat_helice->aplicar();
	gluCylinder(helice, 0.1, 0.1, 2.5, 100, 100);
	glTranslatef(0.0, 0.0, 2.5);
	mat_esfera->aplicar();
	glutSolidSphere(0.25, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glRotatef(270+_helice_ang, 0, 1, 0);
	mat_helice->aplicar();
	gluCylinder(helice, 0.1, 0.1, 2.5, 100, 100);
	glTranslatef(0.0, 0.0, 2.5);
	mat_esfera->aplicar();
	glutSolidSphere(0.25, 100, 100);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}

void Helice::set_rotacion(float inc){
	float _inc = _rotacion + inc;
	if (_inc > 360) _inc -= 360;
	if (_inc < -360) _inc += 360;
	_rotacion = _inc;
	deconstruir();
}

void Helice::setRotAng(float inc){
	float _inc = _palanca_inc + inc/75;
	if (_inc > 2) _inc = 2;
	if (_inc < -0) _inc = 0;
	_palanca_inc = _inc;
	_helice_ang = _palanca_inc * 180; 
}