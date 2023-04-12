
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
#include <iostream>
#include "src/Mundo.h"

Mundo mundo;

//OGLFT::Monochrome* monochrome;
//TTF::Font *font;
//TTF::Triangulator2DI triangulatorA, triangulatorB;
//declaraciones de funciones

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

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
	mundo.creador();

//aqui es donde hay que poner el c�digo de dibujo

//dibujo del suelo
	/*
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0, -5.0f);
	glVertex3f(-5.0f, 0, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0, 5.0f);
	glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);*/

	/*
	setTextColor(1, 0, 0);
	glTranslated(-10, 0, 0);
	print("OLEEEE FUNCIONAAAAA  :))))))))", "fuentes/Bitwise.ttf", 15);
	setTextColor(1, 1, 0, 0.5);
	glTranslated(5, 5, 1);
	print("hola wenaaas", "fuentes/Bitwise.ttf");
	glPopMatrix();*/



	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado

	if (key == '1')
		play("sonidos/Bala.mp3");
	if (key == '2')
		playMusica("sonidos/JasonMraz93Milles.mp3");
	if (key == '3')
		stopMusica();
	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el c�digo de animacion
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