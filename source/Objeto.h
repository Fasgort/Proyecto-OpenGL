#ifndef __OBJETO
#define __OBJETO

enum {
	NO_SELECCIONABLE,
	P_BOXEADOR, BRAZO_1, BRAZO_2, PUÑO_1, PUÑO_2, // boxeador
	P_HELICE, PALANCA, // helice
	ESFERAR, ESFERAB, // esferas
	BOTON_1, BOTON_2, BOTON_3, BOTON_4, BOTON_5, BOTON_6, BOTON_7, BOTON_8, BOTON_9, BOTON_ENTER, BOTON_SORPRESA, PUERTA_CAJA // caja combinacion
};

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
