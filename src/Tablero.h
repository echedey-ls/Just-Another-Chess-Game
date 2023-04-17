#pragma once

#include <vector>
#include <string>

#include "ETSIDI.h"
#include "Piezas.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Tablero
{
	std::vector<Pieza> piezas;


public:
	Tablero(); // Inicializa tablero con sus piezas distribuidas en un juego normal
	void creador();
	void dibuja();
	Sprite* sprite1, * sprite2, * sprite3;
	SpriteSequence* animacion;
	SpriteSequence* explosion;
};

