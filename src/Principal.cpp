#include "freeglut.h"
#include <math.h>
#include <iostream>
#include "Mundo.h"
#include "ETSIDI.h"
#include "Posicion.h"

Mundo mundo;

//declaraciones de funciones

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void mouse(int button, int state, int x, int y); //devuelve la clase posicion??

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Just Another Chess Game");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(mouse); //llama a la función del ratón

	mundo.inicializa();

	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	mundo.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado

	if (key == '1')
		ETSIDI::play("sonidos/Bala.mp3");
	if (key == '2')
		ETSIDI::playMusica("sonidos/JasonMraz93Milles.mp3");
	if (key == '3')
		ETSIDI::stopMusica();
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "posicion del raton1: (" << x << "," << y << ")" << endl;
		//cout << "posicion del raton2: (" << (x - 274) / 65 << "," << (y - 74) / 65 << ")" << endl;
		
		// ancho (x):  137 en cada borde   274, 65 cada cuadrado
		// alto (y): 37 en cada borde  74 , 65 cada cuadrado
		//cuadrado de 65x65
		// tamaño del tablero: 525x525
		//pantalla 800x600

		if (x > 137 && x < (137 + 525) && y>37 && y < (37 + 525)) {
			cout << "estoy dentro del tablero" << endl;
		}
		else
			cout << "estoy fuera del tablero" << endl;
		
		//Calcular el cuadrante

		char x_casilla, y_casilla;

		x_casilla = static_cast<char>((x - 137) / 65);
		y_casilla = static_cast<char>((563 - y) / 65);

		cout << "posicion del nuevo: (" << (int)x_casilla <<"," << (int)y_casilla << ")" << endl;
	}
}

void OnTimer(int value)
{
	//poner aqui el código de animacion
	/*
	float dist = sqrt(mundo.x_ojo * mundo.x_ojo + mundo.z_ojo * mundo.z_ojo);
	float ang = atan2(mundo.z_ojo, mundo.x_ojo);
	ang += 0.05f;
	mundo.x_ojo = dist * cos(ang);
	mundo.z_ojo = dist * sin(ang);
	*/


	/*
	animacion->loop();
	explosion->loop();*/


	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}