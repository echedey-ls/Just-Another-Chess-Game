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

	if (seleccionada) {
		glPushMatrix();
		glTranslatef(pos.x, pos.y, 0);
		glRotatef(30, 1, 1, 1);
		glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
			rand() / (float)RAND_MAX);//color aleatorio
		glutSolidCube(8);
		

		glColor3ub(255, 0, 0);
		glBegin(GL_POLYGON);
		glVertex3f(-5.0f, -5.0f, 1); // top left
		glVertex3f(-5.0f, 5.0f, 1); // top right
		glVertex3f(5.0f, 5.0f, 1); // bottom right
		glVertex3f(5.0f, -5.0f, 1); // bottom left
		glEnd();

		glPopMatrix();
	}
}

void Casilla::no_ilustrar() {
	ilus = false;
}

Posicion Casilla::getPosicion() {
	return pos;
}

void Casilla::setSeleccionada(bool select) {

	seleccionada = select;

}

inline
bool Casilla::getSeleccionada() {

	return seleccionada;

}

void Casilla::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_casilla.mouse(button, state, x, y);
}

void Casilla::mouse_on_click() {
	click_callback(pos);
}
