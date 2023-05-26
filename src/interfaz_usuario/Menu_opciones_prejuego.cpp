#include "Menu_opciones_prejuego.h"

#include "freeglut.h"
#include "ETSIDI.h"

void Menu_opciones_prejuego::dibuja() {
	char txt_wh[12] = "  Blancas";
	char txt_bk[12] = "  Negras";
	switch (estado)
	{
	case Menu_opciones_prejuego::NO_VISIBLE:
		return;
	case Menu_opciones_prejuego::NO_HIGLIGHT:
		break;
	case Menu_opciones_prejuego::HIGHLIGHT_BLANCAS:
		txt_wh[0] = '>';
		break;
	case Menu_opciones_prejuego::HIGHLIGHT_NEGRAS:
		txt_bk[0] = '>';
		break;
	}
	glPushMatrix();
	glTranslatef(x_offset, y_offset, 0.f);
	//glScalef(text_scaling, text_scaling, text_scaling);
	//glutStrokeString(GLUT_STROKE_MONO_ROMAN, )
	//glScalef(1/text_scaling, 1/text_scaling, 1/text_scaling);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Elige el color de tus fichas:", 0, 0);
	glTranslatef(8, 0.f, 0.f);
	ETSIDI::printxy(txt_wh, 0, -8);
	ETSIDI::printxy(txt_bk, 0, -16);

	glPopMatrix();
}

void Menu_opciones_prejuego::mouse(int button, int state, double x, double y) {
	if (estado == NO_VISIBLE) return;
	btn_blancas.mouse(button, state, x, y);
	btn_negras.mouse(button, state, x, y);
	if (btn_blancas.is_hovered()) estado = HIGHLIGHT_BLANCAS;
	else if (btn_negras.is_hovered()) estado = HIGHLIGHT_NEGRAS;
}
