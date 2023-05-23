#pragma once

#include <functional>

class Boton_generico {
protected:
	float x_lo_bound, y_lo_bound, x_hi_bound, y_hi_bound;
	std::function<void()> click_callback;
	bool _hovered;
	// El click se define como presionado dentro y después soltado, también dentro
	int _last_state;
public:
	Boton_generico(float x_lo, float y_lo, float x_hi, float y_hi)
		: click_callback{ nullptr }, _hovered { false }, _last_state { -1 },
		x_lo_bound{ x_lo }, y_lo_bound{ y_lo }, x_hi_bound{ x_hi }, y_hi_bound{ y_hi } {}
	void mouse(int button, int state, double x, double y);
	void register_on_click(std::function<void()>func) { click_callback = func; }
	bool is_hovered() { return _hovered; }
	void set_limits(float x_lo, float y_lo, float x_hi, float y_hi) {

		x_lo_bound = x_lo;
		y_lo_bound = y_lo;
		x_hi_bound = x_hi;
		y_hi_bound = y_hi;
	}
};

