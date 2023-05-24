#include "Interfaz_Partida.h"

Interfaz_Partida::Interfaz_Partida(std::function<void()>callback_cambio_graficos/*, std::function<void()>callback_click_tablero*/) {
	btn_cambio_graficos.register_on_click(callback_cambio_graficos);
	//tablero_click.register_on_click(callback_click_tablero);
}

Interfaz_Partida::~Interfaz_Partida() {
}

void Interfaz_Partida::dibuja() {
	btn_cambio_graficos.ilustra();
}

void Interfaz_Partida::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_cambio_graficos.mouse(button, state, x, y);
	//tablero_click.mouse(button, state, x, y);
	


}
