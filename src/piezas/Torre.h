#pragma once

#include "../Piezas.h"
#include "ETSIDI.h"

class Torre : virtual public Pieza
{
	bool se_ha_movido = false;

public:


	Torre(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = torre;
		cargar_sprite();
	}
};