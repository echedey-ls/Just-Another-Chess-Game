#include "Piezas.h"
#include "ETSIDI.h"
#include"piezas/Peon.h"

using namespace ETSIDI;

void Pieza::ilustrar(Posicion p) {
	// imprimir sprite tal cual
	sprite_ptr->setPos(4 + (8 * p.x), 4 + (8 * p.y));
	sprite_ptr->draw();
}

void Pieza::cambiar_estilo(Estilo_grafico estilo) {
	// *elimina* y vuelve a cargar el sprite, con el nuevo tema gráfico (si es distinto del anterior)
	// y actualiza el estilo de la instancia
}

void Pieza::cargar_sprite() {
	// Carga el sprite (aquí se obtiene el path a la imagen y se añade un "new" objeto sprite al puntero)
	// Atención: revisar si había uno cargado ya


	//NO SE COMO BORRAR EL SPRITE
	//NO PILLA EL COLOR??



	if (sprite_ptr != nullptr) {
		delete sprite_ptr; //BORRAR SPRITE ANTERIOR  ---> NO ES MEJOR CREAR UN SPRITE PARA CADA PIEZA???
	}													// sino al ilustrar a lo mejor se borra la ilustracion anterior(?)	
	else
	{
		if (estilo_actual == clasico) {
			if (Color(0)) {
				switch (tipo) {
				case 1:
					sprite_ptr = new Sprite("imagenes/c_rey_b.png", 0, 0, 8, 8);  //REY BLANCO
					break;
				case 2:
					sprite_ptr = new Sprite("imagenes/c_reina_b.png", 0, 0, 8, 8);  //REINA BLANCA
					break;
				case 3:
					sprite_ptr = new Sprite("imagenes/c_alfil_b.png", 0, 0, 8, 8);  //ALFIL BLANCO
					break;
				case 4:
					sprite_ptr = new Sprite("imagenes/c_torre_b.png", 0, 0, 8, 8); //TORRE BLANCO
					break;
				case 5:
					sprite_ptr = new Sprite("imagenes/c_caballo_b.png", 0, 0, 8, 8);  //CABALLO BLANCO
					break;
				case 6:
					sprite_ptr = new Sprite("imagenes/c_peon_b.png", 0, 0, 8, 8);  //PEON BLANCO
					break;
				default:
					sprite_ptr = nullptr;
					break;
				}
			}
			if (Color(1)) {
				switch (tipo) {
				case 1:
					sprite_ptr = new Sprite("imagenes/c_rey_n.png", 0, 0, 8, 8);  //REY NEGRO
					break;
				case 2:
					sprite_ptr = new Sprite("imagenes /c_reina_n.png", 0, 0, 8, 8);  //REINA NEGRA
					break;
				case 3:
					sprite_ptr = new Sprite("imagenes/c_alfil_n.png", 0, 0, 8, 8);  //ALFIL NEGRO
					break;
				case 4:
					sprite_ptr = new Sprite("imagenes/c_torre_n.png", 0, 0, 8, 8); //TORRE NEGRO
					break;
				case 5:
					sprite_ptr = new Sprite("imagenes/c_caballo_n.png", 0, 0, 8, 8);  //CABALLO NEGRO
					break;
				case 6:
					sprite_ptr = new Sprite("imagenes/c_peon_n.png", 0, 0, 8, 8);  //PEON NEGRO
					break;
				default:
					sprite_ptr = nullptr;
					break;
				}
			}
		}
		if (estilo_actual == stars_wars) {
			if (Color(0)) {
				switch (tipo) {
				case 1:
					sprite_ptr = new Sprite("imagenes/sw_rey_b.png", 0, 0, 8, 8);  //REY BLANCO
					break;
				case 2:
					sprite_ptr = new Sprite("imagenes/sw_reina_b.png", 0, 0, 8, 8);  //REINA BLANCA
					break;
				case 3:
					sprite_ptr = new Sprite("imagenes/sw_alfil_b.png", 0, 0, 8, 8);  //ALFIL BLANCO
					break;
				case 4:
					sprite_ptr = new Sprite("imagenes/sw_torre_b.png", 0, 0, 8, 8); //TORRE BLANCO
					break;
				case 5:
					sprite_ptr = new Sprite("imagenes/sw_caballo_b.png", 0, 0, 8, 8);  //CABALLO BLANCO
					break;
				case 6:
					sprite_ptr = new Sprite("imagenes/sw_peon_b.png", 0, 0, 8, 8);  //PEON BLANCO
					break;
				default:
					sprite_ptr = nullptr;
					break;
				}
			}
			if (Color (1)) {
				switch (tipo) {
				case 1:
					sprite_ptr = new Sprite("imagenes/sw_rey_n.png", 0, 0, 8, 8);  //REY NEGRO
					break;
				case 2:
					sprite_ptr = new Sprite("imagenes / sw_reina_n.png", 0, 0, 8, 8);  //REINA NEGRA
					break;
				case 3:
					sprite_ptr = new Sprite("imagenes/sw_alfil_n.png", 0, 0, 8, 8);  //ALFIL NEGRO
					break;
				case 4:
					sprite_ptr = new Sprite("imagenes/sw_torre_n.png", 0, 0, 8, 8); //TORRE NEGRO
					break;
				case 5:
					sprite_ptr = new Sprite("imagenes/sw_caballo_n.png", 0, 0, 8, 8);  //CABALLO NEGRO
					break;
				case 6:
					sprite_ptr = new Sprite("imagenes/sw_peon_n.png", 0, 0, 8, 8);  //PEON NEGRO
					break;
				default:
					sprite_ptr = nullptr;
					break;
				}
			}
		}
	}

}
