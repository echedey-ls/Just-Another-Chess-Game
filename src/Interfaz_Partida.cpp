#include "Interfaz_Partida.h"

Interfaz_Partida::Interfaz_Partida(std::function<void()>callback_cambio_graficos) {
	btn_cambio_graficos.register_on_click(callback_cambio_graficos);
}

Interfaz_Partida::~Interfaz_Partida() {
}

void Interfaz_Partida::dibuja() {
	btn_cambio_graficos.ilustra();
}

void Interfaz_Partida::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_cambio_graficos.mouse(button, state, x, y);
}
