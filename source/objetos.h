#ifndef __OBJETOS
#define __OBJETOS

#include "museo.h"
#include "muñeco.h"
#include "cuadro.h"

class igvEscena3D;

class Objeto {
	friend class igvEscena3D;
protected:
	// Atributos
	int _seleccionado;

	// Objetos
	Museo* museo;
	Muñeco* muñeco;
	Cuadro* cuadro;
public:

	Objeto();
	~Objeto();

	void setSeleccionado(int seleccionado);
	void setSalaPrincipal(bool salaPrincipal);
	bool getSalaPrincipal();

	void visualizaMuseo();
	void visualizaMuñeco();
	void visualizaCuadro();

};

#endif
