#ifndef __CAJACOMBINACION
#define __CAJACOMBINACION

#include <GL/glut.h>

#include "nombres.h"
#include "poligonoComplejo.h"
#include "igvTextura.h"
#include <bitset>

class Objeto;

class cajaCombinacion {
	friend class Objeto;

	bool _isBuilt; // Indica si el objeto ha sido creado
	std::bitset<9> _combinacion;
	bool _abierto; // Indica si la caja ha sido abierta
	bool _sorpresa; // Es sorpresa

	// cajetin figura exterior
	poligonoComplejo* top;
	poligonoComplejo* bottom;
	poligonoComplejo* back;
	poligonoComplejo* left;
	poligonoComplejo* right;
	poligonoComplejo* doorClosed;
	poligonoComplejo* doorOpened;

	// cajetin figura interior
	poligonoComplejo* top2;
	poligonoComplejo* bottom2;
	poligonoComplejo* back2;
	poligonoComplejo* left2;
	poligonoComplejo* right2;
	poligonoComplejo* doorClosed2;
	poligonoComplejo* doorOpened2;

	// botones
	poligonoComplejo* boton1;
	poligonoComplejo* boton2;
	poligonoComplejo* boton3;
	poligonoComplejo* boton4;
	poligonoComplejo* boton5;
	poligonoComplejo* boton6;
	poligonoComplejo* boton7;
	poligonoComplejo* boton8;
	poligonoComplejo* boton9;
	poligonoComplejo* botonEnter;
	poligonoComplejo* botonSorpresa;

	// texturas botones
	igvTextura* tboton1;
	igvTextura* tboton2;
	igvTextura* tboton3;
	igvTextura* tboton4;
	igvTextura* tboton5;
	igvTextura* tboton6;
	igvTextura* tboton7;
	igvTextura* tboton8;
	igvTextura* tboton9;
	igvTextura* tbotonEnter;

	// Metodo propio del objeto
	void construir();

public:

	cajaCombinacion();
	~cajaCombinacion();

	void pulsaBoton(int boton);
	void cerrarCaja();

	void visualizar();

};

#endif
