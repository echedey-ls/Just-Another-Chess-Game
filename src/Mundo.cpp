#include "Mundo.h"
#include "Tablero.h"
#include "freeglut.h"

#include <iostream>

void Mundo::inicializa()
{
	x_ojo = 32;
	y_ojo = 32;
	z_ojo = 100;

	menu_inicio.estado = Menu_Inicio::select_void;
	tablero.inicializa();
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo,y_ojo,0.0,            // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);             // definimos hacia arriba (eje Y)


	// Esto es guarro, hay que hacer una máquina de estados (mediante enum o algo así)
	menu_inicio.dibuja();
	//tablero.dibuja();
	//gui_partida.dibuja();
	//menu_opts_prejuego.dibuja();
}

void Mundo::mouse(int button, int state, int x, int y) {
	// Usamos gluUnProject para trabajar con coordenadas del mundo en vez de gráficas
	// Copia sin remordimientos de http://nehe.gamedev.net/article/using_gluunproject/16013/index.html
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY; //, winZ;
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


	if (state == GLUT_UP) {
		std::cout << "Posición en coordenadas del mundo x, y, z: " << posX << ", " << posY << ", " << posZ << std::endl;
	}
	gui_partida.mouse(button, state, posX, posY);

	menu_opts_prejuego.mouse(button, state, posX, posY);
	tablero.mouse(button, state, posX, posY);

}
