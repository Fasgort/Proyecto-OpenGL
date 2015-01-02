#include "objetos.h"

Objeto::Objeto() {
	_seleccionado = -1;
	museo = new Museo();
	muneco = new Muneco();
	cuadro = new Cuadro();
}

Objeto::~Objeto() {
	delete museo;
	delete muneco;
	delete cuadro;
}

void Objeto::setSeleccionado(int seleccionado) {muneco->_seleccionado = _seleccionado = seleccionado;}
void Objeto::setSalaPrincipal(bool salaPrincipal){cuadro->_salaPrincipal = museo->_salaPrincipal = salaPrincipal;}
bool Objeto::getSalaPrincipal(){return museo->_salaPrincipal;}

void Objeto::visualizaMuseo(){museo->visualizar();}
void Objeto::visualizaMuneco(){muneco->visualizar();}
void Objeto::visualizaCuadro(){cuadro->visualizar();}
