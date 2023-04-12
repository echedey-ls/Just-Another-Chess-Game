#include "Tablero.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

void Tablero::creador()
{
	sprite1 = new Sprite("imagenes/r2d2.png", 0.05, 0.05, 5, 5);
	sprite2 = new Sprite("imagenes/reina.png", 0.05, 0.05, 5, 5);
	sprite3 = new Sprite("imagenes/tablero.png", 0.05, 0.05, 38, 38);
}

void Tablero::dibuja()
{
	sprite3->draw();
	glTranslated(2.5, -16, 0.05);
	sprite1->draw();
	glTranslated(4.5, -0.5, 0);
	sprite2->draw();
	glTranslated(-2.5, 16, -0.05);
}