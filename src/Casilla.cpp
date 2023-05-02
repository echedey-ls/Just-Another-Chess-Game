#include "Casilla.h"

int Casilla::casillas_counter = 0;

void Casilla::ilustrar() {
	//Posicion p = getPosicion();
	//pieza->cargar_sprite();
	if (pieza != nullptr) pieza->ilustrar(pos);
	
	//PINTAR BASE DE ALGUN COLOR 
	//(1) BORDE AMARILLO -- casilla seleccionada
	//(2) RELLENO AMARILLO -- posibles movimientos
	//(3) BORDE ROJO -- casilla donde comer

}

Posicion Casilla::getPosicion() {
	return pos;
}