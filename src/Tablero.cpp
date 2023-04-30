#include "Tablero.h"
#include "ETSIDI.h"

#include "piezas/Peon.h"


/**
* Inicializa el tablero con las piezas de normal
* Las blancas estarán en las dos primeras filas (0 & 1)
* Las negras estarán en las dos últimas filas (6 & 7)
*/
Tablero::Tablero() : estilo(clasico)
{
	inicializa();
	ETSIDI::play("ventana");
	ETSIDI::Sprite Tablero("imagenes/tablero.png", 0, 0, 64, 64);
	void draw();
	//Tablero.setTexture("imagenes/tablero.png");
}

/**
* Devuelve puntero a la pieza en determinada posición
* Si no hay, devuelve nullptr
*/
inline
Pieza* Tablero::obtener_pieza_en(const Posicion& p) {
	return casillas[p.x][p.y].getPieza();
}

void Tablero::inicializa() {
	Peon* peones_wh[8], * peones_bk[8];
	for (size_t i = 0; i < 8; ++i) {
		peones_wh[i] = new Peon(blanca, clasico);
		casillas[i][1].setPieza(peones_wh[i]);
		peones_bk[i] = new Peon(negra, clasico);
		casillas[i][6].setPieza(peones_bk[i]);
	}
}

void Tablero::dibuja()
{
	// Dibujar el tablero

	// Dibujar todas las piezas que hay en el tablero
	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila)
			;//casilla.ilustrar();
}

void Tablero::mover_pieza(const Posicion& origen, const Posicion& destino) {
	Pieza* pza = eliminar_pieza(origen);
	if(pza) casillas[destino.x][destino.y].setPieza(pza);
}

Pieza* Tablero::eliminar_pieza(const Posicion& p)
{
	Pieza* pza = casillas[p.x][p.y].getPieza();
	casillas[p.x][p.y].setPieza(nullptr);
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
