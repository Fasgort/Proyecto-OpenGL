#include "igvFuenteLuz.h"

// Metodos constructores 

igvFuenteLuz::igvFuenteLuz() {
}

igvFuenteLuz::igvFuenteLuz(const unsigned int _idLuz,
						   const GLfloat  * _posicion,
						   const igvColor & cAmb, const igvColor & cDif, const igvColor & cEsp,
						   const double a0, const double a1, const double a2) {

							   idLuz = _idLuz;

							   posicion[0] = _posicion[0];
							   posicion[1] = _posicion[1];
							   posicion[2] = _posicion[2];
							   posicion[3] = _posicion[3];

							   colorAmbiente = cAmb;
							   colorDifuso = cDif;
							   colorEspecular = cEsp;

							   aten_a0 = a0;
							   aten_a1 = a1;
							   aten_a2 = a2;

							   // valores por defecto cuando la luz no es un foco
							   direccion_foco = igvPunto3D(0,0,0);
							   angulo_foco = 180; // de esta manera la luz se convierte en puntual	
							   exponente_foco = 0;

							   encendida = true;
}

igvFuenteLuz::igvFuenteLuz(const unsigned int _idLuz,
						   const GLfloat * _posicion, 
						   const igvColor& cAmb, const igvColor& cDif, const igvColor& cEsp,
						   const double a0, const double a1, const double a2,
						   const igvPunto3D& dir_foco, const double ang_foco, const double exp_foco) {

							   idLuz = _idLuz;

							   posicion[0] = _posicion[0];
							   posicion[1] = _posicion[1];
							   posicion[2] = _posicion[2];
							   posicion[3] = _posicion[3];

							   colorAmbiente = cAmb;
							   colorDifuso = cDif;
							   colorEspecular = cEsp;

							   aten_a0 = a0;
							   aten_a1 = a1;
							   aten_a2 = a2;

							   direccion_foco = dir_foco;
							   angulo_foco = ang_foco;
							   exponente_foco = exp_foco;

							   encendida = true;
}

// Metodos publicos ----------------------------------------

GLfloat* igvFuenteLuz::getPosicion(void) {
	return posicion;
}

void igvFuenteLuz::setPosicion(GLfloat* pos) {
	posicion[0] = pos[0];
	posicion[1] = pos[1];
	posicion[2] = pos[2];
	posicion[3] = pos[3];
}

void igvFuenteLuz::set(const igvColor & cAmb, const igvColor & cDif, const igvColor & cEsp) {
	colorAmbiente = cAmb;
	colorDifuso = cDif;
	colorEspecular = cEsp;
}

void igvFuenteLuz::setAmbiental(const igvColor & cAmb) {
	colorAmbiente = cAmb;
}

void igvFuenteLuz::setDifuso(const igvColor & cDif) {
	colorDifuso = cDif;
}

void igvFuenteLuz::setEspecular(const igvColor & cEsp) {
	colorEspecular = cEsp;
}

igvColor & igvFuenteLuz::getAmbiental(void) {
	return colorAmbiente;
}

igvColor & igvFuenteLuz::getDifuso(void) {
	return colorDifuso;
}

igvColor & igvFuenteLuz::getEspecular(void) {
	return colorEspecular;
}

void igvFuenteLuz::setAtenuacion(double a0, double a1, double a2) {
	aten_a0 = a0;
	aten_a1 = a1;
	aten_a2 = a2;
}

void igvFuenteLuz::getAtenuacion(double & a0, double & a1, double & a2) {
	a0 = aten_a0;
	a1 = aten_a1;
	a2 = aten_a2;
}

void igvFuenteLuz::encender(void) {
	encendida = true;
}

void igvFuenteLuz::apagar(void) {
	encendida = false;
}

unsigned int igvFuenteLuz::esta_encendida(void) {
	return encendida;
}

void igvFuenteLuz::aplicar(void) {

	// si la luz está encendida
	if(esta_encendida()) {
		//	activar la luz
		glEnable(idLuz);
		//	establecer la posición de la luz
		GLfloat posGL[4];
		posGL[0] = posicion[0];
		posGL[1] = posicion[1];
		posGL[2] = posicion[2];
		posGL[3] = posicion[3];
		glLightfv(idLuz, GL_POSITION, posGL);
		//	establecer los colores ambiental, difuso y especular
		GLfloat cAmbGL[] = {colorAmbiente[0], colorAmbiente[1], colorAmbiente[2], colorAmbiente[3]};
		glLightfv(idLuz, GL_AMBIENT, cAmbGL);
		GLfloat cDifGL[] = {colorDifuso[0], colorDifuso[1], colorDifuso[2], colorDifuso[3]};
		glLightfv(idLuz, GL_DIFFUSE, cDifGL);
		GLfloat cSpGL[] = {colorEspecular[0], colorEspecular[1], colorEspecular[2], colorEspecular[3]};
		glLightfv(idLuz, GL_SPECULAR, cSpGL);
		//	establecer la atenuación radial
		glLightf(idLuz, GL_CONSTANT_ATTENUATION, aten_a0);
		glLightf(idLuz, GL_LINEAR_ATTENUATION, aten_a1);
		glLightf(idLuz, GL_QUADRATIC_ATTENUATION, aten_a2);
		//	establecer la atenuación angular y la dirección del foco
		GLfloat dir_foco[]={direccion_foco[0], direccion_foco[1], direccion_foco[2]};
		glLightfv(idLuz, GL_SPOT_DIRECTION, dir_foco);
		glLightf(idLuz, GL_SPOT_CUTOFF, angulo_foco);
		glLightf(idLuz, GL_SPOT_EXPONENT, exponente_foco);
	}
	// si la luz está apagada
	else {
		//	desactivar la luz
		glDisable(idLuz);
	}

}
