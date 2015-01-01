#include "poligonoComplejo.h"

poligonoComplejo::poligonoComplejo(bFloat si, bFloat ii, bFloat id, bFloat dirNormal, unsigned int comp) : complejidad(comp) {

	const int tam = 4*complejidad*complejidad;

	puntos = new float[3*tam];
	normales = new float[3*tam];
	puntosTex = new float[2*tam];
	indice = new unsigned int[tam];

	unsigned int cont = 0;
	unsigned int cont2 = 0;
	unsigned int cont3 = 0;

	for(unsigned int x=0; x<complejidad; ++x){
		for(unsigned int y=0; y<complejidad; ++y) {

			puntos[cont3] = ii[0] + (id[0]-ii[0])*((x)/complejidad);
			puntos[cont3+1] = ii[1] + (id[1]-ii[1])*((x)/complejidad);
			puntos[cont3+2] = ii[2] + (id[2]-ii[2])*((x)/complejidad);
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = x/complejidad;
			puntosTex[cont2+1] = y/complejidad;
			cont2 += 2;
			indice[cont] = cont++;
			puntos[cont3] = ii[0] + (id[0]-ii[0])*((x+1)/complejidad);
			puntos[cont3+1] = ii[1] + (id[1]-ii[1])*((x+1)/complejidad);
			puntos[cont3+2] = ii[2] + (id[2]-ii[2])*((x+1)/complejidad);
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = x+1/complejidad;
			puntosTex[cont2+1] = y/complejidad;
			cont2 += 2;
			indice[cont] = cont++;
			puntos[cont3] = ii[0] + (id[0]-ii[0])*((x+1)/complejidad) + (si[0]-ii[0])*((y+1)/complejidad);
			puntos[cont3+1] = ii[1] + (id[1]-ii[1])*((x+1)/complejidad) + (si[1]-ii[1])*((y+1)/complejidad);
			puntos[cont3+2+1] = ii[2] + (id[2]-ii[2])*((x+1)/complejidad) + (si[2]-ii[2])*((y+1)/complejidad);
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = x+1/complejidad;
			puntosTex[cont2+1] = y+1/complejidad;
			cont2 += 2;
			indice[cont] = cont++;
			puntos[cont3] = ii[0] + (si[0]-ii[0])*((y+1)/complejidad);
			puntos[cont3+1] = ii[1] + (si[1]-ii[1])*((y+1)/complejidad);
			puntos[cont3+2] = ii[2] + (si[2]-ii[2])*((y+1)/complejidad);
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = x/complejidad;
			puntosTex[cont2+1] = y+1/complejidad;
			cont2 += 2;
			indice[cont] = cont++;

		}
	}

}

poligonoComplejo::~poligonoComplejo(){
	if(puntos) delete [] puntos;
	if(normales) delete [] normales;
	if(puntosTex) delete [] puntosTex;
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
