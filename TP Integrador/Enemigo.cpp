#include "Enemigo.h"

Enemigo::Enemigo() {
	srand(time(NULL));

	//Aparece un enemigo cada 2 segundos.
	tiempo = 2.0f;

	//Reiniciamos el temporizador.
	temp.restart();
}

void Enemigo::InicializarTexturas() {
	//Cargamos la textura y el sprite del enemigo.
	texEnemigo1.loadFromFile("Imagenes//Enemigo.png");

	sprEnemigo1.setTexture(texEnemigo1);

	//Ajustamos la escala del enemigo.
	sprEnemigo1.setScale(0.2f, 0.2f);

	//Obtener el tama�o de la textura del enemigo.
	Vector2u tamEnemigo = texEnemigo1.getSize();

	//Centrar el origen del enemigo.
	sprEnemigo1.setOrigin(tamEnemigo.x / 2.0f, tamEnemigo.y / 2.0f);
}

void Enemigo::DibujarEnemigos(RenderWindow& ven) {
	ven.draw(sprEnemigo1);
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
	sprEnemigo1.setPosition(posiciones[indicePos]);
}

bool Enemigo::EnemigoClick(float x, float y) const {
	//Verificar si las coordenadas (x, y) est�n dentro del sprite del enemigo.
	return sprEnemigo1.getGlobalBounds().contains(x, y);
}

void Enemigo::EliminarEnemigo() {
	//"Eliminar" enemigo, moverlo fuera de la ventana.
	sprEnemigo1.setPosition(-1000.f, -1000.f);
}

void Enemigo::Actualizar() {
	//Verifica si pas� el tiempo suficiente para una nueva aparicion.
	if (temp.getElapsedTime().asSeconds() >= tiempo) {

		//Establecemos una poisici�n al azar nuevamente.
		PosicionInicial();

		//Reiniciamos el temporizador.
		temp.restart();
	}
}