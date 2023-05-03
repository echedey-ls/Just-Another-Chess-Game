#include "Mundo.h"
#include "Tablero.h"
#include "freeglut.h"

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 20;
	z_ojo = 80;

	tablero.inicializa();
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

	tablero.dibuja();
}