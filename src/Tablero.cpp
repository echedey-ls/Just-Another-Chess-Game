#include "Tablero.h"
#include "ETSIDI.h"
#include "freeglut.h"

#include "piezas/Peon.h"
#include "piezas/Torre.h"
#include "piezas/Caballo.h"
#include "piezas/Alfil.h"
#include "piezas/Reina.h"
#include "piezas/Rey.h"
#include "interfaz_usuario/letras_tablero.h"

#include <iostream>
#include <functional>

/**
* Inicializa el tablero con las piezas de normal
* Las blancas estaran en las dos primeras filas (0 & 1)
* Las negras estaran en las dos ultimas filas (6 & 7)
*/


Tablero::Tablero(std::function<void(Pieza*)> callback_pieza_eliminada_)
	: callback_pieza_eliminada(callback_pieza_eliminada_), estilo(clasico), situacion(NINGUNA_CLICKEADA)
{
	inicializa();
	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila)
			casilla.register_on_click(std::bind(&Tablero::clicks, this, std::placeholders::_1));
}

Tablero::~Tablero() {
	// Las piezas de las casillas se eliminan solas
	// Eliminar resto de cosas manualmente
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

	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila);
			//casilla.register_on_callback(std::bind(&Tablero::Clicks, &this);

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
	casilla(3, 7).setPieza(new Reina(negra, clasico));
	//Reyes
	casilla(4, 0).setPieza(new Rey(blanca, clasico));
	casilla(4, 7).setPieza(new Rey(negra, clasico));

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
	// Será peon?
	Peon* pza_as_peon = dynamic_cast<Peon*>(pza);
	if (pza_as_peon) { // Resulta que sí que era un peón
		if (abs(origen.y - destino.y) == 1) pza_as_peon->estado = Peon::se_ha_movido_normalmente;
		if (abs(origen.y - destino.y) == 2) pza_as_peon->estado = Peon::movimiento_paso_doble;
	}
	callback_pieza_eliminada(quitar_pieza(destino));
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
	case peon: {
		Peon* peon = dynamic_cast<Peon*>(pza_p);
		for (char j = -1; j <= 1; j++) {
			// Aquí se comprueban posiciones por delante del peon (es lo habitual)
			Posicion a_revisar = { p.x + j, p.y + (pza_p->get_color() == blanca ? 1 : -1) };
			if (es_posicion_valida(a_revisar)) {
				Pieza* otra_pieza = obtener_pieza_en(a_revisar);
				if ((j != 0) && (otra_pieza))
					resultado(a_revisar) = atacable;
				if ((j == 0) && (otra_pieza))
					resultado(a_revisar) = no_movible;
				if ((j == 0) && (!otra_pieza)) { // No hay pieza justo delante
					resultado(a_revisar) = si_movible;
					if (peon->estado == Peon::sin_moverse) { // Se puede primer movimiento de dos casillas
						Posicion a_revisar = { p.x, p.y + (pza_p->get_color() == blanca ? 2 : -2) };
						if (es_posicion_valida(a_revisar)) {
							Pieza* otra_pieza = obtener_pieza_en(a_revisar);
							if (otra_pieza)
								resultado(a_revisar) = no_movible;
							else // No hay pieza dos delante
								resultado(a_revisar) = si_movible;
						}
					}
				}
			}
		}
		// En passant
		for (char j = -1; j <= 1; j += 2) {
			// Posiciones laterales (en passant)
			Posicion a_revisar = { p.x + j, p.y };
			if (es_posicion_valida(a_revisar)) {
				Pieza* otra_pieza = obtener_pieza_en(a_revisar);
				Peon* otra_pieza_as_peon = dynamic_cast<Peon*>(otra_pieza);
				if (otra_pieza_as_peon and otra_pieza_as_peon->estado == Peon::movimiento_paso_doble) {
					resultado(a_revisar) = atacable;
					resultado(a_revisar.x, a_revisar.y + (pza_p->get_color() == blanca ? 1 : -1) ) = comible_en_passant;
				}
			}
		}
	} break;
	case torre:	{
		for (char i = 1; i <= 7; i++) { // Hacia X+
			Posicion a_revisar = { p.x + i, p.y };
			if (!es_posicion_valida(a_revisar)) break; // Fuera del tablero
			Pieza* otra_pieza = obtener_pieza_en(a_revisar);
			if (otra_pieza and otra_pieza->get_color() != pza_p->get_color()) { // Existe pieza enemiga en la casilla
				resultado(a_revisar) = atacable;
			}
			if (otra_pieza) break; // Da igual la pieza, salimos del bucle
			resultado(a_revisar) = si_movible; // Si llega hasta aquí es pq se puede
		}
		for (char i = 1; i <= 7; i++) { // Hacia X-
			Posicion a_revisar = { p.x - i, p.y };
			if (!es_posicion_valida(a_revisar)) break; // Fuera del tablero
			Pieza* otra_pieza = obtener_pieza_en(a_revisar);
			if (otra_pieza and otra_pieza->get_color() != pza_p->get_color()) { // Existe pieza enemiga en la casilla
				resultado(a_revisar) = atacable;
			}
			if (otra_pieza) break; // Da igual la pieza, salimos del bucle
			resultado(a_revisar) = si_movible; // Si llega hasta aquí es pq se puede
		}
		for (char i = 1; i <= 7; i++) { // Hacia Y+
			Posicion a_revisar = { p.x, p.y + i };
			if (!es_posicion_valida(a_revisar)) break; // Fuera del tablero
			Pieza* otra_pieza = obtener_pieza_en(a_revisar);
			if (otra_pieza and otra_pieza->get_color() != pza_p->get_color()) { // Existe pieza enemiga en la casilla
				resultado(a_revisar) = atacable;
			}
			if (otra_pieza) break; // Da igual la pieza, salimos del bucle
			resultado(a_revisar) = si_movible; // Si llega hasta aquí es pq se puede
		}
		for (char i = 1; i <= 7; i++) { // Hacia Y-
			Posicion a_revisar = { p.x, p.y - i };
			if (!es_posicion_valida(a_revisar)) break; // Fuera del tablero
			Pieza* otra_pieza = obtener_pieza_en(a_revisar);
			if (otra_pieza and otra_pieza->get_color() != pza_p->get_color()) { // Existe pieza enemiga en la casilla
				resultado(a_revisar) = atacable;
			}
			if (otra_pieza) break; // Da igual la pieza, salimos del bucle
			resultado(a_revisar) = si_movible; // Si llega hasta aquí es pq se puede
		}
	} break;
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

