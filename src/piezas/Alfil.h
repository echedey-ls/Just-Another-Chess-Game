#pragma once

#include "../Piezas.h"
#include "ETSIDI.h"

class Alfil : virtual public Pieza
{
	bool se_ha_movido = false;

public:
	//Sprite c_peon_b[8], c_peon_n[8];

	Alfil(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = alfil;
		cargar_sprite();
	}
};