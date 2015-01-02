#ifndef __IGVTEXTURA
#define __IGVTEXTURA

#include <GL/glut.h>
#include <stdio.h>

#include "bmp.h"

class igvTextura {

protected:
	// Atributos
	unsigned int idTextura; // identificador de la textura
	bool isLoaded; // Indica si la textura ha sido cargada
	char* _fichero; // Nombre del fichero

public:
	// Constructores por defecto y destructor
	igvTextura();
	igvTextura(char *fichero);
	~igvTextura();

	// Metodos
	void load(); // Textura ajedrez
	void load(char *fichero); // Textura cargada desde un fichero BMP

	void aplicar(); // establece la textura como la textura activa
};

#endif

