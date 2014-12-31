#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>

#include "igvFuenteLuz.h"
#include "igvMallaTriangulos.h"
#include <iostream>

using namespace std;

enum {
	PUERTA,
	BRAZO_1,
	BRAZO_2,
	PUÑO_1,
	PUÑO_2,
};

class igvEscena3D {
protected:
	// Atributos
	bool ejes;
	bool salaPrincipal;
	int seleccionado;

	// Grados libertad
	float muneco_b1_ang;
	float muneco_b2_ang;
	float muneco_p1_esc;
	float muneco_p2_esc;

public:
	// atributos públicos
	igvMallaTriangulos *malla; // malla de triángulos asociada a la escena

	// Constructores por defecto y destructor
	igvEscena3D();
	~igvEscena3D();

	// Metodos estáticos

	// Métodos
	// método con las llamadas OpenGL para visualizar la escena
	void visualizar();

	bool get_ejes() {return ejes;};
	void set_ejes(bool _ejes){ejes = _ejes;};
	void set_seleccionado(int _seleccionado){
		if(_seleccionado == PUERTA) salaPrincipal = salaPrincipal?false:true;
		else seleccionado = _seleccionado;
	};
	int get_seleccionado(){return seleccionado;};

	// Métodos para crear objetos

	void creaMuseo(GLfloat* color_seleccion);
	void creaMuneco(GLfloat* color_seleccion);

	// Métodos para variar grados de libertad

	void motionMouse(float mov_x, float mov_y) {
		switch(seleccionado) {
		case BRAZO_1:
			set_muneco_b1_ang(mov_y);
			break;
		case BRAZO_2:
			set_muneco_b2_ang(mov_y);
			break;
		case PUÑO_1:
			set_muneco_p1_esc(mov_x);
			break;
		case PUÑO_2:
			set_muneco_p2_esc(mov_x);
			break;
		}
	}

	void set_muneco_b1_ang(float inc){
		float _inc = muneco_b1_ang + inc/3;
		if (_inc > 25) _inc = 25;
		if (_inc < -25) _inc = -25;
		muneco_b1_ang = _inc;
	}

	void set_muneco_b2_ang(float inc){
		float _inc = muneco_b2_ang + inc/3;
		if (_inc > 25) _inc = 25;
		if (_inc < -25) _inc = -25;
		muneco_b2_ang = _inc;
	}

	void set_muneco_p1_esc(float inc){
		float _inc = muneco_p1_esc + inc/100;
		if (_inc > 0.25) _inc = 0.25;
		if (_inc < -0.25) _inc = -0.25;
		muneco_p1_esc = _inc;
	}

	void set_muneco_p2_esc(float inc){
		float _inc = muneco_p2_esc + inc/100;
		if (_inc > 0.25) _inc = 0.25;
		if (_inc < -0.25) _inc = -0.25;
		muneco_p2_esc = _inc;
	}

};

#endif
