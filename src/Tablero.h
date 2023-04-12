#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
class Tablero
{
public:
	void creador();
	void dibuja();
	Sprite* sprite1, * sprite2, * sprite3;
	SpriteSequence* animacion;
	SpriteSequence* explosion;
};

