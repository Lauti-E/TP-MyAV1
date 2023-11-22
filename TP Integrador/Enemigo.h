#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemigo {
private:
	Texture texEnemigo1;
	Sprite sprEnemigo1;

public:
	//Constructor.
	Enemigo();

	//M�todo para inicializar las texturas.
	void InicializarTexturas();

	//M�todo para dibujar los enemigos en la ventana.
	void DibujarEnemigos(RenderWindow& ven);
};

