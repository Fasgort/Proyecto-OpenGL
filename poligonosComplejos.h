#ifndef __POLIGONOSCOMPLEJOS
#define __POLIGONOSCOMPLEJOS

#include <GL/glut.h>

void creaRectangulo(bFloat si, bFloat ii, bFloat id, bFloat dirNormal){

	const int complejidad = 5;
	const int tam = 4*complejidad*complejidad;

	GLfloat puntos[tam][3];
	GLint normales[tam][3];
	GLubyte indice[tam];

	unsigned int cont = 0;

	for(unsigned int x=0; x<complejidad; ++x){
		for(unsigned int y=0; y<complejidad; ++y) {

			puntos[cont][0] = ii[0] + (id[0]-ii[0])*((x)/complejidad);
			puntos[cont][1] = ii[1] + (id[1]-ii[1])*((x)/complejidad);
			puntos[cont][2] = ii[2] + (id[2]-ii[2])*((x)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			indice[cont] = cont++;
			puntos[cont][0] = ii[0] + (id[0]-ii[0])*((x+1)/complejidad);
			puntos[cont][1] = ii[1] + (id[1]-ii[1])*((x+1)/complejidad);
			puntos[cont][2] = ii[2] + (id[2]-ii[2])*((x+1)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			indice[cont] = cont++;
			puntos[cont][0] = ii[0] + (id[0]-ii[0])*((x+1)/complejidad) + (si[0]-ii[0])*((y+1)/complejidad);
			puntos[cont][1] = ii[1] + (id[1]-ii[1])*((x+1)/complejidad) + (si[1]-ii[1])*((y+1)/complejidad);
			puntos[cont][2] = ii[2] + (id[2]-ii[2])*((x+1)/complejidad) + (si[2]-ii[2])*((y+1)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			indice[cont] = cont++;
			puntos[cont][0] = ii[0] + (si[0]-ii[0])*((y+1)/complejidad);
			puntos[cont][1] = ii[1] + (si[1]-ii[1])*((y+1)/complejidad);
			puntos[cont][2] = ii[2] + (si[2]-ii[2])*((y+1)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			indice[cont] = cont++;

		}
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, puntos);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normales);

	glDrawElements(GL_QUADS, cont, GL_UNSIGNED_BYTE, indice);

	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}


#endif