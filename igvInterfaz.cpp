#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"
#include <iostream>
using namespace std;
extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
// ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
	ampliado = false;
}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	// crear c�maras
	interfaz.camara.set(IGV_PARALELA, igvPunto3D(3.0,2.0,4),igvPunto3D(0,0,0),igvPunto3D(0,1.0,0),
		-1*4.5, 1*4.5, -1*4.5, 1*4.5, -1*3, 200);
}

void igvInterfaz::configura_entorno(int argc, char** argv,
									int _ancho_ventana, int _alto_ventana,
									int _pos_X, int _pos_Y,
									string _titulo){
										// inicializaci�n de las variables de la interfaz																	
										ancho_ventana = _ancho_ventana;
										alto_ventana = _alto_ventana;

										// inicializaci�n de la ventana de visualizaci�n
										glutInit(&argc, argv);
										glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
										glutInitWindowSize(_ancho_ventana,_alto_ventana);
										glutInitWindowPosition(_pos_X,_pos_Y);
										glutCreateWindow(_titulo.c_str());

										glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
										glClearColor(1.0,1.0,1.0,0.0); // establece el color de fondo de la ventana

										glEnable(GL_LIGHTING); // activa la iluminacion de la escena
										glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

										glEnable(GL_TEXTURE_2D); // activa el uso de texturas

										crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutSpecialFunc(int key, int x, int y) {
	// manejo de las teclas especiales del teclado

	switch(key)	{
	case GLUT_KEY_UP:
		if(interfaz.camara.P0[0] != 0 && interfaz.camara.P0[1] < 1.5 && interfaz.ampliado == false) {
			interfaz.camara.P0[1] += 1.5;
			interfaz.camara.r[1] += 1.5;
		}
		break;
	case GLUT_KEY_DOWN:
		if(interfaz.camara.P0[0] != 0 && interfaz.camara.P0[1] > -1.5 && interfaz.ampliado == false) {
			interfaz.camara.P0[1] -= 1.5;
			interfaz.camara.r[1] -= 1.5;
		}
		break;
	case GLUT_KEY_LEFT:
		if(interfaz.camara.P0[0] > -3 && interfaz.ampliado == false) {
			interfaz.camara.P0[0] -= 3;
			interfaz.camara.r[0] -= 3;
			interfaz.camara.P0[1] = 0;
			interfaz.camara.r[1] = 0;
		}
		break;
	case GLUT_KEY_RIGHT:
		if(interfaz.camara.P0[0] < 3 && interfaz.ampliado == false) {
			interfaz.camara.P0[0] += 3;
			interfaz.camara.r[0] += 3;
			interfaz.camara.P0[1] = 0;
			interfaz.camara.r[1] = 0;
		}
		break;
	}

	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
	case ' ':
		if(interfaz.ampliado == false && interfaz.camara.P0[1] != 0){
			interfaz.camara.P0[2] -= 2;
			interfaz.ampliado = true;
		}
		else if (interfaz.ampliado == true) {
			interfaz.camara.P0[2] += 2;
			interfaz.ampliado = false;
		}
		break;
	case 'e': // activa/desactiva la visualizacion de los ejes
		interfaz.escena.set_ejes(interfaz.escena.get_ejes()?false:true);
		break;
	case 27: // tecla de escape para SALIR
		exit(1);
		break;
	}
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
	// dimensiona el viewport al nuevo ancho y alto de la ventana
	// guardamos valores nuevos de la ventana de visualizacion
	interfaz.set_ancho_ventana(w);
	interfaz.set_alto_ventana(h);

	// establece los par�metros de la c�mara y de la proyecci�n
	interfaz.camara.tipo = IGV_PERSPECTIVA;
	interfaz.camara.P0 = igvPunto3D(0, 0, 5.5);
	interfaz.camara.r = igvPunto3D(0, 0, 1);
	interfaz.camara.V = igvPunto3D(0, 1, 0);
	interfaz.camara.angulo = 120;
	interfaz.camara.raspecto = 1;
	interfaz.camara.znear = 0.001;
	interfaz.camara.zfar = 15;
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
	GLuint lista_impactos[1024]; // array con la lista de impactos cuando se visualiza en modo selecci�n

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

	// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

	// Apartado D: antes de aplicar las transformaciones de c�mara y proyecci�n hay comprobar el modo,
	if (interfaz.modo == IGV_SELECCIONAR) {
		// Apartado D: si se est� seleccionando se pasa a modo selecci�n de OpenGL y se pasan los par�metros de selecci�n a la c�mara
		interfaz.inicia_seleccion(1024,lista_impactos);
	}

	// establece los par�metros de la c�mara y de la proyecci�n
	interfaz.camara.aplicar();

	//visualiza la escena
	interfaz.escena.visualizar();

	if (interfaz.modo == IGV_SELECCIONAR) {
		// Apartado D: salir del modo seleccion y procesar la lista de impactos
		interfaz.finaliza_seleccion(1024,lista_impactos); 
	}	else {
		// refresca la ventana
		glutSwapBuffers();
	}
}

