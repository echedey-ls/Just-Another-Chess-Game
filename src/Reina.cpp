#include "Reina.h"
#include "ETSIDI.h"
#include "freeglut.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

void Reina::creador()
{
	setPos(0.5, 0.5);
}
void Reina::dibuja()
{
	reinaSprite = new Sprite("imagenes/reina.png", 0.5, 0.5, 5, 5);
	reinaSprite->draw();
}
void Reina::setPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
}
void Reina::mueve()
{
	reinaSprite->setPos(2, 2);
	reinaSprite->draw();
	//dibuja();
}