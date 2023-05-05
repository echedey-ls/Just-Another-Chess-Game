#pragma once
#include "Tablero.h"
#include "Menu_Inicio.h"

class Mundo
{
public:
	void inicializa();
	void dibuja();

	Menu_Inicio menu_inicio;
	Tablero tablero;

	float x_ojo = 0.f;
	float y_ojo = 0.f;
	float z_ojo = 0.f;
};
