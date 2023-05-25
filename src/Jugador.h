#pragma once
class Jugador
{
	int color;
	bool es_mi_turno;
	int piezas_comidas;
public:
	Jugador();
	void set_color(int c) {
		color = c;
	}
	int get_color() { return color; }
	void incremento_pzas_comidas() {
		piezas_comidas++;
	}
	void cambiar_turno();
	int get_pzas_comidas(){ return piezas_comidas; }

};

