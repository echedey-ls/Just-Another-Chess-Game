#pragma once

#include "Piezas.h"

class Casilla {
	static char casillas_counter;
	Pieza* pieza;
	Posicion pos;
public:
	Casilla(void) : pieza{ nullptr }, pos{ -1, -1 } {
		/* Incrementamos la posición de cada casilla, cada vez que se crea una.
		* Empezamos incrementando en el eje X, una vez lleno, el Y.
		*/
		if (casillas_counter >= CHAR_MAX) return;
		pos = { casillas_counter % 8, casillas_counter / 8 };
		casillas_counter++;
	};
	Casilla(Pieza* pieza_ptr) : Casilla() { pieza = pieza_ptr; }
	void setPieza(Pieza* pieza_ptr) { pieza = pieza_ptr; }
	Pieza* getPieza() { return pieza; }
};

