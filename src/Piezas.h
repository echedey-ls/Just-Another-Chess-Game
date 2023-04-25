#pragma once

#include "Posicion.h"
#include "Estilos_graficos.h"
#include "Mascara_tablero.h"

// Par de enumeraciones con los valores que pueden tomar las piezas
enum Color {
	blanca,
	negra,
};
enum Tipo { rey, reina, alfil, torre, caballo, peon };

class Pieza {
	Color color;
	Tipo tipo;
	Posicion pos;

public:
	Pieza(Color c, Tipo t, unsigned char x, unsigned char y) : color{c}, tipo{t}, pos{x, y} {};
	Posicion get_posicion() { return { pos.x, pos.y }; }
	/*virtual*/ void ilustrar(Estilo_grafico estilo);
	void mover_a(Posicion p);
	virtual void calcular_movimientos_posibles(Mascara_tablero& destino);
};
