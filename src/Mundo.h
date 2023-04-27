#pragma once
#include "Tablero.h"
class Mundo
{
public:
	void inicializa();
	void creador();
	void actualiza();

	Tablero tablero;

	float x_ojo;
	float y_ojo;
	float z_ojo;
};

