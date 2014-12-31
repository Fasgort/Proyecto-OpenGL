#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>
#include "igvMallaTriangulos.h"
#include "museo.h"
#include "muneco.h"

using namespace std;

enum {
	PUERTA,
	BRAZO_1,
	BRAZO_2,
	PU�O_1,
	PU�O_2,
};

class igvEscena3D {
protected:
	// Atributos
	bool ejes;
	bool salaPrincipal;
	int seleccionado;

	// Objetos
	Museo museo;
	Muneco muneco;

public:
	// atributos p�blicos
	igvMallaTriangulos *malla; // malla de tri�ngulos asociada a la escena

	// Constructores por defecto y destructor
	igvEscena3D();
	~igvEscena3D();

	// Metodos est�ticos

	// M�todos
	// m�todo con las llamadas OpenGL para visualizar la escena
	void visualizar();

	bool get_ejes() {return ejes;};
	void set_ejes(bool _ejes){ejes = _ejes;};
	void set_seleccionado(int _seleccionado){
		if(_seleccionado == PUERTA) {
			salaPrincipal = salaPrincipal?false:true;
			seleccionado = -1;
		}
		else {
			seleccionado = _seleccionado;
			muneco._seleccionado = _seleccionado;
		}
	};
	int get_seleccionado(){return seleccionado;};

	// M�todos para variar grados de libertad

	void motionMouse(float mov_x, float mov_y) {
		switch(seleccionado) {
		case BRAZO_1:
			muneco.set_muneco_b1_ang(mov_y);
			break;
		case BRAZO_2:
			muneco.set_muneco_b2_ang(mov_y);
			break;
		case PU�O_1:
			muneco.set_muneco_p1_esc(mov_x);
			break;
		case PU�O_2:
			muneco.set_muneco_p2_esc(mov_x);
			break;
		}
	}

};

#endif
