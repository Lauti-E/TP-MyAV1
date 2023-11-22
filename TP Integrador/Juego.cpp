#include "Juego.h"

Juego::Juego() : ventana(VideoMode(800, 600), "Trabajo práctico integrador.") {

	//Cargamos el fondo.
	texFondo.loadFromFile("Imagenes//Escenario.png");
	sprFondo.setTexture(texFondo);

	sprFondo.setScale(800.f / texFondo.getSize().x, 600.f / texFondo.getSize().y);

	//Inicializar la mira.
	crosshair.Inicializar();
	enemigo.InicializarTexturas();

	//Ocultar el cursor.
	ventana.setMouseCursorVisible(false);
}

void Juego::General() {
	while (ventana.isOpen()) {
		ProcesarEventos();
		Dibujar();
	}
}

void Juego::ProcesarEventos() {
	Event eventos;

	while (ventana.pollEvent(eventos)) {
		if (eventos.type == Event::Closed) {
			ventana.close();
		}
	}
}

void Juego::Dibujar() {
	ventana.clear(Color::White);

	ventana.draw(sprFondo);
	enemigo.DibujarEnemigos(ventana);
	crosshair.Dibujar(ventana);

	ventana.display();
}