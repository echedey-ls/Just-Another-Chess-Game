#pragma once
#include "BotonUI.h"

#include "freeglut.h"

#include <functional>
#include <vector>

class Pantalla_guia
{
	//Boton ¿como jugar?
	BotonUI btn_guia_juego{ (unsigned char*)"JEDI,\nNECESITAS\nAYUDA?",
		-19.f, 10.f, 0.02f, -19.5f, 2.7f, -4.5f, 13.f };

public:
	Pantalla_guia(std::function<void(bool)> callback_guia_juego) {
		btn_guia_juego.register_on_click(std::bind(callback_guia_juego, true));
	};
	~Pantalla_guia();

	void dibuja();
	void mouse(int button, int state, GLdouble x, GLdouble y);

	
};

