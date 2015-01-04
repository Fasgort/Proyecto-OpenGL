#include "esferasFlotantes.h"
#include "igvMaterial.h"

esferasFlotantes::esferasFlotantes() {
	_isBuilt = false;
	_seleccionado = -1;

	_esfera_x = -1.5;
	_esfera_y = -1.5;
};

esferasFlotantes::~esferasFlotantes() {
	if(_isBuilt) {
		delete top1;
		delete bottom1;
		delete front1;
		delete back1;
		delete left1;
		delete right1;

		delete top2;
		delete bottom2;
		delete back2;
		delete left2;
		delete right2;

		delete top3;
		delete bottom3;
		delete back3;
		delete left3;
		delete right3;
	}
};

void esferasFlotantes::construir() {
	if(!_isBuilt){
		top1 = new poligonoComplejo(bFloat(-0.25, 0.25, -1.5), bFloat(-0.25, 0.25, 1.5), bFloat(0.25, 0.25, 1.5), bFloat(0, 1, 0), 20);
		bottom1 = new poligonoComplejo(bFloat(-0.25, -0.25, -1.5), bFloat(-0.25, -0.25, 1.5), bFloat(0.25, -0.25, 1.5), bFloat(0, -1, 0), 20);
		front1 = new poligonoComplejo(bFloat(-0.25, 0.25, 1.5), bFloat(-0.25, -0.25, 1.5), bFloat(0.25, -0.25, 1.5), bFloat(0, 0, 1), 20);
		back1 = new poligonoComplejo(bFloat(-0.25, 0.25, -1.5), bFloat(-0.25, -0.25, -1.5), bFloat(0.25, -0.25, -1.5), bFloat(0, 0, -1), 20);
		left1 = new poligonoComplejo(bFloat(-0.25, 0.25, -1.5), bFloat(-0.25, -0.25, -1.5), bFloat(-0.25, -0.25, 1.5), bFloat(-1, 0, 0), 20);
		right1 = new poligonoComplejo(bFloat(0.25, 0.25, -1.5), bFloat(0.25, -0.25, -1.5), bFloat(0.25, -0.25, 1.5), bFloat(1, 0, 0), 20);

		top2 = new poligonoComplejo(bFloat(-4.0, 4.0, -1.5), bFloat(-4.0, 4.0, 1.5), bFloat(4.0, 4.0, 1.5), bFloat(0, 1, 0), 20);
		bottom2 = new poligonoComplejo(bFloat(-4.0, -4.0, -1.5), bFloat(-4.0, -4.0, 1.5), bFloat(4.0, -4.0, 1.5), bFloat(0, -1, 0), 20);
		back2 = new poligonoComplejo(bFloat(-4.0, 4.0, -1.5), bFloat(-4.0, -4.0, -1.5), bFloat(4.0, -4.0, -1.5), bFloat(0, 0, -1), 20);
		left2 = new poligonoComplejo(bFloat(-4.0, 4.0, -1.5), bFloat(-4.0, -4.0, -1.5), bFloat(-4.0, -4.0, 1.5), bFloat(-1, 0, 0), 20);
		right2 = new poligonoComplejo(bFloat(4.0, 4.0, -1.5), bFloat(4.0, -4.0, -1.5), bFloat(4.0, -4.0, 1.5), bFloat(1, 0, 0), 20);

		top3 = new poligonoComplejo(bFloat(-4.0, 3.99, -1.5), bFloat(-4.0, 3.99, 1.5), bFloat(4.0, 3.99, 1.5), bFloat(0, -1, 0), 20);
		bottom3 = new poligonoComplejo(bFloat(-4.0, -3.99, -1.5), bFloat(-4.0, -3.99, 1.5), bFloat(4.0, -3.99, 1.5), bFloat(0, 1, 0), 20);
		back3 = new poligonoComplejo(bFloat(-4.0, 4.0, -1.49), bFloat(-4.0, -4.0, -1.49), bFloat(4.0, -4.0, -1.49), bFloat(0, 0, 1), 20);
		left3 = new poligonoComplejo(bFloat(-3.99, 4.0, -1.5), bFloat(-3.99, -4.0, -1.5), bFloat(-3.99, -4.0, 1.5), bFloat(1, 0, 0), 20);
		right3 = new poligonoComplejo(bFloat(3.99, 4.0, -1.5), bFloat(3.99, -4.0, -1.5), bFloat(3.99, -4.0, 1.5), bFloat(-1, 0, 0), 20);

		_isBuilt = true;
	}
}

