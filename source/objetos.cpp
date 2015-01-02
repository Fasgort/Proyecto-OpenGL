#include "objetos.h"

Objeto::Objeto() {
	_seleccionado = -1;
	museo = new Museo();
	muñeco = new Muñeco();
	cuadro = new Cuadro();
}

Objeto::~Objeto() {
	delete museo;
	delete muñeco;
	delete cuadro;
}

void Objeto::setSeleccionado(int seleccionado) {muñeco->_seleccionado = _seleccionado = seleccionado;}
void Objeto::setSalaPrincipal(bool salaPrincipal){cuadro->_salaPrincipal = museo->_salaPrincipal = salaPrincipal;}
bool Objeto::getSalaPrincipal(){return museo->_salaPrincipal;}

void Objeto::visualizaMuseo(){museo->visualizar();}
void Objeto::visualizaMuñeco(){muñeco->visualizar();}
void Objeto::visualizaCuadro(){cuadro->visualizar();}
