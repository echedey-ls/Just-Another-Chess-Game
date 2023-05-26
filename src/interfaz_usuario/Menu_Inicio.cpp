#include "Menu_Inicio.h"

void Menu_Inicio::dibuja() {

	// Específico del estado del mundo
	switch (estado)
	{
	case Menu_Inicio::inactivo:
		break;
	case Menu_Inicio::select_void:
		inicio->draw();
		break;
	case Menu_Inicio::select_jugar_pvp:
		jugar->draw();
		break;
	case Menu_Inicio::select_salir:
		salir->draw();
		break;
	default:
		break;
	}

}

void Menu_Inicio::mouse(int button, int state, double x, double y) {
	if (estado == inactivo) return;
	btn_jugar.mouse(button, state, x, y);
	btn_salir.mouse(button, state, x, y);

	if (btn_jugar.is_hovered()) {
		estado = select_jugar_pvp;
	}
	else if (btn_salir.is_hovered()) {
		if (estado!= select_salir)
			ETSIDI::play("sonidos/Sonido_game_over.mp3");
		estado = select_salir;
	}
	else estado = select_void;
}

