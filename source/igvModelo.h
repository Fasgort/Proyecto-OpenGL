#ifndef __IGVMODELO
#define __IGVMODELO

#include <GL/glut.h>

#include "igvPunto3D.h"

typedef enum {
	IGV_ESFERA
} tipoModelo;

class igvModelo {

	protected:
		// atributos
		
		tipoModelo tipo; // modelo almacenado

		long int num_coordenadas; // número de coordenadas del modelo
		
		float *coordenadas; // coordenadas del modelo


		// Metodos

	public:
		// Constructor y destructor
		igvModelo(tipoModelo tipo); // crea un modelo del tipo indicado
		~igvModelo();

		// Metodos
		// devuelve el número de coordenadas del modelo
		long int getNum_coordenadas();

		// devuelve el PUNTERO a las coordenadas del modelo
		float *getCoordenadas();
};

#endif

