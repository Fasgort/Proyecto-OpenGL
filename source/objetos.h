#ifndef __OBJETOS
#define __OBJETOS

#include "museo.h"
#include "cuadro.h"
#include "boxeador.h"
#include "helice.h"
#include "esferasFlotantes.h"

class igvEscena3D;

class Objeto {
	friend class igvEscena3D;
protected:
	// Atributos
	int _seleccionado;

	// Objetos
	Museo* museo;
	Cuadro* cuadro;
	Boxeador* figura1;
	Helice* figura2;
	esferasFlotantes* figura3;
	Boxeador* figura4;
public:

	Objeto();
	~Objeto();

	void setSeleccionado(int seleccionado);
	void setSalaPrincipal(bool salaPrincipal);
	bool getSalaPrincipal();

	void visualizaMuseo();
	void visualizaCuadro();
	void visualizaFigura1();
	void visualizaFigura2();
	void visualizaFigura3();
	void visualizaFigura4();

};

#endif
