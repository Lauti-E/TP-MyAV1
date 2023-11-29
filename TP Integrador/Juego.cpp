#include "Juego.h"

Juego::Juego() : ventana(VideoMode(800, 600), "Trabajo práctico integrador.") {

	//Cargamos el fondo.
	texFondo.loadFromFile("Imagenes//Escenario.png");
	sprFondo.setTexture(texFondo);

	sprFondo.setScale(800.f / texFondo.getSize().x, 600.f / texFondo.getSize().y);

	//Inicializar la mira.
	crosshair.Inicializar();

	//Ocultar el cursor.
	ventana.setMouseCursorVisible(false);
}

void Juego::General() {
	while (ventana.isOpen()) {
		ProcesarEventos();

		EnemigoAleatorio();

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
			if (enemigo->EnemigoClick(mousePos.x, mousePos.y)) {
				
				//"Eliminar" el enemigo.
				enemigo->EliminarEnemigo();
			}
		}
	}
}

void Juego::Dibujar() {
	ventana.clear(Color::White);

	ventana.draw(sprFondo);

	enemigo->DibujarEnemigos(ventana);

	crosshair.Dibujar(ventana);

	ventana.display();
}

void Juego::EnemigoAleatorio() {
	//Generar un número aleatorio (0 o 1).
	int tipEnemigo = rand() % 2;

	if (tipEnemigo == 0) {
		delete enemigo; //Liberar memoria.
		enemigo = new EnemigoTipo1();
	}
	else {
		delete enemigo; //Liberar memoria.
		enemigo = new EnemigoTipo2();
	}

	//Inicializar el enemigo creado.
	enemigo->InicializarTexturas();
	enemigo->PosicionInicial();
	enemigo->Actualizar();
}