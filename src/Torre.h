#pragma once

#include "ETSIDI.h"
#include "freeglut.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Torre
{
public:
	float x, y;

	Sprite* sprite;
	SpriteSequence* animacion;

	void dibuja();
};

