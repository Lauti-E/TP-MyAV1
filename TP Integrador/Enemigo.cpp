#include "Enemigo.h"

Enemigo::Enemigo() {
	srand(time(NULL));
}

void Enemigo::InicializarTexturas() {
	//Cargamos la textura y el sprite del enemigo.
	texEnemigo.loadFromFile("Imagenes//Enemigo.png");

	sprEnemigo.setTexture(texEnemigo);

	//Ajustamos la escala del enemigo.
	sprEnemigo.setScale(0.2f, 0.2f);

	//Obtener el tamaño de la textura del enemigo.
	Vector2u tamEnemigo = texEnemigo.getSize();

	//Centrar el origen del enemigo.
	sprEnemigo.setOrigin(tamEnemigo.x / 2.0f, tamEnemigo.y / 2.0f);
}

void Enemigo::DibujarEnemigos(RenderWindow& ven) {
	//Se dibujan los enemigos cada 2 segundos.
	if (temp.getElapsedTime().asSeconds() >= 2.0f) {
		PosicionInicial();
	}

	ven.draw(sprEnemigo);
}

void Enemigo::PosicionInicial() {
	//Definir 4 posiciones posibles.
	Vector2f posiciones[] = {
		{200.f, 200.f}, //Posición 1.
		{600.f, 200.f}, //Posición 2.
		{175.f, 410.f}, //Posición 3.
		{640.f, 410.f}, //Posición 4.
		{400.f, 450.f}  //Posición 5.
	};

	//Posición al azar.
	int indicePos = rand() % 5;

	//Establecer la posición del sprite del enemigo.
	sprEnemigo.setPosition(posiciones[indicePos]);

	temp.restart();
}

bool Enemigo::EnemigoClick(float x, float y) const {
	//Verificar si las coordenadas (x, y) están dentro del sprite del enemigo.
	return sprEnemigo.getGlobalBounds().contains(x, y);
}

void Enemigo::EliminarEnemigo() {
	//Reiniciar el temporizador.
	temp.restart();

	//"Eliminar" enemigo, moverlo fuera de la ventana.
	sprEnemigo.setPosition(-1000.f, -1000.f);

	if (temp.getElapsedTime().asSeconds() >= 2.0f) {
		PosicionInicial();
	}
}