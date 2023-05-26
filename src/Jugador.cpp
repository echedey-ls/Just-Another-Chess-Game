#include "Jugador.h"

Jugador::Jugador() {
	color = 0;
	es_mi_turno = false;
	piezas_comidas = 0;
}

void Jugador::cambiar_turno() {
	if (es_mi_turno == false)
		es_mi_turno = true;
	es_mi_turno = false;
}