#include "Enemigo.h"

Enemigo::Enemigo() {}

void Enemigo::InicializarTexturas() {
	//Cargamos la textura y el sprite del enemigo.
	texEnemigo1.loadFromFile("Imagenes//Enemigo.png");

	sprEnemigo1.setTexture(texEnemigo1);

	//Ajustamos la escala del enemigo.
	sprEnemigo1.setScale(0.3f, 0.3f);

	//Obtener el tama�o de la textura del enemigo.
	Vector2u tamEnemigo = texEnemigo1.getSize();

	//Centrar el origen del enemigo.
	sprEnemigo1.setOrigin(tamEnemigo.x / 2.0f, tamEnemigo.y / 2.0f);
}

void Enemigo::DibujarEnemigos(RenderWindow& ven) {
	ven.draw(sprEnemigo1);
}