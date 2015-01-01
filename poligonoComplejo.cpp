#include "poligonoComplejo.h"

poligonoComplejo::poligonoComplejo(bFloat si, bFloat ii, bFloat id, bFloat dirNormal, unsigned int comp) : complejidad(comp) {

	const int tam = 4*complejidad*complejidad;

	puntos = new GLfloat*[tam];
	normales = new GLfloat*[tam];
	puntosTex = new GLfloat*[tam];
	indice = new GLubyte[tam];

	for(int i=0; i<tam; ++i) {
		puntos[i] = new GLfloat[3];
		normales[i] = new GLfloat[3];
		puntosTex[i] = new GLfloat[2];
	}

	unsigned int cont = 0;

	for(unsigned int x=0; x<complejidad; ++x){
		for(unsigned int y=0; y<complejidad; ++y) {

			puntos[cont][0] = ii[0] + (id[0]-ii[0])*((x)/complejidad);
			puntos[cont][1] = ii[1] + (id[1]-ii[1])*((x)/complejidad);
			puntos[cont][2] = ii[2] + (id[2]-ii[2])*((x)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			puntosTex[cont][0] = x/complejidad;
			puntosTex[cont][1] = y/complejidad;
			indice[cont] = cont++;
			puntos[cont][0] = ii[0] + (id[0]-ii[0])*((x+1)/complejidad);
			puntos[cont][1] = ii[1] + (id[1]-ii[1])*((x+1)/complejidad);
			puntos[cont][2] = ii[2] + (id[2]-ii[2])*((x+1)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			puntosTex[cont][0] = x+1/complejidad;
			puntosTex[cont][1] = y/complejidad;
			indice[cont] = cont++;
			puntos[cont][0] = ii[0] + (id[0]-ii[0])*((x+1)/complejidad) + (si[0]-ii[0])*((y+1)/complejidad);
			puntos[cont][1] = ii[1] + (id[1]-ii[1])*((x+1)/complejidad) + (si[1]-ii[1])*((y+1)/complejidad);
			puntos[cont][2] = ii[2] + (id[2]-ii[2])*((x+1)/complejidad) + (si[2]-ii[2])*((y+1)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			puntosTex[cont][0] = x+1/complejidad;
			puntosTex[cont][1] = y+1/complejidad;
			indice[cont] = cont++;
			puntos[cont][0] = ii[0] + (si[0]-ii[0])*((y+1)/complejidad);
			puntos[cont][1] = ii[1] + (si[1]-ii[1])*((y+1)/complejidad);
			puntos[cont][2] = ii[2] + (si[2]-ii[2])*((y+1)/complejidad);
			normales[cont][0] = dirNormal[0];
			normales[cont][1] = dirNormal[1];
			normales[cont][2] = dirNormal[2];
			puntosTex[cont][0] = x/complejidad;
			puntosTex[cont][1] = y+1/complejidad;
			indice[cont] = cont++;

		}
	}

}

poligonoComplejo::~poligonoComplejo(){
	if(puntos) {
		for(int i = 0; i<=2; ++i) delete puntos[i];
		delete [] puntos;
	}
	if(normales) {
		for(int i = 0; i<=2; ++i) delete normales[i];
		delete [] normales;
	}
	if(puntosTex) {
		for(int i = 0; i<=1; ++i) delete puntosTex[i];
		delete [] puntosTex;
	}
	if(indice) delete [] indice;
}

void poligonoComplejo::visualizar(){
	glShadeModel(GL_SMOOTH);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, puntos);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normales);

	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//glTexCoordPointer(2, GL_FLOAT, 0, puntosTex);

	glDrawElements(GL_QUADS, 4*complejidad*complejidad, GL_UNSIGNED_BYTE, indice);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
