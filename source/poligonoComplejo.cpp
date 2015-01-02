#include "poligonoComplejo.h"

poligonoComplejo::poligonoComplejo(bFloat si, bFloat ii, bFloat id, bFloat dirNormal, unsigned int comp) : complejidad(comp) {

	unsigned int tam = 4*complejidad*complejidad;

	puntos = new float[3*tam];
	normales = new float[3*tam];
	puntosTex = new float[2*tam];
	indice = new GLubyte[tam];

	unsigned int cont = 0;
	unsigned int cont2 = 0;
	unsigned int cont3 = 0;

	float distancia_hor[3];
	float distancia_ver[3];

	for(unsigned int i = 0; i<3; ++i){
		distancia_hor[i] = id[i] - ii[i];
		distancia_ver[i] = si[i] - ii[i];
	}

	for(unsigned int x=0; x<complejidad; ++x){

		for(unsigned int y=0; y<complejidad; ++y) {

			puntos[cont3] = ii[0] + distancia_hor[0] * (float(x)/float(complejidad)) + distancia_ver[0] * (float(y)/float(complejidad));
			puntos[cont3+1] = ii[1] + distancia_hor[1] * (float(x)/float(complejidad)) + distancia_ver[1] * (float(y)/float(complejidad));
			puntos[cont3+2] = ii[2] + distancia_hor[2] * (float(x)/float(complejidad)) + distancia_ver[2] * (float(y)/float(complejidad));
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = float(x)/float(complejidad);
			puntosTex[cont2+1] = float(y)/float(complejidad);
			cont2 += 2;
			indice[cont] = cont++;

			puntos[cont3] = ii[0] + distancia_hor[0] * ((float(x)+1)/float(complejidad)) + distancia_ver[0] * (float(y)/float(complejidad));
			puntos[cont3+1] = ii[1] + distancia_hor[1] * ((float(x)+1)/float(complejidad)) + distancia_ver[1] * (float(y)/float(complejidad));
			puntos[cont3+2] = ii[2] + distancia_hor[2] * ((float(x)+1)/float(complejidad)) + distancia_ver[2] * (float(y)/float(complejidad));
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = (float(x)+1)/float(complejidad);
			puntosTex[cont2+1] = float(y)/float(complejidad);
			cont2 += 2;
			indice[cont] = cont++;

			puntos[cont3] = ii[0] + distancia_hor[0] * ((float(x)+1)/float(complejidad)) + distancia_ver[0] * ((float(y)+1)/float(complejidad));
			puntos[cont3+1] = ii[1] + distancia_hor[1] * ((float(x)+1)/float(complejidad)) + distancia_ver[1] * ((float(y)+1)/float(complejidad));
			puntos[cont3+2] = ii[2] + distancia_hor[2] * ((float(x)+1)/float(complejidad)) + distancia_ver[2] * ((float(y)+1)/float(complejidad));
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = (float(x)+1)/float(complejidad);
			puntosTex[cont2+1] = (float(y)+1)/float(complejidad);
			cont2 += 2;
			indice[cont] = cont++;

			puntos[cont3] = ii[0] + distancia_hor[0] * (float(x)/float(complejidad)) + distancia_ver[0] * ((float(y)+1)/float(complejidad));
			puntos[cont3+1] = ii[1] + distancia_hor[1] * (float(x)/float(complejidad)) + distancia_ver[1] * ((float(y)+1)/float(complejidad));
			puntos[cont3+2] = ii[2] + distancia_hor[2] * (float(x)/float(complejidad)) + distancia_ver[2] * ((float(y)+1)/float(complejidad));
			normales[cont3] = dirNormal[0];
			normales[cont3+1] = dirNormal[1];
			normales[cont3+2] = dirNormal[2];
			cont3 += 3;
			puntosTex[cont2] = float(x)/float(complejidad);
			puntosTex[cont2+1] = (float(y)+1)/float(complejidad);
			cont2 += 2;
			indice[cont] = cont++;

		}
	}

}

poligonoComplejo::~poligonoComplejo(){
	delete [] puntos;
	delete [] normales;
	delete [] puntosTex;
	delete [] indice;
}

void poligonoComplejo::visualizar(){
	glShadeModel(GL_SMOOTH);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, puntos);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normales);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, puntosTex);

	glDrawElements(GL_QUADS, 4*complejidad*complejidad, GL_UNSIGNED_BYTE, indice);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}