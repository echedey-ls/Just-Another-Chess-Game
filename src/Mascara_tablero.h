#pragma once

#include <array>

#include "Posicion.h"
#include "Estado_casilla.h"

/** Esta clase consiste en una herramienta para traducir información relativa a casillas:
* A dónde se puede mover una pieza
* A dónde no se puede mover
* Si lo hemos comprobado, y a qué se debe (para luego pintar las casillas)
* 
* Modo de uso:
* void reset()
*		Establece el estado de todas las casillas que representa como 'sin_calcular'
* Disponibilidad_casilla& Mascara_tablero(uint x, uint y)
* Disponibilidad_casilla& Mascara_tablero(Posicion& p)
*		Devuelve referencia de la casilla apuntada; por tanto, se puede modificar.
*		Ej:
*			Mascara_tablero msk;
*			msk(2, 2) = movible;
* 
* Recomendación:
*		Usar la implementación comentada de 'void reset()' si hay que recorrer todos los elementos.
*/

constexpr char LADO_MASCARA = 8; // Será igual al lado del tablero


// A priori lo dejo todo público, pues el type-checking de C++ ya avisará de errores simples en el uso del array.
struct Mascara_tablero {
	// Usamos array de la librería estándar porque cuentan con características maravillosas
	std::array<std::array<Disponibilidad_casilla, LADO_MASCARA>, LADO_MASCARA> disponibilidades;

	Mascara_tablero() {
		reset();
	}
	void reset();
	Disponibilidad_casilla& operator()(unsigned char x, unsigned char y);
	Disponibilidad_casilla& operator()(const Posicion& p);
};

