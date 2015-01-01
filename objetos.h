#ifndef __OBJETOS
#define __OBJETOS

#include "museo.h"
#include "muneco.h"

class igvEscena3D;
class Museo;
class Muneco;

class Objeto {
	friend class igvEscena3D;
protected:
	//Atributos
	int _seleccionado;

	// Objetos
	Museo museo;
	Muneco muneco;
public:

	Objeto();
	~Objeto();

	void set_seleccionado(int seleccionado);
	void set_salaPrincipal(bool salaPrincipal);

	void visualizaMuseo();
	void visualizaMuneco();

};

#endif
