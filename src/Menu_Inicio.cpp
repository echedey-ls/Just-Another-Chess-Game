#include "Menu_Inicio.h"

void Menu_Inicio::dibuja() {
	// Salimos de la operación de dibujo si no está activo el menú
	if (estado == inactivo) return;
	// Dibujar todo lo constante del menú
	logotipo->draw();

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
}
