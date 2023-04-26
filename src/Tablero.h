#pragma once

#include "Estilos_graficos.h"
#include "Casilla.h"
#include "Mascara_tablero.h"

#include "ETSIDI.h"

class Tablero
{
	Casilla casillas[8][8];
	Estilo_grafico estilo;

public:
	Tablero(); // Inicializa tablero con sus piezas distribuidas en un juego normal
	void creador();
	void dibuja();

	/* Necesario para acceder a las piezas del tablero
	* y computar movimientos posibles
	*/
	static bool es_posicion_valida(const Posicion& p) { return !(p.x < 0 or p.x > 7 or p.y < 0 or p.y > 7); };
	Pieza* obtener_pieza_en(const Posicion& p);
	void mover_pieza(const Posicion& origen, const Posicion& destino);
	Pieza* eliminar_pieza(const Posicion& casilla);

	// Lo que realmente calcula los movimientos
	void calculadora_movimientos(const Posicion& p, Mascara_tablero& resultado);
};

