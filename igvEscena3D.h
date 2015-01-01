#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>
#include "objetos.h"

using namespace std;

class igvEscena3D {
protected:
	// Atributos
	bool ejes;
	Objeto objetos;

public:
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
		if(_seleccionado == PUERTA) {
			objetos.setSalaPrincipal(objetos.getSalaPrincipal()?false:true);
			objetos.setSeleccionado(-1);
		}
		else objetos.setSeleccionado(_seleccionado);
	};

	// Métodos para variar grados de libertad

	void motionMouse(float mov_x, float mov_y) {
		switch(objetos._seleccionado) {
		case BRAZO_1:
			objetos.muneco.set_muneco_b1_ang(mov_y);
			break;
		case BRAZO_2:
			objetos.muneco.set_muneco_b2_ang(mov_y);
			break;
		case PUÑO_1:
			objetos.muneco.set_muneco_p1_esc(mov_x);
			break;
		case PUÑO_2:
			objetos.muneco.set_muneco_p2_esc(mov_x);
			break;
		}
	}

};

#endif
