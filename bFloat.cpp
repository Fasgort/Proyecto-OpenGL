#include <stdio.h>
#include <math.h>

#include "bFloat.h"

// Constructores
bFloat::bFloat() {
	c[X] = c[Y] = c[Z] = 0.0;
}

bFloat::bFloat(const GLfloat& x, const GLfloat& y, const GLfloat& z ) {
	c[X] = x;
	c[Y] = y;
	c[Z] = z;	
}

// Constructor de copia
bFloat::bFloat (const bFloat& p ) {
	c[X] = p.c[X];
	c[Y] = p.c[Y];
	c[Z] = p.c[Z];
}

// Operador de asignación
bFloat& bFloat::operator = (const bFloat& p) {
	c[X] = p.c[X];
	c[Y] = p.c[Y];
	c[Z] = p.c[Z];
	return(*this);
}

// Operador de suma
bFloat& bFloat::operator + (const bFloat& p) {
	c[X] += p.c[X];
	c[Y] += p.c[Y];
	c[Z] += p.c[Z];
	return(*this);
}

// Operador de resta
bFloat& bFloat::operator - (const bFloat& p) {
	c[X] -= p.c[X];
	c[Y] -= p.c[Y];
	c[Z] -= p.c[Z];
	return(*this);
}

// Operador de multiplicacion
bFloat& bFloat::operator * (const float& p) {
	c[X] *= p;
	c[Y] *= p;
	c[Z] *= p;
	return(*this);
}

int bFloat::operator == (const bFloat& p) {
	return ((fabs(c[X]-p[X])<IGV_EPSILON) && (fabs(c[Y]-p[Y])<IGV_EPSILON) && (fabs(c[Z]-p[Z])<IGV_EPSILON));
}

int bFloat::operator != (const bFloat& p) {
	return ((fabs(c[X]-p[X])>=IGV_EPSILON) || (fabs(c[Y]-p[Y])>=IGV_EPSILON) || (fabs(c[Z]-p[Z])>=IGV_EPSILON));
}

// Destructor
bFloat::~bFloat() {
}

// Operadores

void bFloat::set(const GLfloat& x, const GLfloat& y, const GLfloat& z) {
	c[X] = x;
	c[Y] = y;
	c[Z] = z;
}

