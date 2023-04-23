#include "Tablero.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

/**
* Inicializa el tablero con las piezas de normal
* Las blancas estarán en las dos primeras filas (0 & 1)
* Las negras estarán en las dos últimas filas (6 & 7)
*/



Tablero::Tablero() : estilo(clasico)
{

	tablero.setPos(32, 32);
	dibuja();



	piezas.reserve(32); // # Piezas en juego clásico

	// TODO: ACTUALIZAR CON LAS CLASES HEREDADAS
	// TODO: OPTIMIZAR ALGORITMO
	//Peones
	for (unsigned char i = 0; i < 8; i++) {
		piezas.emplace_back(blanca, peon, i, 1 );
		piezas.emplace_back(blanca, peon, i, 6 );
	}
	//Torres
	piezas.emplace_back(blanca, torre, 0, 0 );
	piezas.emplace_back(blanca, torre, 7, 0 );

	piezas.emplace_back(negra, torre, 0, 7 );
	piezas.emplace_back(negra, torre, 7, 7 );

	//Caballos
	piezas.emplace_back(blanca, caballo, 1, 0 );
	piezas.emplace_back(blanca, caballo, 6, 0 );

	piezas.emplace_back(negra, caballo, 1, 7 );
	piezas.emplace_back(negra, caballo, 6, 7 );

	//Alfiles
	piezas.emplace_back(blanca, alfil, 2, 0 );
	piezas.emplace_back(blanca, alfil, 5, 0 );

	piezas.emplace_back(negra, alfil, 2, 7 );
	piezas.emplace_back(negra, alfil, 5, 7 );

	//Reinas
	piezas.emplace_back(blanca, reina, 3, 0 );
	piezas.emplace_back(negra, reina, 3, 7 );

	//Reyes
	piezas.emplace_back(blanca, rey, 4, 0 );
	piezas.emplace_back(negra, rey, 4, 7 );
}

/**
* Devuelve puntero a la pieza en determinada posición
* Si no hay, devuelve nullptr
*/
Pieza* Tablero::obtener_pieza_en(Posicion p)
{
	for (auto& pieza : piezas) if (pieza.get_posicion() == p) return &pieza;
	return nullptr;
}



void Tablero::dibuja()
{
	for (auto& pieza : piezas) pieza.ilustrar(estilo);
	tablero.draw();
}