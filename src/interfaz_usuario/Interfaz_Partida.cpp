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

void Interfaz_Partida::dibuja_guia() {
	glPushMatrix();
	int y_h = 64.f;
	int y_l = 56.f;
	int d = 0;
	int r, g, b;
	for (int i = 1; i <= 5; i++) {
		if (i == 1) r = 0, g = 255, b = 0;
		else if (i == 2)r = 255;
		else if (i == 3)g = 0;
		else if (i == 4)g = 102, b = 255;
		else r = 0, g = 92, b = 230;
		glColor3ub(r, g, b);
		glBegin(GL_QUADS);
		glVertex2f(0.0f, y_l - d);
		glVertex2f(0.0f, y_h - d);
		glVertex2f(8.f, y_h - d);
		glVertex2f(8.f, y_l - d);
		glEnd();
		d += 10;
	}
	
	ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
	ETSIDI::printxy("Puedes mover", 10,60);
	ETSIDI::printxy("Puedes comer", 10, 50);
	ETSIDI::printxy("Comer al paso", 10, 40);
	ETSIDI::printxy("Disponible enroque", 10, 30);
	ETSIDI::printxy("Seleccionada", 10, 20);

	glPopMatrix();
	
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

