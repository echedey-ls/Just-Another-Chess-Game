#pragma once

#include "Posicion.h"
#include "Estilos_graficos.h"

#include "ETSIDI.h"

// Par de enumeraciones con los valores que pueden tomar las piezas
enum Color {
	blanca,
	negra
};

enum Tipo { desconocido, rey, reina, alfil, torre, caballo, peon };

class Pieza {
protected:
	Color color;
	Tipo tipo = desconocido; // Es redundante si se crean clases especializadas, pero lo usamos en esta para cargar gráficos homogéneamente
	Estilo_grafico estilo_actual;

	ETSIDI::Sprite* sprite_ptr = nullptr;


public:
	Pieza(Color c, Estilo_grafico s) : color{ c }, estilo_actual{ s } {};
	Pieza(const Pieza& other) : color{ other.color }, estilo_actual{ other.estilo_actual } {};
	~Pieza() { delete sprite_ptr; };

	/** No hay forma de cambiar el archivo que representa un sprite, así que para
	* cambiarlo, habrá que eliminarlo y crearlo de nuevo.
	*/
	void cambiar_estilo(Estilo_grafico estilo);
	/** Usa tipo, color y estilo_actual para cargar la imagen correspondiente
	*/
	void cargar_sprite();

	Color get_color() const { return color; };
	Tipo get_tipo() const { return tipo; };
	void ilustrar(Posicion p); // En función del tipo, color y estilo_actual




};
