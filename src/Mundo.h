#pragma once
#include "Tablero.h"
#include "interfaz_usuario/Menu_Inicio.h"
#include "interfaz_usuario/Interfaz_Partida.h"
#include "interfaz_usuario/Menu_opciones_prejuego.h"

#include <functional>


class Mundo {
	float x_ojo = 0.f;
	float y_ojo = 0.f;
	float z_ojo = 0.f;
public:
	Mundo();
	void inicializa();
	void dibuja();
	void mouse(int button, int state, int x, int y);

	enum Estado {
		started,
		pantalla_inicio,
		pantalla_seleccion_team,
		juego,
		fin_partida,
		pantalla_guia
	} estado;

	// Callbacks para cambiar los estados desde los atributos
	void callback_menu_inicio(bool jugar);
	void callback_menu_prejuego(bool color_blanco);
	void callback_guia_juego();

	// Clases del juego
	Menu_Inicio menu_inicio{ std::bind(&Mundo::callback_menu_inicio, this, std::placeholders::_1) };
	Tablero tablero{ std::bind(&Interfaz_Partida::add_pieza, &gui_partida, std::placeholders::_1) };
	Interfaz_Partida gui_partida{ std::bind(&Tablero::siguiente_estilo, &tablero), std::bind(&Mundo::callback_guia_juego, this)};
	Menu_opciones_prejuego menu_opts_prejuego{ std::bind(&Mundo::callback_menu_prejuego, this, std::placeholders::_1) };
};
