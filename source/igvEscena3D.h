#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>

#include "Objeto.h"
#include "museo.h"
#include "boxeador.h"
#include "helice.h"
#include "esferasFlotantes.h"
#include "cajaCombinacion.h"

using namespace std;

class igvEscena3D {
protected:
	// Atributos
	int _seleccionado;
	bool _salaPrincipal;

	// Objetos
	Museo* museo;
	Boxeador* figura1;
	Helice* figura2;
	esferasFlotantes* figura3;
	cajaCombinacion* figura4;
public:
	// Constructores por defecto y destructor
	igvEscena3D();
	~igvEscena3D();

	// Metodos est�ticos

	// M�todos
	// m�todo con las llamadas OpenGL para visualizar la escena
	void visualizar();

	// M�todos que comunican con los objetos de la escena

	void set_seleccionado(int seleccionado){
	museo->setSeleccionado(seleccionado);
	figura1->setSeleccionado(seleccionado);
	figura2->setSeleccionado(seleccionado);
	figura3->setSeleccionado(seleccionado);
	figura4->setSeleccionado(seleccionado);
	};

	void cambiarSalaPrincipal(){museo->set_salaPrincipal(_salaPrincipal?false:true);};
	
	// M�todos para variar grados de libertad

	void motionMouse(float mov_x, float mov_y) {
		switch(_seleccionado) {
		case P_BOXEADOR:
			figura1->set_rotacion(mov_x);
			break;
		case BRAZO_1:
			figura1->set_mu�eco_b1_ang(mov_y);
			break;
		case BRAZO_2:
			figura1->set_mu�eco_b2_ang(mov_y);
			break;
		case PU�O_1:
			figura1->set_mu�eco_p1_esc(mov_x);
			break;
		case PU�O_2:
			figura1->set_mu�eco_p2_esc(mov_x);
			break;
		case P_HELICE:
			figura2->set_rotacion(mov_x);
			break;
		case PALANCA:
			figura2->setRotAng(-mov_y);
			break;
		case ESFERAR:
			figura3->setEsferaX(-mov_x);
			figura3->setEsferaY(mov_y);
			break;
		case ESFERAB:
			figura3->setEsferaX(mov_x);
			figura3->setEsferaY(-mov_y);
			break;
		}
	}

};

#endif
