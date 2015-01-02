#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>
#include "objetos.h"

using namespace std;

class igvEscena3D {
protected:
	// Atributos
	Objeto* objetos;
public:
	// Constructores por defecto y destructor
	igvEscena3D();
	~igvEscena3D();

	// Metodos estáticos

	// Métodos
	// método con las llamadas OpenGL para visualizar la escena
	void visualizar();

	void set_seleccionado(int _seleccionado){objetos->setSeleccionado(_seleccionado);};
	void cambiarSalaPrincipal(){objetos->setSalaPrincipal(objetos->getSalaPrincipal()?false:true);};

	// Métodos para variar grados de libertad

	void motionMouse(float mov_x, float mov_y) {
		switch(objetos->_seleccionado) {
		case BRAZO_1:
			objetos->figura1->set_muñeco_b1_ang(mov_y);
			break;
		case BRAZO_2:
			objetos->figura1->set_muñeco_b2_ang(mov_y);
			break;
		case PUÑO_1:
			objetos->figura1->set_muñeco_p1_esc(mov_x);
			break;
		case PUÑO_2:
			objetos->figura1->set_muñeco_p2_esc(mov_x);
			break;
		case PALANCA:
			objetos->figura2->setRotAng(-mov_y);
			break;
		case ESFERAR:
			objetos->figura3->setEsferaX(-mov_x);
			objetos->figura3->setEsferaY(mov_y);
			break;
		case ESFERAB:
			objetos->figura3->setEsferaX(mov_x);
			objetos->figura3->setEsferaY(-mov_y);
			break;
		}
	}

};

#endif
