#pragma once

#include "BotonUI.h"
#include "../Piezas.h"

#include "freeglut.h"

#include <functional>
#include <vector>

class Interfaz_Partida {
	BotonUI btn_cambio_graficos{ (unsigned char*)"USE\nTHE\nFORCE",
		69.f, 10.f, 0.02f, 68.5f, 2.7f, 79.5f, 13.f};
	//BotonUI tablero_click{ 0.0f,0.0f,64.0f,64.0f };

	//vector piezas eliminadas
	std::vector<Pieza*> piezas_blancas;
	std::vector<Pieza*> piezas_negras;

	Posicion original{ 0,0 }, destino{0,0};

public:
	Interfaz_Partida(std::function<void()>callback_cambio_graficos/*, std::function<void()>callback_click_tablero*/);
	~Interfaz_Partida();
	void dibuja();
	void mouse(int button, int state, GLdouble x, GLdouble y);
	void dibujarPiezas();
	void add_pieza(Pieza* p_pieza);

	void ultimos_movimientos(Posicion, Posicion);
};