void Tablero::actualizar_casillas_desde_mascara(Mascara_tablero& msk) {
	for (char x = 0; x < 8; ++x)
		for (char y = 0; y < 8; ++y) {
			casilla(x, y).estado = mascara_calculos(x, y);
		}
}


void Tablero::mouse(int button, int state, GLdouble x, GLdouble y) {
	for (auto& casilla_fila : casillas)
		for (auto& casilla : casilla_fila)
			casilla.mouse(button, state, x, y);

	//casilla.register_on_callback(std::bind(&Tablero::Clicks, &this);
	// FALTA LO DE ARRIBA
}

void Tablero::clicks(Posicion position)
{
	switch (situacion)
	{
	case NINGUNA_CLICKEADA: {
		situacion = PRIMERA_CLICKEADA;
		primer_clickeada = position;
		calculadora_movimientos(position, mascara_calculos);
		casilla(position).setSeleccionada(true);
	} break;

	case PRIMERA_CLICKEADA: {
		casilla(primer_clickeada).setSeleccionada(false);
		mover_pieza(primer_clickeada, position);
		situacion = NINGUNA_CLICKEADA;
		mascara_calculos.reset();
	} break;
	}
	actualizar_casillas_desde_mascara(mascara_calculos);
	// se debe iluminar
	// si es ninguna clickeada, se guarda en posicion la posicion clickeada, si ha sido clikeada, se llamada a la función mover piezas
}
