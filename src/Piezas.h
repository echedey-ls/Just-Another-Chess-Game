#pragma once

#include <iostream>

// structura de la posicion
struct Posicion {
	unsigned char x, y;
	bool operator==(const Posicion &other) { return x == other.x and y == other.y; }
	Posicion(unsigned char x_, unsigned char y_) : x{x_}, y{y_} {};
	Posicion(Posicion&& other) noexcept : x{other.x}, y{other.y} {};

};

// Par de enumeraciones con los valores que pueden tomar las piezas
enum Color {
	blanca,
	negra,
};
enum Tipo { rey, reina, alfil, torre, caballo, peon };

class Pieza {
	Color color;
	Tipo tipo;
	Posicion pos;

public:
	Pieza(Color c, Tipo t, unsigned char x, unsigned char y) : color{c}, tipo{t}, pos{x, y} {};
};
