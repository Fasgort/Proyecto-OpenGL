#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"

using namespace std;
extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
// ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
	ampliado = false;
	up = false;
	down = false;
	left = false;
	right = false;
}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	// crear cámaras
	interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(0, 0, 5.5),igvPunto3D(0, 0, 1),igvPunto3D(0, 1, 0), 90, 1, 0.001, 15);
}

void igvInterfaz::configura_entorno(int argc, char** argv,
									int _ancho_ventana, int _alto_ventana,
									int _pos_X, int _pos_Y,
									string _titulo){
										// inicialización de las variables de la interfaz																	
										ancho_ventana = _ancho_ventana;
										alto_ventana = _alto_ventana;

										// inicialización de la ventana de visualización
										glutInit(&argc, argv);
										glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
										glutInitWindowSize(_ancho_ventana,_alto_ventana);
										glutInitWindowPosition(_pos_X,_pos_Y);
										glutCreateWindow(_titulo.c_str());

										glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
										glClearColor(1.0,1.0,1.0,0.0); // establece el color de fondo de la ventana

										glEnable(GL_LIGHTING); // activa la iluminacion de la escena
										glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion
										glShadeModel(GL_SMOOTH);

										glEnable(GL_TEXTURE_2D); // activa el uso de texturas
										glEnable(GL_LIGHT0);
										glEnable(GL_LIGHT1);
										glEnable(GL_LIGHT2);
										glEnable(GL_LIGHT3);
										glEnable(GL_LIGHT4);

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
		} else if(!interfaz.up && interfaz.ampliado == true && interfaz.camara.P0[1] != 1.5) {
			if(interfaz.down) interfaz.camara.P0[1] -= 1.0;
			interfaz.camara.P0[1] += 2.0;
			if(interfaz.down) interfaz.down = false;
			else interfaz.up = true;
		}
		break;

	case GLUT_KEY_DOWN:
		if(interfaz.camara.P0[0] != 0 && interfaz.camara.P0[1] > -1.5 && interfaz.ampliado == false) {
			interfaz.camara.P0[1] -= 1.5;
			interfaz.camara.r[1] -= 1.5;
		} else if(!interfaz.down && interfaz.ampliado == true && interfaz.camara.P0[1] != 1.5) {
			if(interfaz.up) interfaz.camara.P0[1] -= 1.0;
			interfaz.camara.P0[1] -= 1.0;
			if(interfaz.up) interfaz.up = false;
			else interfaz.down = true;
		}
		break;

	case GLUT_KEY_LEFT:
		if(interfaz.camara.P0[0] > -3.5 && interfaz.ampliado == false) {
			interfaz.camara.P0[0] -= 3.5;
			interfaz.camara.r[0] -= 3.5;
			interfaz.camara.P0[1] = 0;
			interfaz.camara.r[1] = 0;
		} else if(!interfaz.left && interfaz.ampliado == true && interfaz.camara.P0[1] != 1.5) {
			interfaz.camara.P0[0] -= 2.0;
			if(interfaz.right) interfaz.right = false;
			else interfaz.left = true;
		}
		break;

	case GLUT_KEY_RIGHT:
		if(interfaz.camara.P0[0] < 3.5 && interfaz.ampliado == false) {
			interfaz.camara.P0[0] += 3.5;
			interfaz.camara.r[0] += 3.5;
			interfaz.camara.P0[1] = 0;
			interfaz.camara.r[1] = 0;
		} else if(!interfaz.right && interfaz.ampliado == true && interfaz.camara.P0[1] != 1.5) {
			interfaz.camara.P0[0] += 2.0;
			if(interfaz.left) interfaz.left = false;
			else interfaz.right = true;
		}
		break;

	}

	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {

	switch (key) {

	case ' ':
		if(interfaz.ampliado == false) {
			if (interfaz.camara.P0[1] != 0){
				if(interfaz.camara.P0[1] > 0) interfaz.camara.P0[2] -= 3.25;
				else interfaz.camara.P0[2] -= 1.5;
				interfaz.camara.r[2] = 2;
				interfaz.ampliado = true;
			} else if(interfaz.camara.P0[0] == 0) interfaz.escena.cambiarSalaPrincipal();
		} else {
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(0, 0, 5.5),igvPunto3D(0, 0, 1),igvPunto3D(0, 1, 0), 90, 1, 0.001, 15);
			interfaz.ampliado = false;
			interfaz.escena.set_seleccionado(-1);
		}
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

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
	GLuint lista_impactos[1024]; // array con la lista de impactos cuando se visualiza en modo selección

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

	// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

	// Apartado D: antes de aplicar las transformaciones de cámara y proyección hay comprobar el modo,
	if (interfaz.modo == IGV_SELECCIONAR) {
		// Apartado D: si se está seleccionando se pasa a modo selección de OpenGL y se pasan los parámetros de selección a la cámara
		interfaz.inicia_seleccion(1024,lista_impactos);
	}

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();

	//visualiza la escena
	interfaz.escena.visualizar();

	if (interfaz.modo == IGV_SELECCIONAR) {
		// Apartado D: salir del modo seleccion y procesar la lista de impactos
		interfaz.finaliza_seleccion(1024,lista_impactos); 
	} else {
		// refresca la ventana
		glutSwapBuffers();
	}
}

