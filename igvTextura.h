#ifndef __IGVTEXTURA
#define __IGVTEXTURA

#include <GL/glut.h>
#include <stdio.h>

#include "bmp.h"

class igvTextura {

protected:
	// Atributos
	unsigned int idTextura; // identificador de la textura
	unsigned int alto,  // alto de la textura
		ancho; // ancho de la textura

	// Metodos

public:
	// Constructores por defecto y destructor
	igvTextura(); // Textura ajedrez de 64 x 64 texeles
	igvTextura(char *fichero); // Textura cargada desde un fichero BMP
	~igvTextura();

	// Metodos
	void aplicar(void); // establece la textura como la textura activa
};

#endif

