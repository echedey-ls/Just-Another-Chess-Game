#pragma once

#include "Piezas.h"
#include "Estado_casilla.h"
#include <functional>

#include "interfaz_usuario/Boton_generico.h"

class Casilla {
	static char casillas_counter;
	Pieza* pieza;
	Posicion pos;
	bool seleccionada;
	std::function<void()> click_callback;
	Boton_generico btn_casilla{ 0., 0., 0., 0. };

public:
	Casilla(void) : pieza{ nullptr }, pos{ -1, -1 } {
		/* Incrementamos la posición de cada casilla, cada vez que se crea una.
		* Empezamos incrementando en el eje X, una vez lleno, el Y.
		*/
		// Se ha construido con los valores 0,0,0,0, (float) habrá que cambiarlos?

		if (casillas_counter >= CHAR_MAX) return;
		pos = {casillas_counter % 8, casillas_counter / 8};
		casillas_counter++;
		//Asignar límites de la casilla donde el botón se encuentra
		btn_casilla.set_limits(8.*pos.x, 8.*pos.y, 8.*(pos.x+1), 8. * (pos.y + 1));

	};
	Casilla(Pieza* pieza_ptr) : Casilla() { pieza = pieza_ptr; }
	void setPieza(Pieza* pieza_ptr) { pieza = pieza_ptr; }
	Pieza* getPieza() { return pieza; }
	void ilustrar();
	Posicion getPosicion();
	void setSeleccionada(bool);
	bool getSeleccionada();

	void mouse(int button, int state, GLdouble x, GLdouble y);
	void register_on_click(std::function<void()>func) { click_callback = func; }
	
	//Queda pediente aún
	//void register_on_callback(std::function<void(Posicion)>func) {btn_casilla.register_on_click(func); }
};

