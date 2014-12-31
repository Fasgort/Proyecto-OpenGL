#ifndef __MUSEO
#define __MUSEO

#include <GL/glut.h>
#include "igvEscena3D.h"

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

