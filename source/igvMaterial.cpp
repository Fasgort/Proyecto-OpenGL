#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {

}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {

	// Aplicar los valores de los atributos del objeto igvMaterial:
	// - coeficiente de reflexión de la luz ambiental
	GLfloat KaGL[] = {Ka[0], Ka[1], Ka[2], Ka[3]};
	glMaterialfv(GL_FRONT, GL_AMBIENT, KaGL);
	// - coeficiente de reflexión difuso
	GLfloat KdGL[] = {Kd[0], Kd[1], Kd[2], Kd[3]};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, KdGL);
	// - coeficiente de reflesión especular
	GLfloat KsGL[] = {Ks[0], Ks[1], Ks[2], Ks[3]};
	glMaterialfv(GL_FRONT, GL_SPECULAR, KsGL);
	// - exponente de Phong
	GLfloat NsGL[] = {Ns};
	glMaterialfv(GL_FRONT, GL_SHININESS, NsGL);

	// establecer como color de emisión (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)
	GLfloat emisionGL[] = {0.0, 0.0, 0.0};
	glMaterialfv(GL_FRONT, GL_EMISSION, emisionGL);

}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



