#ifndef __OBJETOS
#define __OBJETOS

#include "museo.h"
#include "muneco.h"

class igvEscena3D;

class Objeto {
	friend class igvEscena3D;
protected:
	// Atributos
	int _seleccionado;

	// Objetos
	Museo museo;
	Muneco muneco;
public:

	Objeto();
	~Objeto();

	void setSeleccionado(int seleccionado);
	void setSalaPrincipal(bool salaPrincipal);
	bool getSalaPrincipal();

	void visualizaMuseo();
	void visualizaMuneco();

};

#endif
