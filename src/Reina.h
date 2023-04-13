#pragma once
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Reina
{
public:
	float x;
	float y;
	Sprite* sprite;
	SpriteSequence* animacion;
	void creador();
	void dibuja();
	void mueve();
};

