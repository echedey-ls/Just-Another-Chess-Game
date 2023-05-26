#include "Interfaz_Partida.h"
#include <sstream>

Interfaz_Partida::Interfaz_Partida(std::function<void()>callback_cambio_graficos/*, std::function<void()>callback_click_tablero*/) {
	btn_cambio_graficos.register_on_click(callback_cambio_graficos);
	//tablero_click.register_on_click(callback_click_tablero);
	
}

void Interfaz_Partida::dibuja() {
	btn_cambio_graficos.ilustra();
	dibujarPiezas();

//	Posicion po{ 1,2 };

	glPushMatrix();
	glTranslatef(-29.0f, 22.0f, 1.f);
	glScalef(0.02f, 0.02f, 1);
	
	/*unsigned char*text = (unsigned char*)"ULTIMOS\nMOVIMIENTOS\n";
	std::string vectorText =  std::to_string(Posicion.x) + "-> " + std::to_string(Posicion.y);
	text += vectorText;

	unsigned char* c = reinterpret_cast<unsigned char*>(const_cast<char*>(text.c_str()));
	glutStrokeString(GLUT_STROKE_ROMAN, text); */

	std::ostringstream oss;
	oss << "ULTIMOS\nMOVIMIENTOS\n\n";
	oss << convertirCoordenadasAMatriz(original.x,original.y) << " -> " << convertirCoordenadasAMatriz(5,1);
	std::string text = oss.str();

	unsigned char* c = reinterpret_cast<unsigned char*>(const_cast<char*>(text.c_str()));
	glutStrokeString(GLUT_STROKE_ROMAN, c);

	//std::string nombreCasilla = convertirCoordenadasAMatriz(x, y);
	//std::cout << "Coordenadas de matriz (" << x << ", " << y << ") = " << nombreCasilla << std::endl;

	glPopMatrix();
}

void Interfaz_Partida::mouse(int button, int state, GLdouble x, GLdouble y) {
	btn_cambio_graficos.mouse(button, state, x, y);
	//tablero_click.mouse(button, state, x, y);
}

void Interfaz_Partida::dibujarPiezas() {

	//Piezas blancas
	int xb = 95;  
	int yb = 68;
	int i = 0;
	
	for (auto pieza : piezas_blancas) {
		glPushMatrix();
		glTranslatef(xb, yb, 0);
		pieza->ilustrar();
		glPopMatrix();

		yb -= 8;
		i++;
		if (i == 10){
			xb -= 10;
			yb = 68;
		}
		
    }

	// Piezas negras
	int xn = -33;
	int yn = 68;
	int c = 0;

    for (auto pieza : piezas_negras) {
		glPushMatrix();
		glTranslatef(xn, yn, 0);
		pieza->ilustrar();
		glPopMatrix();

		yn -= 8;
		c++;
		if (c == 10) {
			xn += 10;
			yn = 68;
		}
    }
}

void Interfaz_Partida::add_pieza(Pieza* p_pza) {
	if (!p_pza) return;
	if (p_pza->get_color() == blanca) {
		piezas_blancas.push_back(p_pza);
	}
	else {
		piezas_negras.push_back(p_pza);
	}
	
}

Interfaz_Partida::~Interfaz_Partida() {
	for (auto p : piezas_blancas) {
		delete p;
	}
	for (auto p : piezas_negras) {
		delete p;
	}
}

void Interfaz_Partida::ultimos_movimientos(Posicion o, Posicion d) {
	//o: origen        d:destino
	original = o;
	destino = d;
}

/*void Interfaz_Partida::ultimos_movimientos(Posicion o) {
	//o: origen
	original = o;
}*/

/*void Interfaz_Partida::ultimos_movimientos(Posicion o) {
	original = o;
	std::ostringstream oss;
	oss << convertirCoordenadasAMatriz(original.x, original.y);
	std::cout << "Nombre de casilla: " << oss.str() << std::endl;
}*/

/*void Interfaz_Partida::ultimos_movimientoss(Posicion d) {
	//d:destino
	destino = d;
}*/