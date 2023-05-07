#include "Menu_Inicio.h"

void Menu_Inicio::dibuja() {
	// Salimos de la operaci�n de dibujo si no est� activo el men�
	if (estado == inactivo) return;
	// Dibujar todo lo constante del men�
	logotipo->draw();

	// Espec�fico del estado del mundo
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
