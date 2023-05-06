#pragma once
#include "Tablero.h"
#include "Mascara_tablero.h"
class Mundo
{
public:
	void inicializa();
	void dibuja();
	void ilumina_casilla();

	Tablero tablero;

	float x_ojo;
	float y_ojo;
	float z_ojo;
};

