#pragma once

#include "../Piezas.h"
#include "ETSIDI.h"

class Reina : virtual public Pieza
{
	bool se_ha_movido = false;

public:

	Reina(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = reina;
		cargar_sprite();
	}
};
