#include "Piezas.h"
#include "ETSIDI.h"
#include"piezas/Peon.h"
#include <string>

using namespace ETSIDI;

void Pieza::ilustrar(Posicion p) {
	// imprimir sprite tal cual
	sprite_ptr->setPos(4 + (8 * p.x), 4 + (8 * p.y)); //!!PROBLEMA CONVERSION int float
	sprite_ptr->draw();
}

void Pieza::cambiar_estilo(Estilo_grafico estilo) {
	// *elimina* y vuelve a cargar el sprite, con el nuevo tema gráfico (si es distinto del anterior)
	// y actualiza el estilo de la instancia
	if (estilo != estilo_actual) estilo = estilo_actual;
}

void Pieza::cargar_sprite() {
	// Carga el sprite (aquí se obtiene el path a la imagen y se añade un "new" objeto sprite al puntero)
	// Atención: revisar si había uno cargado ya

	auto png_path = std::string("imagenes/");

	// Prefijo estilo
	if (estilo_actual == clasico or estilo_actual == no_definido) png_path += "c";
	else if (estilo_actual == stars_wars) png_path += "sw";
	png_path += "_";

	// Tipo pieza
	switch (tipo)
	{
	case rey:
		png_path += "rey";
		break;
	case reina:
		png_path += "reina";
		break;
	case alfil:
		png_path += "alfil";
		break;
	case torre:
		png_path += "torre";
		break;
	case caballo:
		png_path += "caballo";
		break;
	case peon:
		png_path += "peon";
		break;
	case desconocido:
	default:
		png_path += "unknown";
		break;
	}
	png_path += "_";

	// Sufijo color
	if (color == blanca) png_path += "b";
	else if (color == negra) png_path += "n";

	// Extension archivo
	png_path += ".png";

	// Si hay que actualizar sprite
	if (sprite_ptr != nullptr) {
		delete sprite_ptr; //BORRAR SPRITE ANTERIOR 
	}

	sprite_ptr = new ETSIDI::Sprite(png_path.c_str(), 0, 0, 8, 8);
}