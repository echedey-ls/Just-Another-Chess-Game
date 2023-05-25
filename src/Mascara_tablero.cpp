#include "Mascara_tablero.h"

void Mascara_tablero::reset() {
	for (size_t i = 0; i < LADO_MASCARA; ++i)
		for (size_t j = 0; j < LADO_MASCARA; ++j)
			disponibilidades[i][j] = sin_calcular;
}

Disponibilidad_casilla& Mascara_tablero::operator()(unsigned char x, unsigned char y) {
	if (x >= LADO_MASCARA or y >= LADO_MASCARA) throw 200;
	return disponibilidades[x][y];
}

Disponibilidad_casilla& Mascara_tablero::operator()(const Posicion& p) {
	return operator()(p.x, p.y);
}
