#include "Piezas.h"

void Pieza::ilustrar() {
	// imprimir sprite tal cual
}

void Pieza::cambiar_estilo(Estilo_grafico estilo) {
	// *elimina* y vuelve a cargar el sprite, con el nuevo tema gráfico (si es distinto del anterior)
	// y actualiza el estilo de la instancia
}

void Pieza::cargar_sprite() {
	// Carga el sprite (aquí se obtiene el path a la imagen y se añade un "new" objeto sprite al puntero)
	// Atención: revisar si había uno cargado ya
}
