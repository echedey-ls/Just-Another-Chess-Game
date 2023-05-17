#pragma once
#include "Tablero.h"
#include "Menu_Inicio.h"
#include "Interfaz_Partida.h"
#include "interfaz_usuario/Menu_opciones_prejuego.h"

#include <functional>

class Mundo {
	float x_ojo = 0.f;
	float y_ojo = 0.f;
	float z_ojo = 0.f;
public:
	void inicializa();
	void dibuja();
	void mouse(int button, int state, int x, int y);

	Menu_Inicio menu_inicio;
	Tablero tablero;
	Interfaz_Partida gui_partida{ std::bind(&Tablero::siguiente_estilo, &tablero) };
	Menu_opciones_prejuego menu_opts_prejuego;
};
