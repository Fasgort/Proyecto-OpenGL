#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>
#include "objetos.h"

using namespace std;

class igvEscena3D {
protected:
	// Atributos
	bool ejes;
	Objeto* objetos;
public:
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
			objetos->setSalaPrincipal(objetos->getSalaPrincipal()?false:true);
			objetos->setSeleccionado(-1);
		}
		else objetos->setSeleccionado(_seleccionado);
	};

	// M�todos para variar grados de libertad

	void motionMouse(float mov_x, float mov_y) {
		switch(objetos->_seleccionado) {
		case BRAZO_1:
			objetos->figura1->set_mu�eco_b1_ang(mov_y);
			break;
		case BRAZO_2:
			objetos->figura1->set_mu�eco_b2_ang(mov_y);
			break;
		case PU�O_1:
			objetos->figura1->set_mu�eco_p1_esc(mov_x);
			break;
		case PU�O_2:
			objetos->figura1->set_mu�eco_p2_esc(mov_x);
			break;
		case PALANCA:
			objetos->figura2->setRotAng(-mov_y);
			break;
		}
	}

};

#endif
