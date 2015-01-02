#include "objetos.h"

Objeto::Objeto() {
	_seleccionado = -1;
	museo = new Museo();
	cuadro = new Cuadro();
	figura1 = new Boxeador();
	figura2 = new Helice();
	figura3 = new Boxeador();
	figura4 = new Boxeador();
}

Objeto::~Objeto() {
	delete museo;
	delete cuadro;
	delete figura1;
	delete figura2;
	delete figura3;
	delete figura4;
}

void Objeto::setSeleccionado(int seleccionado) {figura1->_seleccionado = figura2->_seleccionado = figura3->_seleccionado = figura4->_seleccionado = _seleccionado = seleccionado;}
void Objeto::setSalaPrincipal(bool salaPrincipal){cuadro->_salaPrincipal = museo->_salaPrincipal = salaPrincipal;}
bool Objeto::getSalaPrincipal(){return museo->_salaPrincipal;}

void Objeto::visualizaMuseo(){museo->visualizar();}
void Objeto::visualizaCuadro(){cuadro->visualizar();}
void Objeto::visualizaFigura1(){figura1->visualizar();}
void Objeto::visualizaFigura2(){figura2->visualizar();}
void Objeto::visualizaFigura3(){figura3->visualizar();}
void Objeto::visualizaFigura4(){figura4->visualizar();}
