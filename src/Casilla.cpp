#include "Casilla.h"

#include <iostream>
#include "freeglut.h"

char Casilla::casillas_counter = 0;

void Casilla::ilustrar() {


	//bool select; 
	//atributo para determinar si debe mostrarse la seleccion

	//Posicion p = getPosicion();
	//pieza->cargar_sprite();
	if (pieza != nullptr) pieza->ilustrar(pos);
	
	//PINTAR BASE DE ALGUN COLOR ------------------> pendiente!!!
	//(1) BORDE AMARILLO -- casilla seleccionada
	//(2) RELLENO AMARILLO -- posibles movimientos
	//(3) BORDE ROJO -- casilla donde comer


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Given the coordinates
	gluOrtho2D(0.0, 800.0,
		0.0, 600.0);

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(8);
	glPopMatrix();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-5.0f, -5.0f, 1); // top left
	glVertex3f(-5.0f, 5.0f, 1); // top right
	glVertex3f(5.0f, 5.0f, 1); // bottom right
	glVertex3f(5.0f, -5.0f, 1); // bottom left
	glEnd();
	glFlush();

}

void Casilla::no_ilustrar() {
	ilus = false;
}

Posicion Casilla::getPosicion() {
	return pos;
}

inline
void Casilla::setSeleccionada(bool select) {

	seleccionada = select;

}

inline
bool Casilla::getSeleccionada() {

	return seleccionada;

}

void Casilla::mouse(int button, int state, GLdouble x, GLdouble y) {
	//float x_lo_bound = 625, x_hi_bound =  625, y_lo_bound = 625, y_hi_bound = 625;
	// El click se define como presionado dentro y después soltado, también dentro
	/*static int last_state = -1;
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
	*/
	btn_casilla.mouse(button, state, x, y);
}