#include "objetos.h"

Objeto::Objeto() {
	_seleccionado = -1;
}

Objeto::~Objeto() {}

void Objeto::set_seleccionado(int seleccionado) {
	_seleccionado = seleccionado;
	muneco._seleccionado = seleccionado;
}

void Objeto::set_salaPrincipal(bool salaPrincipal){museo._salaPrincipal = salaPrincipal;}

void Objeto::visualizaMuseo(){museo.visualizar();}
void Objeto::visualizaMuneco(){muneco.visualizar();}

