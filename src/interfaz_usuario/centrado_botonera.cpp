#include "centrado_botonera.h"


//Botonera menu inicio
	//JUGAR-> xmin=23.5, xmax=39, ymin=15.5, ymax=20
	//SALIR-> xmin=23.5, xmax=39, ymin=9.5, ymax=14

void centrado_botonera::dibuja() {
	//glClear(GL_COLOR_BUFFER_BIT);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);

	// Cuadrado jugar
	//xmin=23.5, xmax=39, ymin=15.5, ymax=20
	glColor4f(0.23, 0.78, 0.32, 0.70);
	glBegin(GL_QUADS);
	glVertex2f(23.5, 20);
	glVertex2f(39, 20);
	glVertex2f(39, 15.5);
	glVertex2f(23.5, 15.5);
	glEnd();

	// Cuadrado salir
	//xmin=23.5, xmax=39, ymin=9.5, ymax=14
	glColor4f(128, 0, 0, 0.70);
	glBegin(GL_QUADS);
	glVertex2f(23.5, 14);
	glVertex2f(39, 14);
	glVertex2f(39, 9.5);
	glVertex2f(23.5, 9.5);
	glEnd();


}

