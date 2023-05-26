#include "Mundo.h"
#include "Tablero.h"
#include "freeglut.h"

#include <iostream>

Mundo::Mundo() : estado{started} {}

void Mundo::inicializa()
{
	x_ojo = 32;
	y_ojo = 32;
	z_ojo = 100;

	estado = pantalla_inicio;

	menu_inicio.estado = Menu_Inicio::select_void;
	tablero.inicializa();
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo,y_ojo,0.0,            // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);             // definimos hacia arriba (eje Y)

	switch (estado)
	{
	case Mundo::started:
		inicializa();
		break;
	case Mundo::pantalla_inicio:
		menu_inicio.dibuja();
		break;
	case Mundo::pantalla_seleccion_team:
		menu_opts_prejuego.dibuja();
		if (Menu_opciones_prejuego::Estado::HIGHLIGHT_BLANCAS) {
			int c1 = 0;
			int c2 = 1;
			tablero.set_color_jugadores(c1, c2);
		}
		if (Menu_opciones_prejuego::Estado::HIGHLIGHT_NEGRAS) {
			int c1 = 1;
			int c2 = 0;
			tablero.set_color_jugadores(c1, c2);
		}
		break;
	case Mundo::juego:
		tablero.dibuja();
		gui_partida.dibuja();
		break;
	case Mundo::pantalla_guia:
		gui_partida.dibuja_guia();
		break;
	case Mundo::fin_partida:
		break;
	default:
		break;
	}
}

void Mundo::mouse(int button, int state, int x, int y) {
	// Usamos gluUnProject para trabajar con coordenadas del mundo en vez de gráficas
	// Copia sin remordimientos de http://nehe.gamedev.net/article/using_gluunproject/16013/index.html
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY; // , winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	// Queremos la coordenada del plano con z = 0.0
	// Así que obviamos obtener la profundidad de renderizado, y dejamos la que nos devolvería
	//glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, 1.0, modelview, projection, viewport, &posX, &posY, &posZ);

	//GLdouble posX_r, posY_r, posZ_r;
	//gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX_r, &posY_r, &posZ_r);

	if (state == GLUT_UP) {
		std::cout << "R^2 (Z := 0) x = " << posX << ", y = " << posY << ", z" << posZ << std::endl;
		//std::cout << "R^3 (Z real) x = " << posX << ", y = " << posY << ", z" << posZ << std::endl;

	}

	switch (estado)
	{
	case Mundo::started:
		break;
	case Mundo::pantalla_inicio:
		menu_inicio.mouse(button, state, posX, posY);
		break;
	case Mundo::pantalla_seleccion_team:
		menu_opts_prejuego.mouse(button, state, posX, posY);
		break;
	case Mundo::juego:
		tablero.mouse(button, state, posX, posY);
	case Mundo::pantalla_guia:
		gui_partida.mouse(button, state, posX, posY);
		break;
	case Mundo::fin_partida:
		break;
	default:
		break;
	}
}

void Mundo::callback_menu_inicio(bool jugar) {
	if (jugar) {
		estado = pantalla_seleccion_team;
		ETSIDI::play("sonidos/Sonido_game_start.mp3");
	}
	else {
		exit(0);
	}

}

void Mundo::callback_menu_prejuego(bool color_blanco) {
	if (color_blanco) estado = juego;
	else estado = juego;
}

void Mundo::callback_guia_juego() {
	if (estado == juego) estado = pantalla_guia;
	else if (estado == pantalla_guia) estado = juego;
}