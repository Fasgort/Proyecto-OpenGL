#ifndef __IGVMALLATRIANGULOS
#define __IGVMALLATRIANGULOS

#include <GL/glut.h>

class igvMallaTriangulos {
	protected:
		// Atributos

		long int num_vertices; // n�mero de v�rtices de la malla de tri�ngulos
		float *vertices; // array con las (num_vertices * 3) coordenadas de los v�rtices
		float *normales; // array con las (num_vertices * 3) coordenadas de la normal a cada v�rtice (s�lo para la generaci�n de la esfera)

    float *coor_tex; // array con las (num_vertices * 2) coordenadas de textura para cada v�rtice (s�lo para la generaci�n de la esfera)

		long int num_triangulos; // n�mero de tri�ngulos de la malla de tri�ngulos
		unsigned int *triangulos; // array con los (num_triangulos * 3) �ndices a los v�rtices de cada tri�ngulo

	public:
		// Constructor y destructor
		// constructor de la malla de tri�ngulos gen�rica
		igvMallaTriangulos(long int _num_vertices, float *_vertices, long int _num_triangulos, long int *_triangulos);

		// constructor que genera genera una malla de tri�ngulos a partir de un array de coordenadas X, Y, Z de los v�rtices de los tri�ngulos de la malla
		igvMallaTriangulos(long int _num_coordenadas, float *_coordenadas);


		~igvMallaTriangulos();

		// M�todos
		// m�todo con las llamadas OpenGL para visualizar la malla de tri�ngulos
    void visualizar();
};

#endif
