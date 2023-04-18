#include "Torre.h"
#include "ETSIDI.h"
#include "freeglut.h"

void Torre::dibuja() 
{
	SpriteSequence sprite{ "torre_b.png", 5 };
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);


}


