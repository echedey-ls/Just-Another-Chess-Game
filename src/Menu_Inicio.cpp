#include "Menu_Inicio.h"

void Menu_Inicio::dibuja() {
	
	// Específico del estado del mundo
	switch (estado)
	{
	case Menu_Inicio::inactivo:
		break;
	case Menu_Inicio::select_void:
		break;
	case Menu_Inicio::select_jugar_pvp:
		break;
	case Menu_Inicio::select_salir:
		break;
	default:
		break;
	}

	// Dibujar todo lo constante del menú
	inicio->draw();

}

void Menu_Inicio::mouse(int button, int state, double x, double y) {
	if (estado == inactivo) return;
	btn_jugar.mouse(button, state, x, y);
	btn_salir.mouse(button, state, x, y);

	if (btn_jugar.is_hovered()) estado = select_jugar_pvp;
	else if (btn_salir.is_hovered()) estado = select_salir;
}

