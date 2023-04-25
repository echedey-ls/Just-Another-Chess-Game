#pragma once

// structura de la posicion
struct Posicion {
	unsigned char x, y;
	bool operator==(const Posicion& other) { return x == other.x and y == other.y; }
	Posicion(unsigned char x_, unsigned char y_) : x{ x_ }, y{ y_ } {};
	Posicion(const Posicion& other) noexcept : x{ other.x }, y{ other.y } {};
	Posicion(Posicion&& other) noexcept : x{ other.x }, y{ other.y } {};
};
