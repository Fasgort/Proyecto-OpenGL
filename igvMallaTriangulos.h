#ifndef __IGVMALLATRIANGULOS
#define __IGVMALLATRIANGULOS

#include <GL/glut.h>

class igvMallaTriangulos {
	protected:
		// Atributos

		long int num_vertices; // número de vértices de la malla de triángulos
		float *vertices; // array con las (num_vertices * 3) coordenadas de los vértices
		float *normales; // array con las (num_vertices * 3) coordenadas de la normal a cada vértice (sólo para la generación de la esfera)

    float *coor_tex; // array con las (num_vertices * 2) coordenadas de textura para cada vértice (sólo para la generación de la esfera)

		long int num_triangulos; // número de triángulos de la malla de triángulos
		unsigned int *triangulos; // array con los (num_triangulos * 3) índices a los vértices de cada triángulo

	public:
		// Constructor y destructor
		// constructor de la malla de triángulos genérica
		igvMallaTriangulos(long int _num_vertices, float *_vertices, long int _num_triangulos, long int *_triangulos);

		// constructor que genera genera una malla de triángulos a partir de un array de coordenadas X, Y, Z de los vértices de los triángulos de la malla
		igvMallaTriangulos(long int _num_coordenadas, float *_coordenadas);


		~igvMallaTriangulos();

		// Métodos
		// método con las llamadas OpenGL para visualizar la malla de triángulos
    void visualizar();
};

#endif
