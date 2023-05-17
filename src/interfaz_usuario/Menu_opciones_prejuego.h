#pragma once

#include "Boton_generico.h"

class Menu_opciones_prejuego {
	const float text_scaling = 0.05f, x_offset = 20.f, y_offset = 40.f;
	Boton_generico
		btn_blancas{ x_offset + 8, y_offset - 10, x_offset + 20, y_offset - 5 },
		btn_negras{ x_offset + 8, y_offset - 20, x_offset + 20, y_offset - 15 };
public:
	enum Estado { NO_VISIBLE, NO_HIGLIGHT, HIGHLIGHT_BLANCAS, HIGHLIGHT_NEGRAS } estado = NO_HIGLIGHT;
	void dibuja();
	void mouse(int button, int state, double x, double y);
};