void igvInterfaz::set_glutMouseFunc(GLint boton,GLint estado,GLint x,GLint y) {

	// Apartado D: comprobar que se ha pulsado el bot�n izquierdo 
	if(boton == GLUT_LEFT_BUTTON){

		// Apartado D: guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
		// pasar a modo IGV_SELECCIONAR
		if(estado == GLUT_DOWN) {
			interfaz.modo = IGV_SELECCIONAR;
			interfaz.boton_retenido = true;
		} else if(estado == GLUT_UP) interfaz.boton_retenido = false;

		// Apartado D: guardar el pixel pulsado
		interfaz.cursorX = x;
		interfaz.cursorY = y;

		// Apartado D: renovar el contenido de la ventana de vision
		glutPostRedisplay();

	}

}

void igvInterfaz::set_glutMotionFunc(GLint x,GLint y) {

	// Apartado E: si el bot�n est� retenido y hay alg�n objeto seleccionado,
	// comprobar el objeto seleccionado y la posici�n del rat�n y actualizar
	// convenientemente el grado de libertad del objeto correspondiente 


	// Apartado E: guardar la nueva posici�n del rat�n 
	interfaz.cursorX = x;
	interfaz.cursorY = y;

	// Apartado E: renovar el contenido de la ventana de vision 
	glutPostRedisplay();

}

void igvInterfaz::inicia_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {
	// Apartado D: establecer d�nde se van a almacenar los impactos
	glSelectBuffer(TAMANO_LISTA_IMPACTOS, lista_impactos);


	// Apartado D: pasar a modo de seleccion de OpenGL
	glRenderMode(GL_SELECT);

	// Apartado D: establecer la camara en modo seleccion con los par�metros necesarios para realizar la selecci�n
	// para el alto y el ancho de la ventana de selecci�n probar diferentes tama�os y comprobar la amplitud de la selecci�n
	interfaz.camara.establecerSeleccion(10,10,interfaz.camara.cursorX,interfaz.camara.cursorY);
}

int procesar_impactos(int numero_impactos,GLuint *lista_impactos) {
	/* Apartado D: esta funci�n debe devolver el c�digo del objeto seleccionado, que no tiene porque coincidir con el nombre
	asignado con la pila de nombres, y si se han utilizado nombres jer�rquicos hay que tener en cuenta que
	esta funci�n s�lo devolver un �nico c�digo */

	GLuint minZ = 4294967295;
	unsigned int posArray = 0;
	int codigo = -1;

	// Apartado D: recorrer la lista de impactos con numero_impactos impactos,
	// guardar el m�s pr�ximo al observador (minima Z)
	// para empezar, considerar que la m�nima Z tiene un valor de 0xffffffff (el tope del tipo GLuint)

	for(int cont = 0; cont < numero_impactos; ++cont) {
		unsigned int numNombres = lista_impactos[posArray++];
		if(lista_impactos[posArray] < minZ && numNombres != 0) minZ = lista_impactos[posArray];
		posArray += 2;
		codigo = lista_impactos[posArray];
		posArray += numNombres;
	}

	// Apartado D: a partir de la informaci�n del impacto con la m�nima Z, devolver el c�digo del objeto que le
	// corresponde: como la escena no se almacena en ninguna estructura de datos, para devolver el objeto seleccionado
	// utilizar aqu� directamente los nombres asignados a los objetos de la escena

	return codigo;
}

void igvInterfaz::finaliza_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {

	// Apartado D: volver a modo visualizacion OpenGL y obtener el n�mero de impactos 
	int numImpactos = glRenderMode(GL_RENDER);

	// Apartado D: si hay impactos pasar a procesarlos con la funcion int procesar_impactos(numero_impactos,lista_impactos);
	// obteniendo el objeto seleccionado, si lo hay
	if(numImpactos != 0) procesar_impactos(numImpactos, lista_impactos);

	// Apartado D: seleccion terminada, pasar a visualizaci�n normal
	interfaz.modo = IGV_VISUALIZAR;

	// Apartado D: establecer la camara en modo visualizaci�n
	interfaz.camara.establecerVisualizacion();

}

void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutSpecialFunc(set_glutSpecialFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
}
