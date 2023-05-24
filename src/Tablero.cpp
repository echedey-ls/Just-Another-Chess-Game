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
* Las blancas estaran en las dos primeras filas (0 & 1)
* Las negras estaran en las dos ultimas filas (6 & 7)
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
* Devuelve puntero a la pieza en determinada posicion
* Si no hay, devuelve nullptr
*/
Estilo_grafico Tablero::siguiente_estilo() {
	switch (estilo)
	{
	
	case clasico:
		estilo = stars_wars;
		break;
	case stars_wars:
		estilo = clasico;
		break;
	case no_definido:
	default:
		estilo = clasico;
		break;
	}
	actualizar_estilo_piezas();
	return estilo;
}

void Tablero::actualizar_estilo_piezas() {
	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila) {
			auto pieza = casilla.getPieza();
			if (pieza) pieza->cambiar_estilo(estilo);
		}
}

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

	//mover_pieza({ 4,1 }, { 7,2 });   la función mover_pieza está en tablero.h, y lo que se les pasan como argumentos es de la clase posicion 
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
	{
		if (casilla(p).get_primer_mov()) { //si es el primer movimiento del peon
			char i=0, j=0;
			Posicion a_revisar1 = { p.x, p.y + (pza_p->get_color() == blanca ? i : -i) };
			Posicion a_revisar2 = { p.x+j, p.y + (pza_p->get_color() == blanca ? 1 : -1) };
			do {
				i++;
				if (es_posicion_valida(a_revisar1)) {
					Pieza* otra_pieza = obtener_pieza_en(a_revisar1);
					if (!otra_pieza) { // No existe pieza en la posicion que estamos revisando
						resultado(a_revisar1) = si_movible;
					}
					else
						resultado(a_revisar1) = no_movible;
				}
			}while ((resultado(a_revisar1) != no_movible)||(i<2));

			for (j = -1; j <= 1; j++) {
				if (es_posicion_valida(a_revisar2)) {
					Pieza* otra_pieza = obtener_pieza_en(a_revisar2);
					if ((j != 0) && (otra_pieza))
						resultado(a_revisar2) = atacable;
					if ((j == 0) && (!otra_pieza))
						resultado(a_revisar2) = si_movible;
				}
			}
			casilla(p).primer_mov_hecho();
		}
		else
		{
			char j=0;
			Posicion a_revisar2 = { p.x + j, p.y + (pza_p->get_color() == blanca ? 1 : -1) };
			for (j = -1; j <= 1; j++) {
				if (es_posicion_valida(a_revisar2)) {
					Pieza* otra_pieza = obtener_pieza_en(a_revisar2);
					if ((j != 0) && (otra_pieza))
						resultado(a_revisar2) = atacable;
					if ((j == 0) && (!otra_pieza))
						resultado(a_revisar2) = si_movible;
				}
			}
		}
			/** TODO: check atacable en passant y primer movimiento de dos casillas **/
		break; }
	case torre:
	{
		char i = 0;
		Posicion v_a_revisar[4] = { { p.x + i, p.y},{ p.x - i,p.y },{ p.x, p.y + i },{ p.x,p.y - i } };
		for (int j = 0; j < 4; j++) {
			do {
				i++;
				if (es_posicion_valida(v_a_revisar[j])) {
					Pieza* otra_pieza = obtener_pieza_en(v_a_revisar[j]);
					if (!otra_pieza) { // No existe pieza en la posicion que estamos revisando
						resultado(v_a_revisar[j]) = si_movible;
					}
					else if (pza_p->get_color() != otra_pieza->get_color()) { // Es pieza del equipo contrario
						resultado(v_a_revisar[j]) = atacable;
					}
				}
				
			} while ((resultado(v_a_revisar[j]) != atacable) || (i < 7));
		}
		break; }
	case caballo:
	{
		Posicion v_a_revisar[8] = { { p.x + 1, p.y + 2},{ p.x + 2,p.y + 1 },{ p.x + 2, p.y - 1 },{ p.x + 1,p.y - 2 }, { p.x - 1, p.y - 2 },{ p.x - 2,p.y - 1 },{ p.x - 2, p.y + 1 },{ p.x - 1,p.y + 2 } };
		for (int j = 0; j < 8; j++) {
			if (es_posicion_valida(v_a_revisar[j])) {
				Pieza* otra_pieza = obtener_pieza_en(v_a_revisar[j]);
				if (!otra_pieza) { // No existe pieza en la posicion que estamos revisando
					resultado(v_a_revisar[j]) = si_movible;
				}
				else if (pza_p->get_color() != otra_pieza->get_color()) { // Es pieza del equipo contrario
					resultado(v_a_revisar[j]) = atacable;
				}
			}
		}
		break; }
	case alfil:
	{
		char i = 0;
		Posicion v_a_revisar[4] = { { p.x + i, p.y + i },{ p.x - i,p.y - i },{ p.x + i, p.y - i },{ p.x - i,p.y + i } };
		for (int j = 0; j < 4; j++) {
			do {
				i++;
				if (es_posicion_valida(v_a_revisar[j])) {
					Pieza* otra_pieza = obtener_pieza_en(v_a_revisar[j]);
					if (!otra_pieza) { // No existe pieza en la posicion que estamos revisando
						resultado(v_a_revisar[j]) = si_movible;
					}
					else if (pza_p->get_color() != otra_pieza->get_color()) { // Es pieza del equipo contrario
						resultado(v_a_revisar[j]) = atacable;
					}
				}
			} while ((resultado(v_a_revisar[j]) != atacable)||(i<7));
		}
		break; }
	case reina:
	{
		char i = 0;
		Posicion v_a_revisar[8] = { { p.x + i, p.y},{ p.x - i,p.y },{ p.x, p.y + i },{ p.x,p.y - i }, { p.x + i, p.y + i },{ p.x - i,p.y - i },{ p.x + i, p.y - i },{ p.x - i,p.y + i } };
		for (int j = 0; j < 8; j++) {
			do {
				i++;
				if (es_posicion_valida(v_a_revisar[j])) {
					Pieza* otra_pieza = obtener_pieza_en(v_a_revisar[j]);
					if (!otra_pieza) { // No existe pieza en la posicion que estamos revisando
						resultado(v_a_revisar[j]) = si_movible;
					}
					else if (pza_p->get_color() != otra_pieza->get_color()) { // Es pieza del equipo contrario
						resultado(v_a_revisar[j]) = atacable;
					}
				}
			} while ((resultado(v_a_revisar[j]) != atacable)||(i<7));
		}
		break; }
	case rey:
	{
		Posicion base = { p.x,p.y };
		for (char x = -1; x <= 1; x++) {
			for (char y = -1; y <= 1; y++) {
				Posicion a_revisar = { p.x + x, p.y + y };
				if (a_revisar == base) {
					resultado(a_revisar) = no_movible;
				}
				if (es_posicion_valida(a_revisar)) {
					Pieza* otra_pieza = obtener_pieza_en(a_revisar);
					if (!otra_pieza) { // No existe pieza en la posicion que estamos revisando
						resultado(a_revisar) = si_movible;
					}
					else if (pza_p->get_color() != otra_pieza->get_color()) { // Es pieza del equipo contrario
						resultado(a_revisar) = atacable;
					}
				}
			}
		}
		// FALTA AJUSTAR LIMITACIONES CUANDO HAY JAQUE!!!!
		break; }
	default:
		break;
	}
}

/*void Tablero::ilumina() {

	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Given the coordinates
	gluOrtho2D(0.0, 800.0,
		0.0, 600.0); 


	glPushMatrix();
	/*glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();

	
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-5.0f, -5.0f, 1); // top left
	glVertex3f(-5.0f, 5.0f, 1); // top right 
	glVertex3f(5.0f, 5.0f, 1); // bottom right
	glVertex3f(5.0f, -5.0f, 1); // bottom left
	glEnd();
	glFlush();
} */