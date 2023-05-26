#pragma once

#include "Colores_tipos.h"

class Jugador
{
	int piezas_comidas;
	Color color;
public:
	Jugador(Color c);
	void incremento_pzas_comidas() {
		piezas_comidas++;
	}
	int get_pzas_comidas(){ return piezas_comidas; }
	Color get_color() const { return color; }
	void set_color(Color c) { color = c; }
};

