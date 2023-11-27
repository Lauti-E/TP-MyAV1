#include "Enemigo.h"

Enemigo::Enemigo() {}

void Enemigo::InicializarTexturas() {
	//Cargamos la textura y el sprite del enemigo.
	texEnemigo1.loadFromFile("Imagenes//Enemigo.png");

	sprEnemigo1.setTexture(texEnemigo1);

	//Ajustamos la escala del enemigo.
	sprEnemigo1.setScale(0.3f, 0.3f);

	//Obtener el tamaño de la textura del enemigo.
	Vector2u tamEnemigo = texEnemigo1.getSize();

	//Centrar el origen del enemigo.
	sprEnemigo1.setOrigin(tamEnemigo.x / 2.0f, tamEnemigo.y / 2.0f);
}

void Enemigo::DibujarEnemigos(RenderWindow& ven) {
	ven.draw(sprEnemigo1);
}

bool Enemigo::EnemigoClick(float x, float y) const {
	//Verificar si las coordenadas (x, y) están dentro del sprite del enemigo.
	return sprEnemigo1.getGlobalBounds().contains(x, y);
}

void Enemigo::EliminarEnemigo() {
	//"Eliminar" enemigo, moverlo fuera de la ventana.
	sprEnemigo1.setPosition(-1000.f, -1000.f);
}