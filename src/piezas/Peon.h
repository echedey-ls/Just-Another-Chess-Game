#pragma once
#include "../Piezas.h"
#include "ETSIDI.h"

class Peon : virtual public Pieza
{
	bool se_ha_movido = false;

public:

	Peon(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = peon;
		cargar_sprite();
	}
};

