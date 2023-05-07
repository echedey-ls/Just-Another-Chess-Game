#pragma once

#include "../Piezas.h"
#include "ETSIDI.h"

class Caballo : virtual public Pieza
{
	bool se_ha_movido = false;

public:

	Caballo(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = caballo;
		cargar_sprite();
	}
};
