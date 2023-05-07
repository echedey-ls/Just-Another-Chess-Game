#pragma once

#include "../Piezas.h"
#include "ETSIDI.h"

class Alfil : virtual public Pieza
{
	bool se_ha_movido = false;

public:

	Alfil(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = alfil;
		cargar_sprite();
	}
};