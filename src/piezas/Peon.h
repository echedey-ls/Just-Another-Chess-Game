#pragma once
#include "../Piezas.h"
#include "ETSIDI.h"

class Peon : virtual public Pieza
{
public:

	Peon(Color c, Estilo_grafico s) : Pieza(c, s) {
		tipo = peon;
		cargar_sprite();
	}
	enum Estado {
		sin_moverse,
		movimiento_paso_doble,
		se_ha_movido_normalmente
	} estado = sin_moverse;
};

