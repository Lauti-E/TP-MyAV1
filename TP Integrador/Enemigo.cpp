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

	//Obtener el tama�o de la textura del enemigo.
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
		{200.f, 200.f}, //Posici�n 1.
		{600.f, 200.f}, //Posici�n 2.
		{175.f, 410.f}, //Posici�n 3.
		{640.f, 410.f}, //Posici�n 4.
		{400.f, 450.f}  //Posici�n 5.
	};

	//Posici�n al azar.
	int indicePos = rand() % 5;

	//Establecer la posici�n del sprite del enemigo.
	sprEnemigo.setPosition(posiciones[indicePos]);

	temp.restart();
}

bool Enemigo::EnemigoClick(float x, float y) const {
	//Verificar si las coordenadas (x, y) est�n dentro del sprite del enemigo.
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