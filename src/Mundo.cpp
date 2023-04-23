#include "Mundo.h"
#include "Tablero.h"
#include "freeglut.h"

void Mundo::inicializa()
{
	x_ojo = 32;
	y_ojo = 32;
	z_ojo = 100;
}
void Mundo::creador()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
	tablero.dibuja();
}