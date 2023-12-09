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
	
	//Puntaje en 0.
	puntaje = 0;

	//Vidas en 3.
	vidas = 3;

	//Game Over en false.
	gameOver = false;

	//Cargar la fuente.
	if (!fuente.loadFromFile("Fuentes//Fuente.ttf")) {
		//Mensaje de error.
		cout << "Error al cargar la fuente." << endl;
	}

	ConfigTextos();

}

void Juego::General() {
	while (ventana.isOpen() && !gameOver) {
		ProcesarEventos();

		Dibujar();
	}

	while(ventana.isOpen()) {
		GameOver();

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

				//Incrementar el puntaje.
				puntaje += 2;
				ActualizarPuntaje();
			}

			if (enemigo2.EnemigoClick(mousePos.x, mousePos.y)) {
				//"Eliminar" el enemigo.
				enemigo2.EliminarEnemigo();

				enemigo2.ReiniciarReloj();
				
				//Incrementar el puntaje.
				puntaje += 2;
				ActualizarPuntaje();
			}

			if (inocente.InocenteClick(mousePos.x, mousePos.y)) {
				//"Eliminar" al inocente.
				inocente.EliminarInocente();

				inocente.ReiniciarReloj();

				//Disminuir el puntaje.
				puntaje -= 20;
				ActualizarPuntaje();

				vidas--;
				ActualizarVidas();

				if (vidas == 0) {
					vidas = 0;
					gameOver = true;
				}
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

	ventana.draw(textoPuntaje); //Dibujar el puntaje.
	ventana.draw(textoVidas); //Dibujar las vidas.

	enemigo.DibujarEnemigos(ventana); //Dibujar el enemigo 1.
	enemigo2.DibujarEnemigos(ventana); //Dibujar el enemigo 2.

	inocente.DibujarInocente(ventana); //Dibujar el inocente.

	crosshair.Dibujar(ventana); //Dibujar el crosshair.

	if (gameOver) {
		textoGameOver.setFont(fuente);
		textoGameOver.setCharacterSize(48);
		textoGameOver.setFillColor(Color::Red);
		textoGameOver.setPosition(400.f, 300.f);
		textoGameOver.setString("Game Over");
		
		ventana.draw(textoGameOver);
	}

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

void Juego::ConfigTextos() {
	
	//Configuramos la fuente para el puntaje.
	textoPuntaje.setFont(fuente);
	textoPuntaje.setCharacterSize(24);
	textoPuntaje.setFillColor(Color::Black);
	textoPuntaje.setPosition(25.f, 25.f);
	textoPuntaje.setString("Puntaje: " + to_string(puntaje));

	//Configuramos la fuente para las vidas.
	textoVidas.setFont(fuente);
	textoVidas.setCharacterSize(24);
	textoVidas.setFillColor(Color::Black);
	textoVidas.setPosition(675.f, 25.f);
	textoVidas.setString("Vidas: " + to_string(vidas));
}

void Juego::ActualizarPuntaje() {
	textoPuntaje.setString("Puntaje: " + to_string(puntaje)); //Pasamos a string el puntaje.
}

void Juego::ActualizarVidas() {
	textoVidas.setString("Vidas: " + to_string(vidas)); //Pasamos a string las vidas.
}

void Juego::GameOver() {
	Event evento;

	while (ventana.pollEvent(evento)) {
		if (evento.type == Event::Closed || evento.type == Event::MouseButtonPressed) {
			ventana.close();
		}
	}
}