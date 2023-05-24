#pragma once

#include "ETSIDI.h"
#include "interfaz_usuario/Boton_generico.h"


class Menu_Inicio {
	
	ETSIDI::Sprite *inicio;

	//Botonera menu inicio
	//JUGAR-> xmin=23.5, xmax=39, ymin=15.5, ymax=20
	//SALIR-> xmin=23.5, xmax=39, ymin=9.5, ymax=14
	Boton_generico
		btn_jugar{ 23.5, 15.5, 39, 20 },
		btn_salir{ 23.5, 9.5, 39, 14 };

public:
	enum {
		inactivo = 0,
		select_void,
		select_jugar_pvp,
		select_salir,
	} estado = select_void;

	Menu_Inicio() {
		inicio = new ETSIDI::Sprite("imagenes/pantalla_inicio.png", 30.0f, 30.0f, 90, 90);
	};

	~Menu_Inicio() {
		delete inicio;
	};
	/** Dibujar el menú
	* El parámetro opción indica qué texto debe ser resaltado,
	* no se tiene en cuenta la posición del cursor aquí.
	*/
	void dibuja();
	void mouse(int button, int state, double x, double y);
};
