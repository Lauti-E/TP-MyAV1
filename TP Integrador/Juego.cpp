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

		cout << "El numero es: " << valAleatorio << endl;

		//Si el número aleatorio es igual a 3, se posiciona al inocente.
		if (valAleatorio == 0 || valAleatorio == 2 || valAleatorio == 4) {
			inocente.PosicionInicial();
		}
	}

	//Verificar colisión entre los dos enemigos.
	if (ColisionEnemigos(enemigo, enemigo2)) {
		enemigo.PosicionInicial();
	}

	//Verificar colisión entre el inocente y los enemigos.
	if (ColisionInocenteEnemigo(inocente, enemigo) || ColisionInocenteEnemigo2(inocente, enemigo2)) {
		inocente.PosicionInicial();

		enemigo.PosicionInicial();
		enemigo2.PosicionInicial();
	}
}

void Juego::Dibujar() {
	ventana.clear(Color::White);

	ventana.draw(sprFondo); //Dibujar el fondo.

	enemigo.DibujarEnemigos(ventana); //Dibujar el enemigo 1.
	enemigo2.DibujarEnemigos(ventana); //Dibujar el enemigo 2.

	inocente.DibujarInocente(ventana); //Dibujar el inocente.

	crosshair.Dibujar(ventana); //Dibujar el crosshair.

	ventana.display();
}

bool Juego::ColisionEnemigos(const Enemigo& e1, const Enemigo2& e2) const {
	//Detectar si los enemigos intersectan entre sí para no posicionarlos.
	return e1.GetSprite().getGlobalBounds().intersects(e2.GetSprite().getGlobalBounds());
}

bool Juego::ColisionInocenteEnemigo(const Inocente& in, const Enemigo& e1) const {
	return inocente.GetSprite().getGlobalBounds().intersects(enemigo.GetSprite().getGlobalBounds());
}

bool Juego::ColisionInocenteEnemigo2(const Inocente& in, const Enemigo2& e2) const {
	return inocente.GetSprite().getGlobalBounds().intersects(enemigo2.GetSprite().getGlobalBounds());
}