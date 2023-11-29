#include "EnemigoTipo2.h"

EnemigoTipo2::EnemigoTipo2() {
	srand(time(NULL));

	//Aparece un enemigo cada 2 segundos.
	tiempo = 2.0f;

	//Reiniciamos el temporizador.
	temp.restart();
}

void EnemigoTipo2::InicializarTexturas() {
	//Cargamos la textura y el sprite del enemigo.
	texEnemigo.loadFromFile("Imagenes//Enemigo2.png");

	sprEnemigo.setTexture(texEnemigo);

	//Ajustamos la escala del enemigo.
	sprEnemigo.setScale(0.2f, 0.2f);

	//Obtener el tama�o de la textura del enemigo.
	Vector2u tamEnemigo = texEnemigo.getSize();

	//Centrar el origen del enemigo.
	sprEnemigo.setOrigin(tamEnemigo.x / 2.0f, tamEnemigo.y / 2.0f);
}

void EnemigoTipo2::DibujarEnemigos(RenderWindow& ven) {
	ven.draw(sprEnemigo);
}

void EnemigoTipo2::PosicionInicial() {
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
}

bool EnemigoTipo2::EnemigoClick(float x, float y) const {
	//Verificar si las coordenadas (x, y) est�n dentro del sprite del enemigo.
	return sprEnemigo.getGlobalBounds().contains(x, y);
}

void EnemigoTipo2::EliminarEnemigo() {
	//"Eliminar" enemigo, moverlo fuera de la ventana.
	sprEnemigo.setPosition(-1000.f, -1000.f);
}

void EnemigoTipo2::Actualizar() {
	//Verifica si pas� el tiempo suficiente para una nueva aparicion.
	if (temp.getElapsedTime().asSeconds() >= tiempo) {

		//Establecemos una poisici�n al azar nuevamente.
		PosicionInicial();

		//Reiniciamos el temporizador.
		temp.restart();
	}
}