void igvInterfaz::set_glutMouseFunc(GLint boton,GLint estado,GLint x,GLint y) {

	// comprobar que se ha pulsado el botón izquierdo 
	if(boton == GLUT_LEFT_BUTTON){

		// guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
		// pasar a modo IGV_SELECCIONAR
		if(estado == GLUT_DOWN) {
			interfaz.modo = IGV_SELECCIONAR;
			interfaz.boton_retenido = true;

			// Apartado D: guardar el pixel pulsado
			interfaz.cursorX = x;
			interfaz.cursorY = y;

		} else interfaz.boton_retenido = false;

	}

	// renovar el contenido de la ventana de vision
	glutPostRedisplay();

}

void igvInterfaz::set_glutMotionFunc(GLint x,GLint y) {

	// si el botón está retenido y hay algún objeto seleccionado,
	// comprobar el objeto seleccionado y la posición del ratón y actualizar
	// convenientemente el grado de libertad del objeto correspondiente 
	float mov_x;
	float mov_y;

	mov_x = interfaz.cursorX - x;
	mov_y = interfaz.cursorY - y;

	interfaz.escena.motionMouse(mov_x, mov_y);

	// guardar la nueva posición del ratón 	
	interfaz.cursorX = x;
	interfaz.cursorY = y;

	// renovar el contenido de la ventana de vision 
	glutPostRedisplay(); 

}

void igvInterfaz::inicia_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {
	// establecer dónde se van a almacenar los impactos
	glSelectBuffer(TAMANO_LISTA_IMPACTOS, lista_impactos);

	// pasar a modo de seleccion de OpenGL
	glRenderMode(GL_SELECT);

	// establecer la camara en modo seleccion con los parámetros necesarios para realizar la selección
	// para el alto y el ancho de la ventana de selección probar diferentes tamaños y comprobar la amplitud de la selección
	interfaz.camara.establecerSeleccion(10, 10 ,cursorX,cursorY);
}

int procesar_impactos(int numero_impactos,GLuint *lista_impactos) {
	/* esta función debe devolver el código del objeto seleccionado, que no tiene porque coincidir con el nombre
	asignado con la pila de nombres, y si se han utilizado nombres jerárquicos hay que tener en cuenta que
	esta función sólo devolver un único código */

	GLuint minZ = 0xffffffff;
	unsigned int posArray = 0;
	int codigo = -1;

	// recorrer la lista de impactos con numero_impactos impactos,
	// guardar el más próximo al observador (minima Z)
	// para empezar, considerar que la mínima Z tiene un valor de 0xffffffff (el tope del tipo GLuint)

	for(int cont = 0; cont < numero_impactos; ++cont) {
		unsigned int numNombres = lista_impactos[posArray++];
		if(lista_impactos[posArray] < minZ && numNombres != 0) {
			minZ = lista_impactos[posArray];
			posArray += 2;
			codigo = lista_impactos[posArray];
			posArray += numNombres;
		} else posArray += numNombres+2;
	}

	// a partir de la información del impacto con la mínima Z, devolver el código del objeto que le
	// corresponde: como la escena no se almacena en ninguna estructura de datos, para devolver el objeto seleccionado
	// utilizar aquí directamente los nombres asignados a los objetos de la escena
	return codigo;
}

void igvInterfaz::finaliza_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {

	int objeto_seleccionado;

	// volver a modo visualizacion OpenGL y obtener el número de impactos 
	int numImpactos = glRenderMode(GL_RENDER);

	// si hay impactos pasar a procesarlos con la funcion int procesar_impactos(numero_impactos,lista_impactos);
	// obteniendo el objeto seleccionado, si lo hay
	if(numImpactos != 0) {
		objeto_seleccionado = procesar_impactos(numImpactos, lista_impactos);
	} else objeto_seleccionado = -1;

	if(!interfaz.ampliado) {
		switch(objeto_seleccionado){
		case CUADRO1:
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(-3.5, 1.5, 2.25),igvPunto3D(-3.5, 1.5, 2), igvPunto3D(0, 1, 0), 90, 1, 0.001, 15);
			interfaz.ampliado = true;
			break;
		case CUADRO2:
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(3.5, 1.5, 2.25),igvPunto3D(3.5, 1.5, 2), igvPunto3D(0, 1, 0), 90, 1, 0.001, 15);
			interfaz.ampliado = true;
			break;
		case FIGURA1:
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(-3.5, -1.5, 4.0),igvPunto3D(-3.5, -1.5, 2), igvPunto3D(0, 1, 0), 90, 1, 0.001, 15);
			interfaz.ampliado = true;
			break;
		case FIGURA2:
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(3.5, -1.5, 4.0),igvPunto3D(3.5, -1.5, 2), igvPunto3D(0, 1, 0), 90, 1, 0.001, 15);
			interfaz.ampliado = true;
			break;
		case PUERTA:
			interfaz.escena.cambiarSalaPrincipal();
			break;
		}
	}

	interfaz.escena.set_seleccionado(objeto_seleccionado);

	// seleccion terminada, pasar a visualización normal
	interfaz.modo = IGV_VISUALIZAR;

	// establecer la camara en modo visualización
	interfaz.camara.establecerVisualizacion();
}

void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutSpecialFunc(set_glutSpecialFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutMouseFunc(set_glutMouseFunc); 
	glutMotionFunc(set_glutMotionFunc); 
}
