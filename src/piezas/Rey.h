#pragma once

#include "../Piezas.h"
#include "ETSIDI.h"

class Rey : virtual public Pieza
{
	bool se_ha_movido = false;

public:

	Rey(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = rey;
		cargar_sprite();
	}
};

