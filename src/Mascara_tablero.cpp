#include "Mascara_tablero.h"

void Mascara_tablero::reset()
{
	for (auto& disp_v : disponibilidades)
		for(auto& disp : disp_v)
			disp = sin_calcular;
	/** Es equivalente, pero más bonito lo anterior. Sin embargo, no hay índices.
	for (size_t i = 0; i < LADO_MASCARA; ++i)
		for (size_t j = 0; j < LADO_MASCARA; ++j)
			disponibilidades[i][j] = sin_calcular;
	*/
}

Disponibilidad_casilla& Mascara_tablero::operator()(unsigned char x, unsigned char y) {
	return disponibilidades[x][y];
}

Disponibilidad_casilla& Mascara_tablero::operator()(const Posicion& p) {
	return operator()(p.x, p.y);
}
