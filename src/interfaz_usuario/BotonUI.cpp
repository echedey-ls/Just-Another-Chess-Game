#include "BotonUI.h"

#include <iostream>

void BotonUI::ilustra() {
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	glVertex2f(x_lo_bound, y_lo_bound);
	glVertex2f(x_hi_bound, y_lo_bound);
	glVertex2f(x_hi_bound, y_hi_bound);
	glVertex2f(x_lo_bound, y_hi_bound);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x_text, y_text, 0.0f);
	glScalef(scale_text, scale_text, scale_text);
	glutStrokeString(GLUT_STROKE_ROMAN, text);

	glPopMatrix();
}

void BotonUI::mouse(int button, int state, GLdouble x, GLdouble y) {
	// El click se define como presionado dentro y después soltado, también dentro
	static int last_state = -1;
	if (button == GLUT_LEFT_BUTTON // Solo analizamos click izq dentro de los límites
		  and (x_lo_bound <= x) and (x <= x_hi_bound)
			and (y_lo_bound <= y) and (y <= y_hi_bound)) {
		std::cout << "got here first" << std::endl;
		if (state == GLUT_UP
			  and last_state == GLUT_DOWN) {
			click_callback();
			std::cout << "got here second" << std::endl;
		}
		last_state = state;
	}
}
