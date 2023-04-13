#include "Reina.h"
#include "ETSIDI.h"
#include "freeglut.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

void Reina::creador()
{
	sprite = new Sprite("imagenes/reina.png", 0.05, 0.05, 5, 5);
}
void Reina::dibuja()
{
	sprite->draw();
	glTranslated(-2.5, 16, -0.05);
}
void Reina::mueve()
{
	glTranslated(5, 5, -0.05);
}