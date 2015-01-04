#include "cajaCombinacion.h"

#include "igvColor.h"
#include "bFloat.h"

cajaCombinacion::cajaCombinacion() {
	_isBuilt = false;
	_abierto = false;
	_sorpresa = false;
}

cajaCombinacion::~cajaCombinacion() {
	deconstruir();
}

void cajaCombinacion::deconstruir() {
	if(_isBuilt) {
		delete mat_pedestal;
		delete mat_cuboExt;
		delete mat_cuboInt;
		delete mat_botonCaja;
		delete mat_botonSorpresa;
		delete mat_reset;

		delete top;
		delete bottom;
		delete doorClosed;
		delete doorOpened;
		delete back;
		delete left;
		delete right;

		delete top2;
		delete bottom2;
		delete doorClosed2;
		delete doorOpened2;
		delete back2;
		delete left2;
		delete right2;

		delete boton1;
		delete boton2;
		delete boton3;
		delete boton4;
		delete boton5;
		delete boton6;
		delete boton7;
		delete boton8;
		delete boton9;
		delete botonEnter;
		delete botonSorpresa;

		delete tboton1;
		delete tboton2;
		delete tboton3;
		delete tboton4;
		delete tboton5;
		delete tboton6;
		delete tboton7;
		delete tboton8;
		delete tboton9;
		delete tbotonEnter;
	}
}

