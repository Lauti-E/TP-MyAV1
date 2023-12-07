#include "Juego.h"

Juego::Juego() : ventana(VideoMode(800, 600), "Trabajo práctico integrador.") {

	srand(time(NULL));

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

	temp.restart();

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

			if (inocente.InocenteClick(mousePos.x, mousePos.y)) {
				//"Eliminar" al inocente.
				inocente.EliminarInocente();

				inocente.ReiniciarReloj();
			}
		}
	}

	//Si el número aleatorio es igual a 3, intenta posicionar al inocente.
	if (temp.getElapsedTime().asSeconds() >= 4.0f) {
		//Reinicia el temporizador.
		temp.restart();

		//Genera un número aleatorio entre 0 y 4.
		int valAleatorio = rand() % 5;

		//Si el número aleatorio es igual a 3, se posiciona al inocente.
		if (valAleatorio == 3) {
			inocente.PosicionInicial();
		}
	}

	do {
		enemigo.PosicionInicial();
	} while (ColisionEnemigos(enemigo, enemigo2));

	enemigo2.PosicionInicial();
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

bool Juego::ColisionEnemigos(const Enemigo& e1, const Enemigo2& e2) const {
	return e1.GetSprite().getGlobalBounds().intersects(e2.GetSprite().getGlobalBounds());
}