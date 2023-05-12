#include "freeglut.h"
#include <math.h>
#include <iostream>
#include "Mundo.h"
#include "ETSIDI.h"
#include "Posicion.h"

Mundo mundo;
bool mouse_si_no = false;

// Callbacks
void OnDraw(void); // esta funcion sera llamada para dibujar
void OnTimer(int value); // esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); // cuando se pulse una tecla	
void mouse(int button, int state, int x, int y); // delega en los objetos el tratamiento de los clicks
void reshape(GLsizei, GLsizei);

// Config global del entorno de OpenGL
void initGL() {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Just Another Chess Game");

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutReshapeFunc(reshape);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(mouse); //llama a la función del ratón

	initGL();
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

	/*
	// Superficie cuadrada de fondo para calcular posiciones en XY homogéneamente
	// si se omite, la coord. Z varía mucho y los botones pueden no funcionar
	glColor3f(0.5f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	constexpr GLfloat MIN_LIM = 
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(64.0f, 0.0f, 0.0f);
		glVertex3f(64.0f, 64.0f, 0.0f);
		glVertex3f(0.0f, 64.0f, 0.0f);
	glEnd();*/

	// El juego
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

	if (key == 'e')
		glutHideWindow();  //para ocultar del programa

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	mundo.mouse(button, state, x, y);

}

void OnTimer(int value)
{

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

// Inspirado de https://www3.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html
// De alguna forma sin esto la ventana no imprime correctamente
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
