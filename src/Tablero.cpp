#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"

#include "piezas/Peon.h"
#include "piezas/Torre.h"
#include "piezas/Caballo.h"
#include "piezas/Alfil.h"
#include "piezas/Reina.h"
#include "piezas/Rey.h"
#include "letras_tablero.h"


/**
* Inicializa el tablero con las piezas de normal
* Las blancas estar n en las dos primeras filas (0 & 1)
* Las negras estar n en las dos  ltimas filas (6 & 7)
*/



Tablero::Tablero() : estilo(clasico)
{
	inicializa();
}

Tablero::~Tablero() {
	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila)
			delete casilla.getPieza();
}

/**
* Devuelve puntero a la pieza en determinada posici n
* Si no hay, devuelve nullptr
*/
inline
Pieza* Tablero::obtener_pieza_en(const Posicion& p) {
	return casilla(p).getPieza();
}

void Tablero::inicializa() {
	tablero.setPos(32, 32);

	/* Piezas */
	// Peones
	for (char i = 0; i < 8; ++i) {
		casilla(i, 1).setPieza(new Peon(blanca, clasico));
		casilla(i, 6).setPieza(new Peon(negra, clasico));
	}
	//Torres
	for (char i = 0; i < 2; i++) {
		casilla(7 * i,0).setPieza(new Torre(blanca, clasico));
		casilla(7 * i,7).setPieza(new Torre(negra, clasico));
	}
	//Caballos
	for (char i = 0; i < 2; i++) {
		casilla(i == 0 ? (7 * i + 1) : (7 * i - 1), 0).setPieza(new Caballo(blanca, clasico));
		casilla(i == 0 ? (7 * i + 1) : (7 * i - 1), 7).setPieza(new Caballo(negra, clasico));
	}
	//Alfiles
	for (char i = 0; i < 2; i++) {
		casilla(i == 0 ? (7 * i + 2) : (7 * i - 2), 0).setPieza(new Alfil(blanca, clasico));
		casilla(i == 0 ? (7 * i + 2) : (7 * i - 2), 7).setPieza(new Alfil(negra, clasico));
	}
	//Reinas
	casilla(3, 0).setPieza(new Reina(blanca, clasico));
	casilla(4, 7).setPieza(new Reina(negra, clasico));
	//Reyes
	casilla(4, 0).setPieza(new Rey(blanca, clasico));
	casilla(3, 7).setPieza(new Rey(negra, clasico));

	//mover_pieza({ 4,1 }, { 7,2 });   la función mover_pieza está en tablero.h, y lo que se les pasan como argumentos es la clase posicion (vector2D en la practica)
}

void Tablero::dibuja()
{
	// Dibujar el tablero
	tablero.draw();

	// Dibujar todas las piezas que hay en el tablero
	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila)
			casilla.ilustrar();

	//Dibuja letras tablero
	letras_tablero cadena;
	cadena.cadena_letras();
	cadena.cadena_numeros();
}

void Tablero::mover_pieza(const Posicion& origen, const Posicion& destino) {
	Pieza* pza = quitar_pieza(origen);
	if (pza) casilla(destino).setPieza(pza);
}

Pieza* Tablero::quitar_pieza(const Posicion& p)
{
	Pieza* pza = obtener_pieza_en(p);
	casilla(p).setPieza(nullptr);
	return pza;
}

void Tablero::calculadora_movimientos(const Posicion& p, Mascara_tablero& resultado) {
	Pieza* pza_p = obtener_pieza_en(p);
	if (!pza_p) return; // No existe pieza (es puntero nullptr)
	switch (pza_p->get_tipo())
	{
	case peon:
		for (char x = -1; x <= 1; x++) { // Loop para calcular posiciones que comprobaremos
			Posicion a_revisar = { p.x + x, p.y + (pza_p->get_color() == blanca ? 1 : -1) }; // El sentido de avance depende del color
			if (es_posicion_valida(a_revisar)) {
				Pieza* otra_pieza = obtener_pieza_en(a_revisar);
				if (!otra_pieza) { // No existe pieza en la posicion que estamos revisando
					resultado(a_revisar) = si_movible;
				}
				else if (pza_p->get_color() != otra_pieza->get_color()) { // Es pieza del equipo contrario
					resultado(a_revisar) = atacable;
				}
			}
			/** TODO: check atacable en passant y primer movimiento de dos casillas **/
		}
		break;
	default:
		break;
	}
}

/*Posicion* Tablero::setLimite() {

	const Posicion& mi_limite = { 0,0 };


}*/