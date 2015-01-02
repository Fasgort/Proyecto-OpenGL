#include "objetos.h"

Objeto::Objeto() {
	_seleccionado = -1;
	museo = new Museo();
	muneco = new Muneco();
}

Objeto::~Objeto() {
	delete museo;
	delete muneco;
}

void Objeto::setSeleccionado(int seleccionado) {muneco->_seleccionado = _seleccionado = seleccionado;}
void Objeto::setSalaPrincipal(bool salaPrincipal){museo->_salaPrincipal = salaPrincipal;}
bool Objeto::getSalaPrincipal(){return museo->_salaPrincipal;}

void Objeto::visualizaMuseo(){museo->visualizar();}
void Objeto::visualizaMuneco(){muneco->visualizar();}

