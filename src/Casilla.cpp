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
void Casilla::primer_mov_hecho() {
	if (get_primer_mov() == false)
		set_primer_mov(true);
}
bool Casilla::get_primer_mov() {
	return primer_mov;
}
void Casilla::set_primer_mov(bool mov1) {
	primer_mov = mov1;
}

