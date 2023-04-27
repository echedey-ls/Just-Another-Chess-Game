#pragma once
#include "ETSIDI.h"
#include "Reina.h"

using namespace ETSIDI;
using ETSIDI::getTexture;
class Tablero
{
public:
	Reina reina;
	void creador();
	void dibuja();
	void actualiza();
	Sprite* sprite1, * sprite2, * sprite3;
	SpriteSequence* animacion;
	SpriteSequence* explosion;
};

