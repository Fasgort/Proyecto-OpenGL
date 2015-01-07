#include "Boxeador.h"

#include "igvColor.h"
#include "bFloat.h"

Boxeador::Boxeador() {
	_isBuilt = false;
	_seleccionado = -1;

	_rotacion = 0;
	_muñeco_b1_ang = 0;
	_muñeco_b2_ang = 0;
	_muñeco_p1_esc = 0;
	_muñeco_p2_esc = 0;
}

Boxeador::~Boxeador() {
	deconstruir();
}

void Boxeador::deconstruir() {
	if(_isBuilt){
		delete mat_pedestal;
		delete mat_cubo;
		delete mat_brazo;
		delete mat_musculo;
		delete mat_puño;

		delete top;
		delete bottom;
		delete front;
		delete back;
		delete left;
		delete right;
		_isBuilt = false;
	}
}

void Boxeador::construir() {
	if(!_isBuilt){
		mat_pedestal = new igvMaterial(igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_cubo = new igvMaterial(igvColor(0.0, 0.0, 0.5), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_brazo = new igvMaterial(igvColor(0.0, 0.1, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_musculo = new igvMaterial(igvColor(0.2, 0.1, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_puño = new igvMaterial(igvColor(0.5, 0.0, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);

		top = new poligonoComplejo(bFloat(-1.5, 1.5, -1.5), bFloat(-1.5, 1.5, 1.5), bFloat(1.5, 1.5, 1.5), bFloat(0, 1, 0), 20);
		bottom = new poligonoComplejo(bFloat(-1.5, -1.5, -1.5), bFloat(-1.5, -1.5, 1.5), bFloat(1.5, -1.5, 1.5), bFloat(0, -1, 0), 20);
		front = new poligonoComplejo(bFloat(-1.5, 1.5, 1.5), bFloat(-1.5, -1.5, 1.5), bFloat(1.5, -1.5, 1.5), bFloat(0, 0, 1), 20);
		back = new poligonoComplejo(bFloat(-1.5, 1.5, -1.5), bFloat(-1.5, -1.5, -1.5), bFloat(1.5, -1.5, -1.5), bFloat(0, 0, -1), 20);
		left = new poligonoComplejo(bFloat(-1.5, 1.5, -1.5), bFloat(-1.5, -1.5, -1.5), bFloat(-1.5, -1.5, 1.5), bFloat(-1, 0, 0), 20);
		right = new poligonoComplejo(bFloat(1.5, 1.5, -1.5), bFloat(1.5, -1.5, -1.5), bFloat(1.5, -1.5, 1.5), bFloat(1, 0, 0), 20);
		_isBuilt = true;
	}
}

void Boxeador::visualizar() {

	GLfloat color_seleccion[] = {1, 1, 0};

	construir();

	GLUquadricObj *cilindro = gluNewQuadric();
	gluQuadricDrawStyle(cilindro, GLU_FILL);

	// Pedestal de rotación
	glPushMatrix();
	mat_pedestal->aplicar();
	if(_seleccionado == P_BOXEADOR) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glTranslatef(0.0, -1.5, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glPushName(P_BOXEADOR);
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

	glPushMatrix();

	// Brazo 1
	mat_brazo->aplicar();
	if(_seleccionado == BRAZO_1) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);

	glTranslatef(1, 0, 0);
	glRotatef(_muñeco_b1_ang, 0, 0, 1);
	glScalef(1-_muñeco_p1_esc, 1, 1);
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glPushName(BRAZO_1);
	gluCylinder(cilindro, 0.5, 0.5, 3.5, 100, 100);
	glPopName();
	glPopMatrix();

	glPushMatrix();

	// Músculo 1
	mat_musculo->aplicar();
	glTranslatef(1.75, 0.2, 0);
	glutSolidSphere(0.45, 100, 100);
	glPopMatrix();

	// Puño 1
	mat_puño->aplicar();
	if(_seleccionado == PUÑO_1) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glTranslatef(3.5, 0, 0);
	glPushName(PUÑO_1);
	glutSolidSphere(1.0, 100, 100);
	glPopName();
	glPopMatrix();

	// Brazo 2
	mat_brazo->aplicar();
	if(_seleccionado == BRAZO_2) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);

	glTranslatef(-1, 0, 0);
	glRotatef(-_muñeco_b2_ang, 0, 0, 1);
	glScalef(1+_muñeco_p2_esc, 1, 1);
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glPushName(BRAZO_2);
	gluCylinder(cilindro, 0.5, 0.5, 3.5, 100, 100);
	glPopName();
	glPopMatrix();

	glPushMatrix();

	// Músculo 2
	mat_musculo->aplicar();

	glTranslatef(-1.75, 0.2, 0);
	glutSolidSphere(0.45, 100, 100);
	glPopMatrix();

	// Puño 2
	mat_puño->aplicar();
	if(_seleccionado == PUÑO_2) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glTranslatef(-3.5, 0, 0);
	glPushName(PUÑO_2);
	glutSolidSphere(1.0, 100, 100);
	glPopName();

	glPopMatrix();

}

void Boxeador::set_rotacion(float inc){
	float _inc = _rotacion + inc;
	if (_inc > 30) _inc = 30;
	if (_inc < -30) _inc = -30;
	_rotacion = _inc;
}

void Boxeador::set_muñeco_b1_ang(float inc){
	float _inc = _muñeco_b1_ang + inc/3;
	if (_inc > 25) _inc = 25;
	if (_inc < -25) _inc = -25;
	_muñeco_b1_ang = _inc;
}

void Boxeador::set_muñeco_b2_ang(float inc){
	float _inc = _muñeco_b2_ang + inc/3;
	if (_inc > 25) _inc = 25;
	if (_inc < -25) _inc = -25;
	_muñeco_b2_ang = _inc;
}

void Boxeador::set_muñeco_p1_esc(float inc){
	float _inc = _muñeco_p1_esc + inc/100;
	if (_inc > 0.25) _inc = 0.25;
	if (_inc < -0.25) _inc = -0.25;
	_muñeco_p1_esc = _inc;
}

void Boxeador::set_muñeco_p2_esc(float inc){
	float _inc = _muñeco_p2_esc + inc/100;
	if (_inc > 0.25) _inc = 0.25;
	if (_inc < -0.25) _inc = -0.25;
	_muñeco_p2_esc = _inc;
}
