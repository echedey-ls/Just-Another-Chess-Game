#pragma once

#include <iostream>
using namespace std;

//structura de la posicion
struct Posicion
{
	unsigned char x, y;
};

class Piezas
{
	enum color { blancas, negras };
	enum tipo{rey, reina, alfil, torre, caballo, peon};

	Posicion pos;

	

};

