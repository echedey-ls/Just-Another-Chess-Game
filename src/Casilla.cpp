#include "Casilla.h"

char Casilla::casillas_counter = 0;

void Casilla::ilustrar() {

	//Posicion p = getPosicion();
	//pieza->cargar_sprite();
	if (pieza != nullptr) pieza->ilustrar(pos);
	
	//PINTAR BASE DE ALGUN COLOR ------------------> pendiente!!!
	//(1) BORDE AMARILLO -- casilla seleccionada
	//(2) RELLENO AMARILLO -- posibles movimientos
	//(3) BORDE ROJO -- casilla donde comer

}

Posicion Casilla::getPosicion() {
	return pos;
}

inline
void Casilla::setSeleccionada(bool select) {

	seleccionada = select;

}

inline
bool Casilla::getSeleccionada() {

	return seleccionada;

}
