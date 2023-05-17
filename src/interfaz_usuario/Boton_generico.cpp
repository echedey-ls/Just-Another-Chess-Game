#include "Boton_generico.h"

#include "freeglut.h"

void Boton_generico::mouse(int button, int state, double x, double y) {
	_hovered = (x_lo_bound <= x) and (x <= x_hi_bound) and (y_lo_bound <= y) and (y <= y_hi_bound);
	if (button == GLUT_LEFT_BUTTON // Solo analizamos click izq dentro de los límites
		  and _hovered) {
		if (state == GLUT_UP
			and _last_state == GLUT_DOWN
			and click_callback) {
			click_callback();
		}
		_last_state = state;
	}
}
