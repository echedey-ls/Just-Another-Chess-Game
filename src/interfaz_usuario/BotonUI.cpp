#include "BotonUI.h"

#include "freeglut.h"

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
