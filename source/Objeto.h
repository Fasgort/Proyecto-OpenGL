#ifndef __OBJETO
#define __OBJETO

class Objeto {
protected:

	// Atributos
	int _seleccionado;
	bool _isBuilt;

	// Métodos privados
	virtual void deconstruir() = 0;
	virtual void construir() = 0;

public:

	virtual void visualizar() = 0;

	void setSeleccionado(int seleccionado){_seleccionado = seleccionado;};

};

#endif