void esferasFlotantes::visualizar() {

	construir();

	igvMaterial mat_pedestal(igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial mat_rectangulo(igvColor(0.8, 0.8, 0.8), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial mat_cuboExt(igvColor(0.5, 0.5, 0.2), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial mat_cuboInt(igvColor(0.3, 0.0, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial mat_esferaR(igvColor(1.0, 0.0, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	igvMaterial mat_esferaB(igvColor(0.0, 0.0, 1.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
	GLfloat color_seleccion[] = {1, 1, 0};

	GLUquadricObj *cilindro = gluNewQuadric();
	gluQuadricDrawStyle(cilindro, GLU_FILL);

	// Pedestal
	glPushMatrix();
	mat_pedestal.aplicar();
	glTranslatef(0.0, -4.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cilindro, 0.5, 0.5, 5.0, 100, 100);
	glPopMatrix();

	// Cuerpo
	mat_rectangulo.aplicar();
	glPushName(NO_SELECCIONABLE);
	top1->visualizar();
	bottom1->visualizar();
	front1->visualizar();
	back1->visualizar();
	left1->visualizar();
	right1->visualizar();

	mat_cuboExt.aplicar();
	top2->visualizar();
	bottom2->visualizar();
	back2->visualizar();
	left2->visualizar();
	right2->visualizar();

	mat_cuboInt.aplicar();
	top3->visualizar();
	bottom3->visualizar();
	back3->visualizar();
	left3->visualizar();
	right3->visualizar();
	glPopName();

	// Esfera grande (detrás)

	glPushMatrix();
	glTranslatef(_esfera_x, _esfera_y, -0.75);
	mat_esferaR.aplicar();
	if(_seleccionado == ESFERAR) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glPushName(ESFERAR);
	glutSolidSphere(0.75, 100, 100);
	glPopName();
	glPopMatrix();

	// Esfera pequeña (delante)

	glPushMatrix();
	glTranslatef(-_esfera_x, -_esfera_y, 0.75);
	mat_esferaB.aplicar();
	if(_seleccionado == ESFERAB) glMaterialfv(GL_FRONT, GL_EMISSION, color_seleccion);
	glPushName(ESFERAB);
	glutSolidSphere(0.75, 100, 100);
	glPopName();
	glPopMatrix();

}

void esferasFlotantes::setEsferaX(float inc){
	float _inc = _esfera_x + inc/75;
	if (_inc > 3) _inc = 3;
	if (_inc < -3) _inc = -3;
	if (_esfera_y < 1 && _esfera_y > -1 && _inc < 1 && _esfera_x > 0) _inc = 1;
	if (_esfera_y < 1 && _esfera_y > -1 && _inc > -1 && _esfera_x < 0) _inc = -1;
	_esfera_x = _inc;
}

void esferasFlotantes::setEsferaY(float inc){
	float _inc = _esfera_y + inc/75;
	if (_inc > 3) _inc = 3;
	if (_inc < -3) _inc = -3;
	if (_esfera_x < 1 && _esfera_x > -1 && _inc < 1 && _esfera_y > 0) _inc = 1;
	if (_esfera_x < 1 && _esfera_x > -1 && _inc > -1 && _esfera_y < 0) _inc = -1;
	_esfera_y = _inc;
}