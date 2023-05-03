#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"

#include "piezas/Peon.h"



/**
* Inicializa el tablero con las piezas de normal
* Las blancas estar�n en las dos primeras filas (0 & 1)
* Las negras estar�n en las dos �ltimas filas (6 & 7)
*/



Tablero::Tablero() : estilo(clasico)
{
	inicializa();
}

/**
* Devuelve puntero a la pieza en determinada posici�n
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
		casillas[1][i].setPieza(peones_wh[i]);
		peones_bk[i] = new Peon(negra, clasico);
		casillas[6][i].setPieza(peones_bk[i]);
	}
}

void Tablero::dibuja()
{
	/*//Poner coordenadas
	char caracter = 'A';
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(40, 40); // posici�n del car�cter
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'A');*/

	// Dibujar todas las piezas que hay en el tablero
	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila)
			casilla.ilustrar();
	// Dibujar el tablero
	tablero.setPos(32, 32);
	tablero.draw();
}

void Tablero::mover_pieza(const Posicion& origen, const Posicion& destino) {
	Pieza* pza = eliminar_pieza(origen);
	if(pza) casillas[destino.y][destino.x].setPieza(pza);
}

Pieza* Tablero::eliminar_pieza(const Posicion& p)
{
	Pieza* pza = casillas[p.y][p.x].getPieza();
	casillas[p.y][p.x].setPieza(nullptr);
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
