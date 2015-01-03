#include "igvTextura.h"

// Metodos constructores y destructor
igvTextura::igvTextura() {isLoaded = false; _fichero = 0;}
igvTextura::igvTextura(char* fichero) {isLoaded = false; _fichero = fichero;}

void igvTextura::load() {
	unsigned int ancho = 64;
	unsigned int alto = 64;

	GLubyte textura[64][64][4];

	// almacena en el array textura una imagen con un tablero de ajedrez
	unsigned int i, j, c;
	for (i = 0; i < alto ; i++) {
		for (j = 0; j < ancho ; j++) {
			c = (((i&0x8) == 0) ^ (((j&0x8)) == 0)) * 255;
			textura[i][j][0] = (GLubyte) c;
			textura[i][j][1] = (GLubyte) c;
			textura[i][j][2] = (GLubyte) c;
			textura[i][j][3] = (GLubyte) 255;
		}
	}

	/* Apartado G: Añadir aquí el código para cargar la textura de ajedrez */
	/*
	- Generar el identificador de textura y asignarlo al atributo idTextura
	- Especificar la textura
	- Modo de aplicación de la textura
	- Parámetros de la textura: repetición y filtros
	*/

	// Genera identificador
	glGenTextures(1, &idTextura); 

	// Especifica textura
	glBindTexture(GL_TEXTURE_2D, idTextura);

	// Modo de aplicación
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);

	// Parámetros de la textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Carga la textura
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ancho, alto, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);

	isLoaded = true;
}

void igvTextura::load(char *fichero) {
	BITMAPINFO *BitmapInfo; /* Bitmap information */
	GLubyte *imagen;

	// carga en memoria el BMP almacenado en el fichero
	imagen=LoadDIBitmap(fichero,&BitmapInfo);

	unsigned int alto=(*BitmapInfo).bmiHeader.biHeight;
	unsigned int ancho=(*BitmapInfo).bmiHeader.biWidth;

	/* Apartado H: Añadir aquí el código para cargar como textura OpenGL el BMP imagen */
	/*
	- Generar el identificador de textura y asignarlo al atributo idTextura
	- Especificar la textura, asignádole como textura el array imagen
	- Modo de aplicación de la textura
	- Parámetros de la textura: repetición y filtros
	*/

	// Genera identificador
	glGenTextures(1, &idTextura); 

	// Especifica textura
	glBindTexture(GL_TEXTURE_2D, idTextura);

	// Modo de aplicación
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// Parámetros de la textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// Carga la textura
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ancho, alto, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imagen);

	delete BitmapInfo;
	delete imagen;

	isLoaded = true;
}

void igvTextura::aplicar() {
	if(!isLoaded) {
		if(!_fichero) load();
		else load(_fichero);
	}
	glBindTexture(GL_TEXTURE_2D, idTextura);
}

igvTextura::~igvTextura() {
	if(isLoaded) glDeleteTextures(1, &idTextura); 
}
