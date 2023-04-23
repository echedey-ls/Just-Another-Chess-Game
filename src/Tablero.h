#pragma once

#include <vector>
#include <string>

#include "ETSIDI.h"
#include "Piezas.h"
#include "Posicion.h"
#include "Estilos_graficos.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Tablero
{
	std::vector<Piezas> piezas;
	Estilo_grafico estilo;

	Piezas* v_piezas[32];

public:
	Tablero(); // Inicializa tablero con sus piezas distribuidas en un juego normal
	void dibuja();
	Pieza* obtener_pieza_en(Posicion p);

	Sprite tablero{ "imagenes/tablero.png",0,0,64,64 };

	Sprite reina_b{ "imagenes/reina_b.png",0,0,8,8 };
	Sprite rey_b{ "imagenes/rey_b.png",0,0,8,8 };
	Sprite torre_b{ "imagenes/torre_b.png",0,0,8,8 };
	Sprite caballo_b{ "imagenes/caballo_b.png",0,0,8,8 };
	Sprite alfil_b{ "imagenes/alfil_b.png",0,0,8,8 };
	Sprite peon_b{ "imagenes/peon_b.png",0,0,8,8 };

	Sprite reina_n{ "imagenes/reina_n.png",0,0,8,8 };
	Sprite rey_n{ "imagenes/rey_n.png",0,0,8,8 };
	Sprite torre_n{ "imagenes/torre_n.png",0,0,8,8 };
	Sprite caballo_n{ "imagenes/caballo_n.png",0,0,8,8 };
	Sprite alfil_n{ "imagenes/alfil_n.png",0,0,8,8 };
	Sprite peon_n{ "imagenes/peon_n.png",0,0,8,8 };
	
};

