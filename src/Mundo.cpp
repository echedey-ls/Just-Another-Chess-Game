#include "Mundo.h"
#include "Tablero.h"
#include "freeglut.h"

void Mundo::inicializa()
{
	x_ojo = 32;
	y_ojo = 32;
	z_ojo = 100;

	menu_inicio.estado = Menu_Inicio::select_void;
	tablero.inicializa();
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo,y_ojo,0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)


	// Esto es guarro, hay que hacer un entorno de elección (enum o algo así)
	menu_inicio.dibuja();
	tablero.dibuja();
}

void Mundo::ilumina_casilla() {

	tablero.ilumina();
}