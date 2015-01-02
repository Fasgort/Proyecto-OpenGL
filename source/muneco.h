#ifndef __MUNECO
#define __MUNECO

#include <GL/glut.h>
#include "nombres.h"

class Objeto;

class Muneco {
	friend class Objeto;
protected:
	int _seleccionado;
	GLfloat _color_seleccion[3];

	// grados de libertad
	float _muneco_b1_ang;
	float _muneco_b2_ang;
	float _muneco_p1_esc;
	float _muneco_p2_esc;

public:

	Muneco();
	~Muneco();

	void visualizar();

	void set_muneco_b1_ang(float inc);
	void set_muneco_b2_ang(float inc);
	void set_muneco_p1_esc(float inc);
	void set_muneco_p2_esc(float inc);

};

#endif
