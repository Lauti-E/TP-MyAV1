#include "Juego.h"

Juego::Juego() : ventana(VideoMode(800, 600), "Trabajo práctico integrador.") {

	//Cargamos el fondo.
	texFondo.loadFromFile("Imagenes//Escenario.png");
	sprFondo.setTexture(texFondo);

	sprFondo.setScale(800.f / texFondo.getSize().x, 600.f / texFondo.getSize().y);

	//Inicializar la mira.
	crosshair.Inicializar();

	//Inicializar el enemigo y su posición.
	enemigo.InicializarTexturas();
	enemigo.PosicionInicial();

	//Ocultar el cursor.
	ventana.setMouseCursorVisible(false);
}

void Juego::General() {
	while (ventana.isOpen()) {
		ProcesarEventos();

		enemigo.Actualizar();

		Dibujar();
	}
}

void Juego::ProcesarEventos() {
	Event eventos;

	while (ventana.pollEvent(eventos)) {
		if (eventos.type == Event::Closed) {
			ventana.close();
		}

		if (Mouse::isButtonPressed(Mouse::Left)) {
			
			//Obtener la posición del mouse.
			Vector2i mousePos = Mouse::getPosition(ventana);

			//Verificar si el clic fue dentro del sprite del enemigo.
			if (enemigo.EnemigoClick(mousePos.x, mousePos.y)) {
				
				//"Eliminar" el enemigo.
				enemigo.EliminarEnemigo();
			}
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