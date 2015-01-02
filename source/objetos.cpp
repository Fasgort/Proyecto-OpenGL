#include "objetos.h"

Objeto::Objeto() {
	_seleccionado = -1;
	museo = new Museo();
	mu�eco = new Mu�eco();
	cuadro = new Cuadro();
}

Objeto::~Objeto() {
	delete museo;
	delete mu�eco;
	delete cuadro;
}

void Objeto::setSeleccionado(int seleccionado) {mu�eco->_seleccionado = _seleccionado = seleccionado;}
void Objeto::setSalaPrincipal(bool salaPrincipal){cuadro->_salaPrincipal = museo->_salaPrincipal = salaPrincipal;}
bool Objeto::getSalaPrincipal(){return museo->_salaPrincipal;}

void Objeto::visualizaMuseo(){museo->visualizar();}
void Objeto::visualizaMu�eco(){mu�eco->visualizar();}
void Objeto::visualizaCuadro(){cuadro->visualizar();}
