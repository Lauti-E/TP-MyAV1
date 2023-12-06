#include "Juego.h"

Juego::Juego() : ventana(VideoMode(800, 600), "Trabajo práctico integrador.") {

	//Cargamos el fondo.
	texFondo.loadFromFile("Imagenes//Escenario.png");
	sprFondo.setTexture(texFondo);

	sprFondo.setScale(800.f / texFondo.getSize().x, 600.f / texFondo.getSize().y);

	//Inicializar la mira.
	crosshair.Inicializar();

	enemigo.InicializarTexturas();
	enemigo.PosicionInicial();

	enemigo2.InicializarTexturas();
	enemigo2.PosicionInicial();

	inocente.InicializarTexturas();
	inocente.PosicionInicial();

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

		if (Mouse::isButtonPressed(Mouse::Left)) {
			
			//Obtener la posición del mouse.
			Vector2i mousePos = Mouse::getPosition(ventana);

			//Verificar si el clic fue dentro del sprite del enemigo.
			if (enemigo.EnemigoClick(mousePos.x, mousePos.y)) {
				
				//"Eliminar" el enemigo.
				enemigo.EliminarEnemigo();

				enemigo.ReiniciarReloj();
			}

			if (enemigo2.EnemigoClick(mousePos.x, mousePos.y)) {

				//"Eliminar" el enemigo.
				enemigo2.EliminarEnemigo();

				enemigo2.ReiniciarReloj();
			}

			//Verificar si el clic fue dentro del sprite del inocente.
			if (inocente.InocenteClick(mousePos.x, mousePos.y)) {
				//"Eliminar" el inocente.
				inocente.EliminarInocente();
				
				inocente.ReiniciarReloj();
			}
		}
	}
}

void Juego::Dibujar() {
	ventana.clear(Color::White);

	ventana.draw(sprFondo);

	enemigo.DibujarEnemigos(ventana);
	enemigo2.DibujarEnemigos(ventana);
	inocente.DibujarInocente(ventana);

	crosshair.Dibujar(ventana);

	ventana.display();
}