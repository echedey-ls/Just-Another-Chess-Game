#pragma once

#include "Estilos_graficos.h"
#include "Casilla.h"
#include "Mascara_tablero.h"

#include <functional>
#include "ETSIDI.h"
using namespace ETSIDI;

class Tablero
{
	Casilla casillas[8][8]; // se acceden como casillas[Y][X]
	Estilo_grafico estilo;

	// Utilidades para acceder a las casillas legiblemente (X, Y) o (Posicion)
	Casilla& casilla(char x, char y) { return casillas[y][x]; }
	Casilla& casilla(const Posicion& p) { return casilla(p.x, p.y); }

	//Cuando no está clickeada, se guarda la posición 
	//Se crea una variable de tipo situacion
	enum Situacion {NINGUNA_CLICKEADA, PRIMERA_CLICKEADA} situacion; 
	enum Evento {PRIMER_CLICK} evento;
	
	Posicion primer_clickeada{ 0,0 };


public:
	Tablero(); // Inicializa tablero con sus piezas distribuidas en un juego normal
	~Tablero(); // Borra toda la memoria reservada

	void inicializa();
	// Funciones gráficas
	void dibuja();
	Estilo_grafico siguiente_estilo();
	void actualizar_estilo_piezas();

	Sprite tablero{ "imagenes/tablero.png",0,0,64,64 };//, 0.05, 0.05, 38, 38 

	/* Necesario para acceder a las piezas del tablero
	* y computar movimientos posibles
	*/
	static bool es_posicion_valida(const Posicion& p) { return !(p.x < 0 or p.x > 7 or p.y < 0 or p.y > 7); };
	Pieza* obtener_pieza_en(const Posicion& p);
	void mover_pieza(const Posicion& origen, const Posicion& destino);
	Pieza* quitar_pieza(const Posicion& casilla);

	// Lo que realmente calcula los movimientos
	void calculadora_movimientos(const Posicion& p, Mascara_tablero& resultado);

	//void ilumina(); 
	//quiero que se ilumine al hacer click sobre la casilla

	//Para gestionar clicks en el tablero a través del mouse
	void mouse(int button, int state, GLdouble x, GLdouble y);
	
	//Gestión de clicks en función de la Posición que estás
	void clicks(Posicion);
};


