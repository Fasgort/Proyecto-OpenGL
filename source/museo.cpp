#include "museo.h"

#include "igvColor.h"
#include "bFloat.h"

Museo::Museo() {
	_salaPrincipal = true;
}

Museo::~Museo() {
	deconstruir();
}

void Museo::deconstruir() {
	if(_isBuilt){
		delete luzMuseo;
		delete luzMuseo2;

		delete matParedFrontal;
		delete matParedLateral;
		delete matSupInf;
		delete matPuerta;
		delete matMarco;

		delete paredFrontal;
		delete paredTrasera;
		delete paredIzq;
		delete paredDer;
		delete techo;
		delete suelo;
		delete puerta;

		delete cuadro1;
		delete cuadro2;

		delete pintura1;
		delete pintura2;
		delete pintura3;
		delete pintura4;
		_isBuilt = false;
	}
}

void Museo::construir() {
	if(!_isBuilt){
		GLfloat posLuz[4] = {0.0, 3.5, 5.5, 1.0};

		luzMuseo = new igvFuenteLuz(GL_LIGHT0, posLuz, igvColor(0.8, 0.8, 0.75, 1.0), igvColor(0.7, 0.7, 0.7, 1.0), igvColor(0.7, 0.7, 0.7, 1.0), 0.75, 0.05, 0.008);
		luzMuseo2 = new igvFuenteLuz(GL_LIGHT0, posLuz, igvColor(0.8, 0.75, 0.8, 1.0), igvColor(0.7, 0.7, 0.7, 1.0), igvColor(0.7, 0.7, 0.7, 1.0), 0.75, 0.05, 0.008);

		matParedFrontal = new igvMaterial(igvColor(0.9, 0.9, 0.9), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		matParedLateral = new igvMaterial(igvColor(0.875, 0.875, 0.875), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		matSupInf = new igvMaterial(igvColor(0.85, 0.85, 0.85), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		matPuerta = new igvMaterial(igvColor(0.3, 0.15, 0.08), igvColor(0.7, 0.7, 0.7), igvColor(0.7, 0.7, 0.7), 120);
		matMarco = new igvMaterial(igvColor(1.0, 1.0, 1.0), igvColor(0.0, 0.0, 0.0), igvColor(0.0, 0.0, 0.0), 120);

		paredFrontal = new poligonoComplejo(bFloat(-6,4,1), bFloat(-6,-3,1), bFloat(6,-3,1), bFloat(0,0,1), 100);
		paredTrasera = new poligonoComplejo(bFloat(-6,4,10), bFloat(-6,-3,10), bFloat(6,-3,10), bFloat(0,0,-1), 100);
		paredIzq = new poligonoComplejo(bFloat(-6,4,1), bFloat(-6,-3,1), bFloat(-6,-3,11), bFloat(1,0,0), 100);
		paredDer = new poligonoComplejo(bFloat(6,-3,1), bFloat(6,-3,10), bFloat(6,4,10), bFloat(-1,0,0), 100);
		techo = new poligonoComplejo(bFloat(-6,4,1), bFloat(6,4,1), bFloat(6,4,10), bFloat(0,-1,0), 100);
		suelo = new poligonoComplejo(bFloat(-6,-3,10), bFloat(6,-3,10), bFloat(6,-3,1), bFloat(0,1,0), 100);
		puerta = new poligonoComplejo(bFloat(-1,-3, 1.05), bFloat(1,-3, 1.05), bFloat(1, 1.5, 1.05), bFloat(0, 0, 1), 100);

		cuadro1 = new poligonoComplejo(bFloat(-4.7, 2.1, 1.05), bFloat(-4.7, 0.9, 1.05), bFloat(-2.3, 0.9, 1.05), bFloat(0, 0, 1), 100);
		cuadro2 = new poligonoComplejo(bFloat(2.3, 2.1, 1.05), bFloat(2.3, 0.9, 1.05), bFloat(4.7, 0.9, 1.05), bFloat(0, 0, 1), 100);

		pintura1 = new igvTextura("texturas/estrellas.bmp");
		pintura2 = new igvTextura("texturas/mirada.bmp");
		pintura3 = new igvTextura("texturas/playa.bmp");
		pintura4 = new igvTextura("texturas/planeta.bmp");
		_isBuilt = true;
	}
}

void Museo::visualizar() {

	construir();

	if (_salaPrincipal) luzMuseo->aplicar();
	else luzMuseo2->aplicar();

	glPushMatrix();
	matParedFrontal->aplicar();
	paredFrontal->visualizar(); // pared frontal museo
	paredTrasera->visualizar(); // pared trasera museo
	glPopMatrix();

	glPushMatrix();
	matParedLateral->aplicar();
	paredIzq->visualizar(); // pared izquierda museo
	paredDer->visualizar(); // pared derecha museo
	glPopMatrix();

	glPushMatrix();
	matSupInf->aplicar();
	techo->visualizar(); // pared techo museo
	suelo->visualizar(); // pared suelo museo
	glPopMatrix();

	glPushMatrix();
	matPuerta->aplicar();
	puerta->visualizar(); // puerta
	glPopMatrix();

	glPushMatrix();
	matMarco->aplicar();
	if(_salaPrincipal) pintura1->aplicar();
	else pintura3->aplicar();
	cuadro1->visualizar(); // cuadro 1
	if(_salaPrincipal) pintura2->aplicar();
	else pintura4->aplicar();
	cuadro2->visualizar(); // cuadro 2
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

}