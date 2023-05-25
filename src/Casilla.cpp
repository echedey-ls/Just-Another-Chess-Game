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

	if (seleccionada or estado != sin_calcular) {
		glPushMatrix();
		glTranslatef(pos.x, pos.y, 0.f);

		//Dependiendo del estado en que se encuentre, la casilla iluminado será de color distinto
		switch (estado)
		{
		case sin_calcular:
			glColor3ub(255, 255, 255); //blanco
		case no_movible:
			glColor3ub(0, 0, 0);    //negro
		case si_movible:
			glColor3ub(0, 255,  0);  //verde
		case atacable:
			glColor3ub(255, 255, 0);  //amarillo
		case prohibida:
			glColor3ub(255, 0, 0); //rojo
		default:
			break;
		}
		
		if (seleccionada) glColor3ub(51, 153, 102);

		glBegin(GL_POLYGON);

		constexpr float side = 8.f;
		constexpr float offset = 0.2f;
		float x_lo = 6.93f * pos.x + offset;
		float y_lo = 6.93f * pos.y + offset;

		glVertex3f(x_lo, y_lo + side, 0);				  // top left
		glVertex3f(x_lo + side, y_lo + side, 0);  // top right
		glVertex3f(x_lo + side, y_lo, 0);         // bottom right
		glVertex3f(x_lo, y_lo, 0);		            // bottom left

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

void Casilla::primer_mov_hecho() {
	if (get_primer_mov() == false)
		set_primer_mov(true);
}
bool Casilla::get_primer_mov() {
	return primer_mov;
}
void Casilla::set_primer_mov(bool mov1) {
	primer_mov = mov1;
}


void Casilla::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_casilla.mouse(button, state, x, y);
}

void Casilla::mouse_on_click() {
	click_callback(pos);
}

