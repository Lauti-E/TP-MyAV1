#include "Enemigo2.h"

Enemigo2::Enemigo2() {
	srand(time(NULL));
}

void Enemigo2::InicializarTexturas() {
	//Cargamos la textura y el sprite del enemigo.
	texEnemigo2.loadFromFile("Imagenes//Enemigo2.png");

	sprEnemigo2.setTexture(texEnemigo2);

	//Ajustamos la escala del enemigo.
	sprEnemigo2.setScale(0.2f, 0.2f);

	//Obtener el tamaño de la textura del enemigo.
	Vector2u tamEnemigo = texEnemigo2.getSize();

	//Centrar el origen del enemigo.
	sprEnemigo2.setOrigin(tamEnemigo.x / 2.0f, tamEnemigo.y / 2.0f);
}

void Enemigo2::DibujarEnemigos(RenderWindow& ven) {

	if (temp.getElapsedTime().asSeconds() >= 2.0f) {
		PosicionInicial();
	}

	ven.draw(sprEnemigo2);
}

void Enemigo2::PosicionInicial() {
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
	sprEnemigo2.setPosition(posiciones[indicePos]);

	temp.restart();
}

bool Enemigo2::EnemigoClick(float x, float y) const {
	//Verificar si las coordenadas (x, y) están dentro del sprite del enemigo.
	return sprEnemigo2.getGlobalBounds().contains(x, y);
}

void Enemigo2::EliminarEnemigo() {
	//Reiniciar el temporizador.
	temp.restart();

	//"Eliminar" enemigo, moverlo fuera de la ventana.
	sprEnemigo2.setPosition(-1000.f, -1000.f);

	if (temp.getElapsedTime().asSeconds() >= 2.0f) {
		PosicionInicial();
	}
}