#pragma once

#include "freeglut.h"

#include <functional>

class BotonUI {
private:
	float x_lo_bound, y_lo_bound, x_hi_bound, y_hi_bound, x_text, y_text, scale_text;
	const unsigned char* text;
	std::function<void()> click_callback;
public:
	BotonUI(const unsigned char* txt, float x_txt, float y_txt, float scale_txt,
		float x_lo, float y_lo, float x_hi, float y_hi)
		: click_callback{ nullptr }, text{ txt }, x_text{ x_txt }, y_text{ y_txt }, scale_text{ scale_txt },
		x_lo_bound{ x_lo }, y_lo_bound{ y_lo }, x_hi_bound{ x_hi }, y_hi_bound{ y_hi } {
		// A partir de la cadena de texto se podrían deducir varias variables,
		// pero habría que comprobar muchas propiedades del renderizado.
		// TODO: maybe?
	}


	//BotonUI(float x_lo, float y_lo, float x_hi, float y_hi):click_callback{ nullptr }, 	x_lo_bound{ x_lo }, y_lo_bound{ y_lo }, x_hi_bound{ x_hi }, y_hi_bound{ y_hi } {	}
	
	
	
	void ilustra();
	void mouse(int button, int state, GLdouble x, GLdouble y);
	void register_on_click(std::function<void()>func) { click_callback = func; }
};
