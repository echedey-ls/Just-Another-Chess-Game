#include "Interfaz_Partida.h"

Interfaz_Partida::Interfaz_Partida(std::function<void()>callback_cambio_graficos/*, std::function<void()>callback_click_tablero*/) {
	btn_cambio_graficos.register_on_click(callback_cambio_graficos);
	//tablero_click.register_on_click(callback_click_tablero);
}

Interfaz_Partida::~Interfaz_Partida() {
	for (auto p : piezas_blancas) {
		delete p;
	}
	for (auto p : piezas_negras) {
		delete p;
	}
}

void Interfaz_Partida::dibuja() {
	btn_cambio_graficos.ilustra();
}

void Interfaz_Partida::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_cambio_graficos.mouse(button, state, x, y);
	//tablero_click.mouse(button, state, x, y);
	
}

void Interfaz_Partida::dibujarPiezas() {

	glPushMatrix();

	//Piezas blancas
	for (auto pieza : piezas_blancas) {
        
    }

    // Piezas negras
    for (auto pieza : piezas_negras) {
        
    }

	glPopMatrix();
}

void Interfaz_Partida::add_pieza(Pieza* p_pza) {
	
	if (p_pza->get_color() == blanca) {
		piezas_blancas.push_back(p_pza);
	}
	else {
		piezas_negras.push_back(p_pza);
	}
	
}



