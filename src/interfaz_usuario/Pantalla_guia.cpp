#include "Pantalla_guia.h"

void Pantalla_guia::dibuja() {
	btn_guia_juego.ilustra();
}

void Pantalla_guia::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_guia_juego.mouse(button, state, x, y);
}

Pantalla_guia::~Pantalla_guia() {

}


