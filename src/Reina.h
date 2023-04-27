#pragma once
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Reina
{
public:
	Vector2D pos;
	Sprite* reinaSprite;
	SpriteSequence* animacion;
	void creador();
	void dibuja();
	void setPos(int x, int y);
	void mueve();
};

