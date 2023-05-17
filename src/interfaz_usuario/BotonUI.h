#pragma once

#include "Boton_generico.h"

#include <functional>

class BotonUI: public Boton_generico {
private:
	float x_text, y_text, scale_text;
	const unsigned char* text;
public:
	BotonUI(const unsigned char* txt, float x_txt, float y_txt, float scale_txt,
		float x_lo, float y_lo, float x_hi, float y_hi)
		: text{ txt }, x_text{ x_txt }, y_text{ y_txt }, scale_text{ scale_txt },
		Boton_generico(x_lo, y_lo, x_hi, y_hi) {
		// A partir de la cadena de texto se podrían deducir varias variables,
		// pero habría que comprobar muchas propiedades del renderizado.
		// TODO: maybe?
	}
	void ilustra();
};
