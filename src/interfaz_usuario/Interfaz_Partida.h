#pragma once

#include "BotonUI.h"
#include "../Piezas.h"

#include "freeglut.h"

#include <functional>
#include <vector>
#include <sstream>
#include <iostream>
#include "../Casilla.h"

class Interfaz_Partida {
	BotonUI btn_cambio_graficos{ (unsigned char*)"USE\nTHE\nFORCE",
		69.f, 10.f, 0.02f, 68.5f, 2.7f, 79.5f, 13.f};
	//BotonUI tablero_click{ 0.0f,0.0f,64.0f,64.0f };

	//vector piezas eliminadas
	std::vector<Pieza*> piezas_blancas;
	std::vector<Pieza*> piezas_negras;

	Posicion original{ 0,0 }, destino{0,0};

public:
	Interfaz_Partida(std::function<void()>callback_cambio_graficos/*, std::function<void()>callback_click_tablero*/);
	Interfaz_Partida() {}
	~Interfaz_Partida();
	void dibuja();
	void mouse(int button, int state, GLdouble x, GLdouble y);
	void dibujarPiezas();
	void add_pieza(Pieza* p_pieza);

	//es como get_posicion, obtiene el valor del dominio privado
	void ultimos_movimientos(Posicion orgn, Posicion dest);
	//void ultimos_movimientos(Posicion);
	//void ultimos_movimientoss(Posicion);

	//
	/*void ultimos_movimientos_origen(Posicion o) {
		original = o;
		/*std::ostringstream oss;
		oss << convertirCoordenadasAMatriz(o.x, o.y);
		std::cout << "Nombre de casilla: " << oss.str() << std::endl;
	}*/

	//Realiza la conversión de la posición (x,y) a casilla(letra, numero)
	

	std::string convertirCoordenadasAMatriz(int x, int y) {

		//ultimos_movimientos(a); //a son las cogidas con el tablero
		//ultimos_movimientos(b);

		//a.x     a.y

		std::ostringstream nombreCasilla;
		char columna = 'A' + x; 
		int fila = y + 1;
		nombreCasilla << columna << fila;
		return nombreCasilla.str();
	}
};

