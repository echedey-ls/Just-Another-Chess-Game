#include "Letras_tablero.h"

void Letras_tablero::cadena_letras() {
	//Cadena inferior
	char letra = 'A';
	float x = 80.0f;
	while (letra <= 'H') {
		glPushMatrix();
		glScalef(0.035f, 0.035f, 1);
		glTranslatef(x, -100.0f, 1.f);
		glColor3ub(255, 255, 255);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, letra);
		glPopMatrix();
		x = x + 226.0f;
		letra++;
	}

	//Cadena superior
	letra = 'A';
	x = 80.0f;
	while (letra <= 'H') {
		glPushMatrix();
		glScalef(0.035f, 0.035f, 1);
		glTranslatef(x, 1830.0f, 1.f);
		glColor3ub(255, 255, 255);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, letra);
		glPopMatrix();
		x = x + 226.0f;
		letra++;
	}
}

void Letras_tablero::cadena_numeros() {
	//Cadena izquierda
	int num = '1';
	float y = 50.0f;
	while (num <= '8') {
		glPushMatrix();
		glScalef(0.035f, 0.035f, 1);
		glTranslatef(-80.f, y, 1.f);
		glColor3ub(255, 255, 255);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, num);
		glPopMatrix();
		y = y + 226.0f;
		num++;
	}

	//Cadena derecha
	num = '1';
	y = 50.0f;
	while (num <= '8') {
		glPushMatrix();
		glScalef(0.035f, 0.035f, 1);
		glTranslatef(1830.f, y, 1.f);
		glColor3ub(255, 255, 255);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, num);
		glPopMatrix();
		y = y + 226.0f;
		num++;
	}

}
