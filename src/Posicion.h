#pragma once

// structura de la posicion
struct Posicion {
	char x, y;
	bool operator==(const Posicion& other) { return x == other.x and y == other.y; }
	Posicion& operator= (const Posicion& other) { x = other.x, y = other.y; return *this; }
	Posicion(char x_, char y_) : x{ x_ }, y{ y_ } {};
	Posicion(const Posicion& other) noexcept : x{ other.x }, y{ other.y } {};
	Posicion(Posicion&& other) noexcept : x{ other.x }, y{ other.y } {};
};
