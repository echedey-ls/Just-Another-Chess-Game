#include "Piezas.h"
#include "ETSIDI.h"
#include"piezas/Peon.h"
#include "piezas/Torre.h"
#include "piezas/Alfil.h"
#include <string>

using namespace ETSIDI;

void Pieza::ilustrar() {
	// Dibuja según estilo del atributo
	switch (estilo_actual)
	{
	case no_definido:
		break;
	case clasico:
		sprite_ptr_cl->draw();
		break;
	case stars_wars:
		sprite_ptr_sw->draw();
		break;
	default:
		break;
	}
	
}

void Pieza::cambiar_estilo(Estilo_grafico estilo) {
  // Actualiza el estilo como atributo
	estilo_actual = estilo;
}

void Pieza::cargar_sprite() {
	// Carga el sprite (aquí se obtiene el path a la imagen y se añade un "new" objeto sprite al puntero)
	// Atención: revisar si había uno cargado ya

	auto png_path_cl = std::string("imagenes/");
	auto png_path_sw = std::string("imagenes/");

	// Prefijo estilo
	png_path_cl += "c_";
	png_path_sw += "sw_";

	// Tipo pieza
	switch (tipo)
	{
	case rey:
		png_path_cl += "rey";
		png_path_sw += "rey";
		break;
	case reina:
		png_path_cl += "reina";
		png_path_sw += "reina";
		break;
	case alfil:
		png_path_cl += "alfil";
		png_path_sw += "alfil";
		break;
	case torre:
		png_path_cl += "torre";
		png_path_sw += "torre";
		break;
	case caballo:
		png_path_cl += "caballo";
		png_path_sw += "caballo";
		break;
	case peon:
		png_path_cl += "peon";
		png_path_sw += "peon";
		break;
	case desconocido:
	default:
		png_path_cl += "unknown";
		png_path_sw += "unknown";
		break;
	}
	png_path_cl += "_";
	png_path_sw += "_";

	// Sufijo color
	if (color == blanca) png_path_cl += "b", png_path_sw += "b";
	else if (color == negra) png_path_cl += "n", png_path_sw += "n";

	// Extension archivo
	png_path_cl += ".png";
	png_path_sw += ".png";

	sprite_ptr_cl = new ETSIDI::Sprite(png_path_cl.c_str(), 0, 0, 8, 8);
	sprite_ptr_sw = new ETSIDI::Sprite(png_path_sw.c_str(), 0, 0, 8, 8);
}


