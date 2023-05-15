#pragma once

#include "ETSIDI.h"

class Menu_Inicio {
	ETSIDI::Sprite *logotipo;
	ETSIDI::Sprite *inicio;

public:
	enum {
		inactivo = 0,
		select_void,
		select_jugar_pvp,
		select_salir,
	} estado = select_void;
	Menu_Inicio() {
		logotipo = new ETSIDI::Sprite("imagenes/Logo.png", 0.f, .0f, 64, 64);
		inicio = new ETSIDI::Sprite("imagenes/pantalla_inicio.png", 0.0f, 0.0f, 32, 32);
	};

	~Menu_Inicio() {
		delete logotipo;
	};
	/** Dibujar el menú
	* El parámetro opción indica qué texto debe ser resaltado,
	* no se tiene en cuenta la posición del cursor aquí.
	*/
	void dibuja();
};