void cajaCombinacion::construir() {
	if(!_isBuilt){
		mat_pedestal = new igvMaterial(igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_cuboExt = new igvMaterial(igvColor(0.13, 0.08, 0.05), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_cuboInt = new igvMaterial(igvColor(0.1, 0.1, 0.1), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_botonCaja = new igvMaterial(igvColor(0.0, 0.3, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_botonSorpresa = new igvMaterial(igvColor(0.5, 0.0, 0.0), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		mat_reset = new igvMaterial(igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);

		top = new poligonoComplejo(bFloat(-4.0, 4.0, -1.5), bFloat(-4.0, 4.0, 1.5), bFloat(4.0, 4.0, 1.5), bFloat(0, 1, 0), 20);
		bottom = new poligonoComplejo(bFloat(-4.0, -4.0, -1.5), bFloat(-4.0, -4.0, 1.5), bFloat(4.0, -4.0, 1.5), bFloat(0, -1, 0), 20);
		doorClosed = new poligonoComplejo(bFloat(-4.0, 4.0, 1.5), bFloat(-4.0, -4.0, 1.5), bFloat(4.0, -4.0, 1.5), bFloat(0, 0, 1), 20);
		doorOpened = new poligonoComplejo(bFloat(4.0, 4.0, 1.5), bFloat(4.0, -4.0, 1.5), bFloat(6.83, -4.0, 4.33), bFloat(1, 0, -1), 20);
		back = new poligonoComplejo(bFloat(-4.0, 4.0, -1.5), bFloat(-4.0, -4.0, -1.5), bFloat(4.0, -4.0, -1.5), bFloat(0, 0, -1), 20);
		left = new poligonoComplejo(bFloat(-4.0, 4.0, -1.5), bFloat(-4.0, -4.0, -1.5), bFloat(-4.0, -4.0, 1.5), bFloat(-1, 0, 0), 20);
		right = new poligonoComplejo(bFloat(4.0, 4.0, -1.5), bFloat(4.0, -4.0, -1.5), bFloat(4.0, -4.0, 1.5), bFloat(1, 0, 0), 20);

		top2 = new poligonoComplejo(bFloat(-4.0, 3.99, -1.5), bFloat(-4.0, 3.99, 1.5), bFloat(4.0, 3.99, 1.5), bFloat(0, -1, 0), 20);
		bottom2 = new poligonoComplejo(bFloat(-4.0, -3.99, -1.5), bFloat(-4.0, -3.99, 1.5), bFloat(4.0, -3.99, 1.5), bFloat(0, 1, 0), 20);
		doorClosed2 = new poligonoComplejo(bFloat(-4.0, 4.0, 1.49), bFloat(-4.0, -4.0, 1.49), bFloat(4.0, -4.0, 1.49), bFloat(0, 0, -1), 20);
		doorOpened2 = new poligonoComplejo(bFloat(3.99, 4.0, 1.51), bFloat(3.99, -4.0, 1.51), bFloat(6.82, -4.0, 4.34), bFloat(-1, 0, 1), 20);
		back2 = new poligonoComplejo(bFloat(-4.0, 4.0, -1.49), bFloat(-4.0, -4.0, -1.49), bFloat(4.0, -4.0, -1.49), bFloat(0, 0, 1), 20);
		left2 = new poligonoComplejo(bFloat(-3.99, 4.0, -1.5), bFloat(-3.99, -4.0, -1.5), bFloat(-3.99, -4.0, 1.5), bFloat(1, 0, 0), 20);
		right2 = new poligonoComplejo(bFloat(3.99, 4.0, -1.5), bFloat(3.99, -4.0, -1.5), bFloat(3.99, -4.0, 1.5), bFloat(-1, 0, 0), 20);

		boton1 = new poligonoComplejo(bFloat(-3.1125, 3.6, 1.51), bFloat(-3.1125, 2.25, 1.51), bFloat(-1.7625, 2.25, 1.51), bFloat(0, 0, 1), 10);
		boton2 = new poligonoComplejo(bFloat(-0.675, 3.6, 1.51), bFloat(-0.675, 2.25, 1.51), bFloat(0.675, 2.25, 1.51), bFloat(0, 0, 1), 100);
		boton3 = new poligonoComplejo(bFloat(1.7625, 3.6, 1.51), bFloat(1.7625, 2.25, 1.51), bFloat(3.1125, 2.25, 1.51), bFloat(0, 0, 1), 10);
		boton4 = new poligonoComplejo(bFloat(-3.1125, 1.65, 1.51), bFloat(-3.1125, 0.3, 1.51), bFloat(-1.7625, 0.3, 1.51), bFloat(0, 0, 1), 10);
		boton5 = new poligonoComplejo(bFloat(-0.675, 1.65, 1.51), bFloat(-0.675, 0.3, 1.51), bFloat(0.675, 0.3, 1.51), bFloat(0, 0, 1), 10);
		boton6 = new poligonoComplejo(bFloat(1.7625, 1.65, 1.51), bFloat(1.7625, 0.3, 1.51), bFloat(3.1125, 0.3, 1.51), bFloat(0, 0, 1), 10);
		boton7 = new poligonoComplejo(bFloat(-3.1125, -0.4, 1.51), bFloat(-3.1125, -1.75, 1.51), bFloat(-1.7625, -1.75, 1.51), bFloat(0, 0, 1), 10);
		boton8 = new poligonoComplejo(bFloat(-0.675, -0.4, 1.51), bFloat(-0.675, -1.75, 1.51), bFloat(0.675, -1.75, 1.51), bFloat(0, 0, 1), 10);
		boton9 = new poligonoComplejo(bFloat(1.7625, -0.4, 1.51), bFloat(1.7625, -1.75, 1.51), bFloat(3.1125, -1.75, 1.51), bFloat(0, 0, 1), 10);
		botonEnter = new poligonoComplejo(bFloat(-3.0, -2.225, 1.51), bFloat(-3.0, -3.725, 1.51), bFloat(3.0, -3.725, 1.51), bFloat(0, 0, 1), 10);
		botonSorpresa = new poligonoComplejo(bFloat(-2.0, 2.0, -1.48), bFloat(-2.0, -2.0, -1.48), bFloat(2.0, -2.0, -1.48), bFloat(0, 0, 1), 10);

		tboton1 = new igvTextura("texturas/1.bmp");
		tboton2 = new igvTextura("texturas/2.bmp");
		tboton3 = new igvTextura("texturas/3.bmp");
		tboton4 = new igvTextura("texturas/4.bmp");
		tboton5 = new igvTextura("texturas/5.bmp");
		tboton6 = new igvTextura("texturas/6.bmp");
		tboton7 = new igvTextura("texturas/7.bmp");
		tboton8 = new igvTextura("texturas/8.bmp");
		tboton9 = new igvTextura("texturas/9.bmp");
		tbotonEnter = new igvTextura("texturas/enter.bmp");

		_isBuilt = true;
	}
}

void cajaCombinacion::visualizar() {

	GLfloat color_activado[] = {0.0, 0.3, 0.0};
	GLfloat color_activado2[] = {0.5, 0.0, 0.0};
	GLfloat color_desactivado[] = {0.0, 0.0, 0.0};

	construir();

	GLUquadricObj *cilindro = gluNewQuadric();
	gluQuadricDrawStyle(cilindro, GLU_FILL);

	// Pedestal
	glPushMatrix();
	mat_pedestal->aplicar();
	glTranslatef(0.0, -4.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cilindro, 0.5, 0.5, 5.0, 100, 100);
	glPopMatrix();

	glPushName(NO_SELECCIONABLE);

	// caja exterior
	mat_cuboExt->aplicar();
	top->visualizar();
	bottom->visualizar();
	if (!_abierto) doorClosed->visualizar();
	else doorOpened->visualizar();
	back->visualizar();
	left->visualizar();
	right->visualizar();

	// caja interior
	mat_cuboInt->aplicar();
	top2->visualizar();
	bottom2->visualizar();
	if (!_abierto) doorClosed2->visualizar();
	else {
		glPopName();
		glPushName(PUERTA_CAJA);
		doorOpened2->visualizar();
		glPopName();
		glPushName(NO_SELECCIONABLE);
	}
	back2->visualizar();
	left2->visualizar();
	right2->visualizar();

	glPopName();

	// Botones

	if(!_abierto) {

		GLUquadricObj *boton = gluNewQuadric();
		gluQuadricDrawStyle(boton, GLU_FILL);
		mat_botonCaja->aplicar();

		tboton1->aplicar();
		if (_combinacion[0]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_1);
		boton1->visualizar();
		glPopName();

		if (_combinacion[1]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		tboton2->aplicar();
		glPushName(BOTON_2);
		boton2->visualizar();
		glPopName();

		tboton3->aplicar();
		if (_combinacion[2]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_3);
		boton3->visualizar();
		glPopName();

		tboton4->aplicar();
		if (_combinacion[3]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_4);
		boton4->visualizar();
		glPopName();

		tboton5->aplicar();
		if (_combinacion[4]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_5);
		boton5->visualizar();
		glPopName();

		tboton6->aplicar();
		if (_combinacion[5]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_6);
		boton6->visualizar();
		glPopName();

		tboton7->aplicar();
		if (_combinacion[6]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_7);
		boton7->visualizar();
		glPopName();

		tboton8->aplicar();
		if (_combinacion[7]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_8);
		boton8->visualizar();
		glPopName();

		tboton9->aplicar();
		if (_combinacion[8]) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
		glPushName(BOTON_9);
		boton9->visualizar();
		glPopName();

		tbotonEnter->aplicar();
		glMaterialfv(GL_FRONT, GL_EMISSION, color_activado);
		glPushName(BOTON_ENTER);
		botonEnter->visualizar();
		glPopName();

		glBindTexture(GL_TEXTURE_2D, 0);

	}

	mat_botonSorpresa->aplicar();
	if (_sorpresa) glMaterialfv(GL_FRONT, GL_EMISSION, color_activado2);
	else glMaterialfv(GL_FRONT, GL_EMISSION, color_desactivado);
	glPushName(BOTON_SORPRESA);
	botonSorpresa->visualizar();
	glPopName();

}

void cajaCombinacion::setSeleccionado(int seleccionado) {
	switch(seleccionado){
	case BOTON_1:
		_combinacion[0].flip();
		break;
	case BOTON_2:
		_combinacion[1].flip();
		break;
	case BOTON_3:
		_combinacion[2].flip();
		break;
	case BOTON_4:
		_combinacion[3].flip();
		break;
	case BOTON_5:
		_combinacion[4].flip();
		break;
	case BOTON_6:
		_combinacion[5].flip();
		break;
	case BOTON_7:
		_combinacion[6].flip();
		break;
	case BOTON_8:
		_combinacion[7].flip();
		break;
	case BOTON_9:
		_combinacion[8].flip();
		break;
	case BOTON_ENTER:
		if (_combinacion.to_string() == "001010110") _abierto = true; // La combinación válida es activar aquellos números que son primos
		_combinacion.reset();
		break;
	case BOTON_SORPRESA:
		if (!_sorpresa){
			int randR = rand()%8 + 1;
			int randG = rand()%8 + 1;
			int randB = rand()%8 + 1;
			GLfloat luz_sorpresa[] = {0.2 + float(randR)/10, 0.2 + float(randG)/10, 0.2 + float(randB)/10, 1.0};
			glLightModelfv (GL_LIGHT_MODEL_AMBIENT, luz_sorpresa); 
			_sorpresa = true;
		} else {
			GLfloat luz_ambiental[] = {0.2, 0.2, 0.2, 1.0};
			glLightModelfv (GL_LIGHT_MODEL_AMBIENT, luz_ambiental); 
			_sorpresa = false;
		}
		break;
	case PUERTA_CAJA:
		_abierto = false;
		break;
	}
}
