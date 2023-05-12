#pragma once

#include "interfaz_usuario/BotonUI.h"

#include "freeglut.h"

#include <functional>

class Interfaz_Partida {
	BotonUI btn_cambio_graficos{ (unsigned char*)"Cambiar\ntema\ngrafico",
		69.f, 10.f, 0.02f, 68.5f, 2.7f, 79.5f, 13.f};

public:
	Interfaz_Partida(std::function<void()>callback_cambio_graficos);
	~Interfaz_Partida();
	void dibuja();
	void mouse(int button, int state, GLdouble x, GLdouble y);
};

