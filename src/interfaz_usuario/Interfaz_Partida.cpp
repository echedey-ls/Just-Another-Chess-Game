#include "Interfaz_Partida.h"


Interfaz_Partida::Interfaz_Partida(std::function<void()>callback_cambio_graficos, std::function<void()>callback_guia_juego) {
	btn_cambio_graficos.register_on_click(callback_cambio_graficos);
	btn_guia_juego.register_on_click(callback_guia_juego);
}

void Interfaz_Partida::dibuja() {
	btn_cambio_graficos.ilustra();
	btn_guia_juego.ilustra();
	dibujarPiezas();
}

void Interfaz_Partida::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_cambio_graficos.mouse(button, state, x, y);
	btn_guia_juego.mouse(button, state, x, y);
	//tablero_click.mouse(button, state, x, y);
}

void Interfaz_Partida::dibujarPiezas() {

	//Piezas blancas
	int xb = 95;  
	int yb = 68;
	int i = 0;
	
	for (auto pieza : piezas_blancas) {
		glPushMatrix();
		glTranslatef(xb, yb, 0);
		pieza->ilustrar();
		glPopMatrix();

		yb -= 8;
		i++;
		if (i == 10){
			xb -= 10;
			yb = 68;
		}
		
    }

	// Piezas negras
	int xn = -33;
	int yn = 68;
	int c = 0;

    for (auto pieza : piezas_negras) {
		glPushMatrix();
		glTranslatef(xn, yn, 0);
		pieza->ilustrar();
		glPopMatrix();

		yn -= 8;
		c++;
		if (c == 10) {
			xn += 10;
			yn = 68;
		}
    }
}

void Interfaz_Partida::add_pieza(Pieza* p_pza) {
	if (!p_pza) return;
	if (p_pza->get_color() == blanca) {
		piezas_blancas.push_back(p_pza);
	}
	else {
		piezas_negras.push_back(p_pza);
	}
	
}

Interfaz_Partida::~Interfaz_Partida() {
	for (auto p : piezas_blancas) {
		delete p;
	}
	for (auto p : piezas_negras) {
		delete p;
	}
}

