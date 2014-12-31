#ifndef __MUSEO
#define __MUSEO

#include <GL/glut.h>
#include "objetos.h"

class igvEscena3D;

class Museo {
	friend class igvEscena3D;
protected:
	bool _salaPrincipal;
public:

	Museo();
	~Museo();

	void visualizar();

};

#endif

