#ifndef __IGVCAMARA
#define __IGVCAMARA

#include <GL/glut.h>

#include "igvPunto3D.h"

typedef enum {
	IGV_PARALELA,
	IGV_FRUSTUM,
	IGV_PERSPECTIVA
} tipoCamara;

typedef enum {
	IGV_VISUALIZACION,
	IGV_SELECCION
} modoCamara;

class igvCamara {

public:
	// atributos

	tipoCamara tipo; // paralela o perspectiva

	// ventana de visión: parametros proyección paralela y frustum
	GLdouble xwmin, xwmax, ywmin, ywmax;

	// ventana de visión: parametros proyección perspectiva
	GLdouble angulo, raspecto;

	// distancias de planos cercano y lejano
	GLdouble znear, zfar;

	// punto de visión	
	igvPunto3D P0;

	// punto de referencia de visión	
	igvPunto3D r;

	// vector arriba	
	igvPunto3D V;

	////// atributos necesarios para generar el volumen alrededor del pixel seleccionado
	modoCamara modo; // camara se utiliza para visualizar (IGV_VISUALIZACION) o para seleccionar (IGV_SELECCION)
	int cursorX, cursorY; // posición del viewport seleccionada a partir de la cual hay que generar el volumen
	// de visión para la selección por lista de impactos
	int ancho_seleccion, alto_seleccion; // tamaño de la ventana para hacer la seleccion por lista de impactos

	// Metodos

public:
	// Constructores por defecto y destructor
	igvCamara();
	~igvCamara();

	// Otros constructores
	igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

	// Metodos
	// define la posición de la cámara
	void set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

	// define una cámara de tipo paralela o frustum
	void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
		double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar);

	// define una cámara de tipo perspectiva
	void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
		double _angulo, double _raspecto, double _znear, double _zfar);

	void aplicar(void); // aplica a los objetos de la escena la transformación de visión y la transformación de proyección
	// asociadas a los parámetros de la cámara

	////// métodos para cambiar el modo de la camara
	void establecerSeleccion(int _ancho_seleccion, int _alto_seleccion, int _cursorX, int _cursorY) {
		modo = IGV_SELECCION;
		// ancho y alto de la ventana de selección
		ancho_seleccion = _ancho_seleccion;
		alto_seleccion = _alto_seleccion;
		// pixel pulsado
		cursorX = _cursorX;
		cursorY = _cursorY;
	};

	void establecerVisualizacion() {
		modo = IGV_VISUALIZACION;
	};
};

#endif

