#ifndef __BFLOAT
#define __BFLOAT

#include <GL/glut.h>

#define IGV_EPSILON 0.000001 // para comparaciones con 0

#ifndef __ENUM_XYZ
#define __ENUM_XYZ

typedef enum {
	X,
	Y,
	Z
};
#endif

class bFloat {

	public:
		GLfloat c[3]; // componentes x, y, z del punto o vector

	public:
		// Constructores
		bFloat();
		bFloat(const GLfloat& x, const GLfloat& y, const GLfloat& z );
		
		// Constructor de copia
		bFloat(const bFloat& p );

		// Operador de asignación
		bFloat& operator = (const bFloat& p);

		// Operador de suma
		bFloat& operator + (const bFloat& p);

		// Operador de resta
		bFloat& operator - (const bFloat& p);

		// Operador de multiplicacion
		bFloat& operator * (const float& p);

		// Destructor
		~bFloat();

		// Operadores
		inline GLfloat& operator[] ( const unsigned char idx ) {return c[idx];};
		inline GLfloat operator[] (const unsigned char idx) const {return c[idx];};

		int operator == (const bFloat& p);
		int operator != (const bFloat& p);

		void set(const GLfloat& x, const GLfloat& y, const GLfloat& z);
};
#endif

