#ifndef __MUSEO
#define __MUSEO

#include <GL/glut.h>
#include "nombres.h"

class Objeto;

class Museo {
	friend class Objeto;
protected:
	bool _salaPrincipal;
public:

	Museo();
	~Museo();

	void visualizar();

};

#endif

