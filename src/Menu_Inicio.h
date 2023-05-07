#pragma once

#include "ETSIDI.h"

class Menu_Inicio {
	ETSIDI::Sprite *logotipo;

public:
	enum {
		inactivo = 0,
		select_void,
		select_jugar_pvp,
		select_salir,
	} estado = select_void;
	Menu_Inicio() {
		logotipo = new ETSIDI::Sprite("imagenes/Logo.png", 0.f, .0f, 64, 64);
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
